CC=g++
OBJ=future.o
TARGET=future
CPPFLAGS= -lpthread

${TARGET} : ${OBJ}
	${CC} $^ ${CPPFLAGS} -o $@

${OBJ} : %.o : %.cpp
	${CC} $< -c -o $@ 

clean:
	@rm -f *.o ${TARGET}
