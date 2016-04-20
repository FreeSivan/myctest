CC=gcc
OBJ=partperm.o

partperm : ${OBJ}
	${CC} $^ -o $@

${OBJ} : %.o : %.c
	${CC} -c $< -o $@

clean:
	@rm -f *.o partperm 

