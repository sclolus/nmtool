make && for file in `ls -1 "$DIR_TARGET"`; do echo "$file"; ./ft_nm "$DIR_TARGET/$file" > diff.txt && nm "$DIR_TARGET/$file" > diff_bin.txt && diff diff*.txt ; done
