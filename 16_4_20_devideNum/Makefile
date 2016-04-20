CC=gcc
OBJ=devideNum.o

devideNum : ${OBJ}
	${CC} $^ -o $@

${OBJ} : %.o : %.c
	${CC} -c $< -o $@

clean:
	@rm -f *.o devideNum 

