triangle.o: triangle.cpp
	g++ -c triangle.cpp

point.o: point.cpp point.hpp
	g++ -c point.cpp

main.o: main.cpp
	g++ -c main.cpp

link: point.o main.o triangle.o
	g++ main.o point.o triangle.o -o prog

all: point.cpp point.hpp main.cpp
	g++ -c point.cpp
	g++ -c main.cpp	
	g++ -c triangle.cpp

run:
	./prog

clean:
	rm *.o prog


compile: point.cpp point.hpp main.cpp point.o main.o
	g++ -c point.cpp
	g++ -c main.cpp	
	g++ -c triangle.cpp
	g++ main.o point.o triangle.o -o prog
	./prog
