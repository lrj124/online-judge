#!/bin/bash
while true; do
	./gen
	./luogu2331
	./std
	if diff luogu2331.out std.out; then
		echo Accepted -- well done~
	else
		echo Wrong Answer -- oops~
		exit 0
fi
done
