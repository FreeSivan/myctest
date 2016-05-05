CC=g++
OBJ=mtqueue.o
TARGET=mtqueue
CXXFLAG= -lpthread

${TARGET} : ${OBJ}
	${CC} $^ ${CXXFLAG} -o $@

${OBJ} : %.o : %.cc
	${CC} -c $< -o $@

clean:
	@rm -f *.o ${TARGET} 

