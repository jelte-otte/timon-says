#!/usr/bin/env python3
"""Generate public declarations from simple top-level C++ definitions."""

import re
import sys
from pathlib import Path

BEGIN = "// BEGIN GENERATED DECLARATIONS"
END = "// END GENERATED DECLARATIONS"

GLOBAL = re.compile(r"^\s*(?!static\b|constexpr\b)([\w:<>\s*&]+?)\s+(\w+)(\[\s*\])?\s*=")
FUNCTION = re.compile(r"^\s*([\w:<>\s*&~]+?)\s+(\w+)\s*\(([^;{}]*)\)\s*\{")
FUNCTION_SIGNATURE = re.compile(r"^\s*([\w:<>\s*&~]+?)\s+(\w+)\s*\(([^;{}]*)\)\s*$")


def declarations(source):
    found = []
    depth = 0
    lines = source.splitlines()
    for index, line in enumerate(lines):
        code = line.split("//", 1)[0]
        if depth == 0:
            global_match = GLOBAL.match(code)
            function_match = FUNCTION.match(code)
            if not function_match and index + 1 < len(lines) and lines[index + 1].strip().startswith("{"):
                function_match = FUNCTION_SIGNATURE.match(code)
            if global_match:
                type_name, name, array = global_match.groups()
                found.append(f"extern {type_name.strip()} {name}{'[]' if array else ''};")
            elif function_match:
                return_type, name, arguments = function_match.groups()
                found.append(f"{return_type.strip()} {name}({arguments.strip()});")
        depth += code.count("{") - code.count("}")
        if depth < 0:
            raise ValueError("Unbalanced braces in source")
    if depth != 0:
        raise ValueError("Unbalanced braces in source")
    return found


def sync(source_path):
    if source_path.suffix != ".cpp" or not source_path.is_file():
        raise ValueError("Select an existing .cpp file")
    header_path = source_path.with_suffix(".h")
    generated = "\n".join(declarations(source_path.read_text()))
    section = f"{BEGIN}\n{generated}\n{END}"

    if header_path.exists() and header_path.read_text().strip():
        content = header_path.read_text()
        if content.count(BEGIN) != 1 or content.count(END) != 1:
            raise ValueError(f"{header_path} has no generated section; add the BEGIN/END markers first")
        start = content.index(BEGIN)
        stop = content.index(END, start) + len(END)
        updated = content[:start] + section + content[stop:]
    else:
        updated = f"#pragma once\n#include <stdint.h>\n\n{section}\n"

    if not header_path.exists() or header_path.read_text() != updated:
        header_path.write_text(updated)
    print(f"Updated {header_path}")


if __name__ == "__main__":
    try:
        if len(sys.argv) != 2:
            raise ValueError("Usage: sync_header.py path/to/File.cpp")
        sync(Path(sys.argv[1]).resolve())
    except (OSError, ValueError) as error:
        print(error, file=sys.stderr)
        sys.exit(1)
