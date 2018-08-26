make "$PROJECT_PATH"
echo "$DIR_TARGET" | while IFS= read -r -d ':' TARGET
do
	echo "$TARGET";
	for file in `find "$TARGET" -type f -print`;
	do
		echo "$file"; "$PROJECT_PATH"/ft_"$TEST_BIN" $NM_FLAGS "$file" > diff.txt
		if [[ $? -ge 129 ]]
		then
			echo "SEGV on $TARGET"
			exit 3.14
		fi
		echo "$TEST_BIN" "$NM_FLAGS" "$file"
		$TEST_BIN $NM_FLAGS "$file" > diff_bin.txt
		diff diff.txt diff_bin.txt || exit
	done
done
