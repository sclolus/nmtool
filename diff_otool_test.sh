make
echo "$DIR_TARGET" | while IFS= read -r -d ':' TARGET
do
	echo "$TARGET";
	for file in `ls -1 "$TARGET"`;
	do
		echo "$file"; "$PROJECT_PATH"/ft_otool "$TARGET/$file" > diff.txt
		if [[ $? -ge 129 ]]
		then
			echo "SEGV on $TARGET"
			exit 3.14
		fi

		otool -t "$TARGET/$file" > diff_bin.txt
		diff diff.txt diff_bin.txt || exit
	done
done
