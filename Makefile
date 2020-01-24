compile: main.cpp
	g++ -std=c++11 -Wall main.cpp 

build: 
	g++ -Wall -std=c++11 main.cpp

run:
	make compile
	./a.out -f input.txt
	./a.out -f input.txt -print_col_type 0
	./a.out -f input.txt -print_col_type 1
	./a.out -f input.txt -is_missing_idx 2 2
	./a.out -f input.txt -is_missing_idx 2 0
	./a.out -f input.txt -print_col_idx 2 0
	./a.out -f input.txt -print_col_idx 2 0

test:
	./a.out -f input.txt
	./a.out -f input.txt -print_col_type 0
	./a.out -f input.txt -print_col_type 1
	./a.out -f input.txt -is_missing_idx 2 2
	./a.out -f input.txt -is_missing_idx 2 0
	./a.out -f input.txt -print_col_idx 2 0
	./a.out -f input.txt -print_col_idx 2 0

clean: 
	rm -rf .vscode
	rm -rf a.out.dSYM
	rm a.out
	