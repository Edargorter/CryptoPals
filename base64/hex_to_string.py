#!/usr/bin/env python3

from sys import argv

if len(argv) < 2:
    print("nope...")
    exit(1)

hexstr = argv[1]

if len(hexstr) & 1:
    print("Input must be of even length.")
    exit(1)

out_string = ""

for i in range(0, len(hexstr), 2):
    c = int(hexstr[i:i+2], 16)
    out_string += chr(c)

print("Chars: \"%s\"" % out_string)

#Or, in hex bytes 
out_string = ""
for i in range(0, len(hexstr), 2):
    out_string += "\\x" + hexstr[i:i+2]

print("Hex: %s" % out_string)
