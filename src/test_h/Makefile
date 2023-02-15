APP ?= binary
.PHONY: all clean test

lib${APP}: *.c
	cd ${APP} && \
	gcc -g -c  $^ &&\
	ar rc $@  *.o &&\
	ranlib $@ 

test:
	APP = BINARY
	${shell echo ${APP}}