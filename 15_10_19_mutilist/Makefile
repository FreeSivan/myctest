CC=gcc
OBJ=mutilist.o main.o

main : ${OBJ}
	${CC} $^ -o $@

%.o : %.c
	${CC} -c $< -o $@

clean :
	@rm -r *.o main

