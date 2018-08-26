#!/bin/bash

make -C $PROJECT_PATH
echo "$DIR_TARGET" | while IFS= read -r -d ':' dir_target
do
	for file in `find "$dir_target" -type f -print`
	do
		export i=0;
		while [ $i -ne $MAX_POISON ]
		do
			echo "Poisoning $file...";
			$PROJECT_PATH/poisoner $file
			i=$((i + 1))
		done
	done
done
