CXX=g++ 
CXXFLAGS=-g

OBJS = entero.o racional.o real.o complejo.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o numeros ${OBJS}

clean: 
	rm -rf *.o numeros