import re
import os

IGNORE_INCLUDES = ["ystar.h", "include/ystar.h"]

def amalgamate(filename, strip_guards=False):
    output = []
    if not os.path.exists(filename):
        return f"/* File not found: {filename} */\n"

    with open(filename, 'r') as f:
        for line in f:
            match = re.match(r'^\s*#include\s+"([^"]+)"', line)
            if match:
                path = match.group(1)
                
                if any(path.endswith(h) for h in IGNORE_INCLUDES):
                    continue

                base_dir = os.path.dirname(filename)
                full_path = os.path.join(base_dir, path)
                output.append(f"/* ~=~ START {path} ~=~ */\n")
                output.append(amalgamate(full_path, strip_guards=True))
                output.append(f"/* ~=~ END {path} ~=~ */\n")
                continue

            if strip_guards:
                if re.match(r'^\s*#ifndef\s+\w+_H', line) or \
                   re.match(r'^\s*#define\s+\w+_H', line) or \
                   re.match(r'^\s*#endif\s+/\*\s*\w+_H\s*\*/', line) or \
                   re.match(r'^\s*#endif\s+//\s*\w+_H', line):
                    continue

            output.append(line)
            
    return "".join(output)

if not os.path.exists("dist"):
    os.makedirs("dist")

final_header = [
    f"/* AMALGAMATED ystar.h -- {os.times().elapsed} */\n",
    
    "#ifndef YSTAR_H\n",
    "#define YSTAR_H\n\n",
    "/* ~=~=~=~=~=~= */\n",
    "/* || HEADER || */\n",
    "/* ~=~=~=~=~=~= */\n",
    
    amalgamate("include/ystar.h", strip_guards=True),
    "\n#endif /* YSTAR_H */\n\n",
    
    "#ifdef YSTAR_IMPLEMENTATION\n",
    "/* ~=~=~=~=~=~=~=~=~=~= */\n",
    "/* || IMPLEMENTATION || */\n",
    "/* ~=~=~=~=~=~=~=~=~=~= */\n",
    
    amalgamate("src/ystar.c", strip_guards=False),
    "#endif /* YSTAR_IMPLEMENTATION */\n"
]

with open("dist/ystar.h", "w") as f:
    f.write("".join(final_header))

print("[DONE] ystar.h GENERATED IN DIST/")
