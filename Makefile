main: main.cpp
	g++ main.cpp -std=c++11 -o test

run:
	make main
	./test -f input.txt
	./test -f input.txt -print_col_type 0
	./test -f input.txt -print_col_type 1
	./test -f input.txt -is_missing_idx 2 2
	./test -f input.txt -is_missing_idx 2 0
	./test -f input.txt -print_col_idx 2 0
	./test -f input.txt -print_col_idx 2 1