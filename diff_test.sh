make
echo "$DIR_TARGET" | while IFS= read -r -d ':' TARGET
do
	echo "$TARGET";
	for file in `ls -1 "$TARGET"`;
	do
		echo "$file"; ./ft_nm $NM_FLAGS "$TARGET/$file" > diff.txt #2>/dev/null
		nm $NM_FLAGS "$TARGET/$file" > diff_bin.txt #2>/dev/null
		diff diff.txt diff_bin.txt
	done
done
