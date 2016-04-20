CC=gcc
OBJ=perm.o

perm : ${OBJ}
	${CC} $^ -o $@

${OBJ} : %.o : %.c
	${CC} -c $< -o $@

clean:
	@rm -f *.o perm 

