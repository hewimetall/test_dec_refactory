.PHONY: lib* test* 21_decimal.a clean all
all: 21_decimal.a clean
include make_libs
include make_test

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf lib* && rm -rf test
	-rm -rf test_*
