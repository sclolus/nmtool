nm $1 $2 > diff_bin 2>/dev/null;
./ft_nm $1 $2 > diff;
diff diff_bin diff || echo $2 >> diff_test_log;
rm diff diff_bin;
