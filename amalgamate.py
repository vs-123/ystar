import re
import os

def amalgamate(filename):
    output = []
    with open(filename, 'r') as f:
        for line in f:
            match = re.match(r'^\s*#include\s+"([^"]+)"', line)
            if match:
                path = match.group(1)
                if os.path.exists(path):
                    output.append(f"/* ~=~ START {path} ~=~ */\n")
                    output.append(amalgamate(path))
                    output.append(f"/* ~=~ END {path} ~=~ */\n")
                else:
                    output.append(line)
            else:
                output.append(line)
    return "".join(output)

if not os.path.exists("dist"):
    os.makedirs("dist")
    
amalgamated = amalgamate("amalgamate_template.h")
with open("dist/ystar.h", "w") as f:
    f.write(amalgamated)

print("[DONE] 'ystar.h' DISTRIBUTABLE HEADER GENERATED")

