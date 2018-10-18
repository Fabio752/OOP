point.o: point.cpp point.hpp
	g++ -c point.cpp

main.o: main.cpp
	g++ -c main.cpp

link: point.o main.o
	g++ main.o point.o -o prog

all: point.cpp point.hpp main.cpp
	g++ -c point.cpp
	g++ -c main.cpp	

run:
	./prog

clean:
	rm *.o prog


compile: point.cpp point.hpp main.cpp point.o main.o
	g++ -c point.cpp
	g++ -c main.cpp	
	g++ main.o point.o -o prog
	./prog
