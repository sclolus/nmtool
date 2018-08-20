#!/bin/bash
make
for file in `ls -1 "$DIR_TARGET"`;
do
	echo "----$DIR_TARGET/$file----";
	cp "$DIR_TARGET/$file" ./tests;
	./poisoner ./tests/"$file" >/dev/null;
	export TARGET=./tests/"$file";
	./diff_target.sh
done
