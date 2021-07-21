for i in $(seq 1 1000);do
	./gen
	./std
	./luogu6378
	if diff luogu6378.out std.out;then
		echo $i 'AC'
	else 
		echo $i 'WA'
		exit 0
	fi
done
