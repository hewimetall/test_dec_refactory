GCC = gcc
CFLAGS = -I. 
LDFLAGS = -c

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
