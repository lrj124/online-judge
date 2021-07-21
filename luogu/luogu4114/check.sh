#!/bin/bash
while true; do
./gen
./luogu4114
./std
if diff luogu4114.out std.out; then
echo AC
else
echo WA
exit 0
fi
done
