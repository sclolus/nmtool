nm -j $1 > diff_bin;
./ft_nm -j $1 > diff;
diff diff_bin diff || echo $1 >> diff_test_log;
rm diff diff_bin;
