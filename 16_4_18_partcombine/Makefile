CC=g++

obj=partcombine.o

partcombine : ${obj}
	${CC} $^ -o $@

${obj} : %.o : %.c
	${CC} -c $< -o $@

clean:
	@rm -f *.o partcombine


