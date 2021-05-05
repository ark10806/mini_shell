mini_shell.out : h.o main.o
	g++ -std=c++11 -o mini_shell.out h.o main.o

h.o : history.cpp
	g++ -std=c++11 -c -o h.o history.cpp

main.o : mini_shell.cpp
	g++ -std=c++11 -c -o main.o mini_shell.cpp

clean:
	rm *.o mini_shell.out
