import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


SCRIPT = Path(__file__).with_name("sync_header.py")


class SyncHeaderTests(unittest.TestCase):
    def run_script(self, source):
        return subprocess.run([sys.executable, str(SCRIPT), str(source)], capture_output=True, text=True)

    def test_creates_header_for_new_cpp(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "Example.cpp"
            source.write_text('''#include "Example.h"\nconst uint8_t led = 8;\nvoid blink(int times) {\n  while (times--) {}\n}\n''')
            result = self.run_script(source)
            self.assertEqual(result.returncode, 0, result.stderr)
            header = source.with_suffix(".h").read_text()
            self.assertIn("extern const uint8_t led;", header)
            self.assertIn("void blink(int times);", header)

    def test_updates_generated_section_and_preserves_manual_content(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "Example.cpp"
            source.write_text('const unsigned int tone = 440;\nunsigned int mode = 0;\n')
            header = source.with_suffix(".h")
            header.write_text("#pragma once\nstruct Data {};\n// BEGIN GENERATED DECLARATIONS\nold\n// END GENERATED DECLARATIONS\n")
            result = self.run_script(source)
            self.assertEqual(result.returncode, 0, result.stderr)
            content = header.read_text()
            self.assertIn("struct Data {};", content)
            self.assertIn("extern const unsigned int tone;", content)
            self.assertIn("extern unsigned int mode;", content)
            self.assertNotIn("old", content)

    def test_refuses_existing_unmarked_header(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "Example.cpp"
            source.write_text('const int value = 1;\n')
            header = source.with_suffix(".h")
            header.write_text("#pragma once\nmanual\n")
            result = self.run_script(source)
            self.assertNotEqual(result.returncode, 0)
            self.assertEqual(header.read_text(), "#pragma once\nmanual\n")

    def test_fills_empty_header_for_multiline_function(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "SetupPins.cpp"
            source.write_text('''#include "SetupPins.h"\nvoid setupPins()\n{\n  int count = 4;\n}\n''')
            header = source.with_suffix(".h")
            header.write_text("")
            result = self.run_script(source)
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("void setupPins();", header.read_text())

    def test_moves_enum_to_header_and_keeps_it_on_next_run(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "Config.cpp"
            source.write_text('''#include "Config.h"\nenum class Result{\n    none,\n    succes,\n    failed\n};\n''')
            first = self.run_script(source)
            self.assertEqual(first.returncode, 0, first.stderr)
            header = source.with_suffix(".h")
            self.assertIn("enum class Result{", header.read_text())
            self.assertIn("failed", header.read_text())
            self.assertNotIn("enum class Result{", source.read_text())
            second = self.run_script(source)
            self.assertEqual(second.returncode, 0, second.stderr)
            self.assertIn("enum class Result{", header.read_text())

    def test_pointer_return_and_size_t_in_new_header(self):
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "Pointers.cpp"
            source.write_text('''uint8_t *findItem(size_t count, uint8_t *items)\n{\n    return items;\n}\n''')
            result = self.run_script(source)
            self.assertEqual(result.returncode, 0, result.stderr)
            header = source.with_suffix(".h").read_text()
            self.assertIn("#include <stddef.h>", header)
            self.assertIn("uint8_t *findItem(size_t count, uint8_t *items);", header)


if __name__ == "__main__":
    unittest.main()
