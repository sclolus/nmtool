#!/bin/bash
./ft_nm "$TARGET"_poisoned > diff.txt ; nm "$TARGET"_poisoned > diff_bin.txt ; diff diff*.txt
