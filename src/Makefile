.PHONY: 21_decimal.a test clean cppcheck format
all: s21_decimal.a test clean

CFLAGS = -I. 

binary_s := $(shell find ./binary -maxdepth 1 -iname "*.c" )
comparison_s := $(shell find ./comparison -maxdepth 1 -iname "*.c" )
conversion_s := $(shell find ./conversion -maxdepth 1 -iname "*.c" )
helpers_s := $(shell find ./helpers -maxdepth 1 -iname "*.c" )
math_ops_s := $(shell find ./math_ops -maxdepth 1 -iname "*.c" )

all := $(shell find ./ -iname "*.c" )
test_f := $(shell find ./tests/ -iname "*.c" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@.a -lcheck -lpthread -lm  -Wuninitialized -Winit-self -Wmaybe-uninitialized -fanalyzer -Wall -Werror -Wextra
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@.a -lcheck -lgcov -lpthread -lm
endif

s21_decimal.a: ${binary_s} ${helpers_s} ${math_ops_s} ${conversion_s} ${comparison_s}
	gcc -g -c  ${CFLAGS} $^
	ar rc $@  *.o
	ranlib $@

test: ${test_f} s21_decimal.a
	gcc -g $(CFLAGS) $(TEST_FLAGS)
	./$@.a

cppcheck: $(all) 
	cppcheck $^;

format: $(all)
	cp ../materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format


clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf lib* && rm -rf test
	-rm -rf test_*
