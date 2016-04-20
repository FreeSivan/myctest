CC=gcc
OBJ=combine.o

combine : ${OBJ}
	${CC} $^ -o $@

${OBJ} : %.o : %.c
	${CC} -c $< -o $@

clean:
	@rm -f *.o combine 

