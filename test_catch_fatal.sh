#!/bin/bash

echo "$DIR_TARGET" | while IFS= read -r -d ':' TARGET
do
	echo "$TARGET";
	for file in `find "$TARGET" -type f -print`;
	do
		echo "$file"; "$PROJECT_PATH"/ft_nm $NM_FLAGS "$file" > diff.txt
		if [[ $? -ge 129 ]]
		then
			echo "SEGV on $TARGET"
			exit 3.14
		else
			echo "OK"
		fi
	done
done
