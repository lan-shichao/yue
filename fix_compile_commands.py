import os
import json
R"""
当command为 ninja -t msvc -e environment.x64 -- \"<cmd>\" 开头时,
clangd无法正确识别编译命令, 需要将 <cmd> 提取出来 然后替换为command
"""
with open('compile_commands.json') as f:
    data = json.load(f)
STR_CMD = "ninja -t msvc -e environment.x64 -- "

for item in data:
    if item['command'].startswith(STR_CMD):
        item['command'] = item['command'][len(STR_CMD):]

with open('compile_commands.json', 'w') as f:
    json.dump(data, f, indent=4)

