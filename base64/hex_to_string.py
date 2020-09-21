#!/usr/bin/env python3

from sys import argv

if len(argv) < 2:
    print("nope...")
    exit(1)

hexstr = argv[1]

out_string = ""

for i in range(0, len(hexstr), 2):
    c = int(hexstr[i:i+2], 16)
    out_string += chr(c)

print(out_string)
