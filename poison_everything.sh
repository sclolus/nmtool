#!/bin/bash

make
echo "$DIR_TARGET" | while IFS= read -r -d ':' file
do
	export i=0;
	while [ $i -ne $MAX_POISON ]
	do
		echo "Poisoning $TARGET...";
		$PROJECT_DIR/poisoner $file
		i=$((i + 1))
	done
done
