CFLAGS=-std=c++11 -g
debug:
	g++ $(CFLAGS) main.cpp TodoList.h -o debug

todo:
	g++ main.cpp TodoList.h -o TODO

valgrind:
	g++ -g main.cpp TodoList.h -o TODO

clean:
	rm -f TODO