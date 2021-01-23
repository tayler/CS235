CFLAGS=-std=c++11 -g

todo:
	g++ main.cpp TodoList.h -o TODO

debug:
	g++ $(CFLAGS) main.cpp TodoList.h -o debug

clean-debug:
	rm -f debug

valgrind:
	g++ -g main.cpp TodoList.h -o TODO

clean:
	rm -f TODO