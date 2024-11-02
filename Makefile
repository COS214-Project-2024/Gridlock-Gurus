main: *.o
	g++ -std=c++20 -o main *.o

*.o: *.cpp *.h
	clear
	g++ -std=c++20 -c -g *.cpp

run:
	./main

clean:
	clear
	rm *.o main