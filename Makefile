main: main.cpp
	g++ main.cpp -std=c++11 -o test

run:
	make main
	./test -f input.txt