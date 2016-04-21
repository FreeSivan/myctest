CC=g++

obj=composite.o

composite : ${obj}
	${CC} $^ -o $@

${obj} : %.o : %.cpp
	${CC} -c $< -o $@

clean:
	@rm -f *.o composite


