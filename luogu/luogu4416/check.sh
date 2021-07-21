#!/bin/bash
while true; do
./gen
./luogu4416
./std
if diff luogu4416.out std.out; then
echo AC
else
echo WA
exit 0
fi
done
