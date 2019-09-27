# Comment lines
# General makefile for c++ - choose PROG =   name of given program
# Here we define compiler option, libraries and the  target
CPPflags= c++ -O3
# Here we define the library functions we nee
LIB = -larmadillo -llapack -lblas
# Here we define the name of the executable
PROG= testcode
${PROG} :	   	CatchMain.o  test-functions.o jacobi.o
			${CPPflags} CatchMain.o test-functions.o jacobi.o ${LIB} -o ${PROG}

CatchMain.o :			CatchMain.cpp
		        	${CPPflags} -c CatchMain.cpp

test-functitons.o :			test-functions.cpp
		        	${CPPflags} -c test-functions.cpp

jacobi.o :		jacobi.cpp
		        	${CPPflags} -c jacobi.cpp
