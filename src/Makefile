GCC = gcc
CFLAGS = -I. 
LDFLAGS = -c
# TEST_FLAGS = -g -O0 -Wuninitialized -Winit-self -Wmaybe-uninitialized --fanalyzer -Wall -Werror -Wextra

# DIRS = ./comparison ./conversion ./math_ops ./other_func
# SOURCE := $(shell find ${DIRS}  -iname "*.c" )
# TEST_SOURCE := $(shell find ./tests  -iname "*.c" )
# HEADER_SOURCE := $(shell find . -iname "*.h" )
# BINARY_SOURCE := $(shell find ./binary_api -iname "*.c" )

# ifeq ($(shell uname -s),Darwin)
# 	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
# else
# 	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit
# endif

# all: clean s21_decimal.a test
# s21_decimal.a: ${SOURCE} clean
# 	$(GCC) -c $(CFLAGS) $(LDFLAGS) $(SOURCE)
# 	ar rc $@  *.o
# 	ranlib $@

# test: ${SOURCE} ${TEST_SOURCE}
# 	$(GCC) -g  $(CFLAGS) $^ -o $@

# vertor: ${SOURCE} ${TEST_SOURCE}
# 	$(GCC) -g  $(CFLAGS) $(TEST_FLAGS) $^ -o $@

# gcov_report: test
# 	gcov $(SOURCE) $(TEST_SOURCE)
# 	rm -rf s21_decimal_test.gcda s21_decimal_test.gcno
# 	find ./ -type f -iname '*.gcda'
# 	lcov --directory ./ --capture --output-file postgresql.info
# 	mkdir cov-report
# 	genhtml -o ./cov-report/ postgresql.info

# lcov:
# ifeq ("", "$(shell PATH=$(PATH) which lcov)")
# 	$(error Need to install lcov)
# endif

# cpplint: $(SOURCE) $(SOURCE_TEST)
# 	python3 ../materials/linters/cpplint.py --extensions=c $^

# leaks: test
# 	leaks -atExit -- ./test

# cppcheck: $(SOURCE) $(SOURCE_TEST) ${HEADER_SOURCE}
# 	cppcheck $^;

# format: ${SOURCE} ${TEST_SOURCE} ${HEADER_SOURCE}
# 	cp .././materials/linters/.clang-format .
# 	clang-format -i -style=google $^;
# 	rm .clang-format

# valgrind: test
# 	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test
# 	valgrind --leak-check=full --leak-resolution=high test



BINARY_SOURCE := $(shell find ./binary_api -d 1 -iname "*.c" )
LIB_INC ?=libbinary
TEST_SOURCE_CORE := $(shell find ./tests/tests_binary -iname "*.c" )


ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit
endif


libbinary: ${BINARY_SOURCE}
	gcc -g -c  $^
	ar rc $@  *.o
	ranlib $@
	make clean

test_core: ${TEST_SOURCE_CORE} libbinary
	make clean
	$(GCC) $(CFLAGS) $(TEST_FLAGS)  -DTESTS_CORE
	./$@

# Excemle run 
# make main.a with default{libbinary}
# make main.a LIB_INC=test wuth lib test
main: ${LIB_INC}
	gcc  -g main.c ${LIB_INC} -o $@
	./main || true
clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf test
.PHONY: libbinary main.a
