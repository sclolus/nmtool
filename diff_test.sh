make && for file in `ls -1 "$DIR_TARGET"`; do echo "$file"; ./ft_nm "$DIR_TARGET/$file" > diff.txt 2>/dev/null && nm "$DIR_TARGET/$file" > diff_bin.txt 2>/dev/null && diff diff*.txt ; done
