#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, and date.o to executable main
main: main.o stack.o 
	g++ -g -o main main.o stack.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the calendar.cpp to calendar.o
stack.o: stack.cpp
	g++ -g -c stack.cpp -std=c++11

#remove built files
clean:
	del -rf main main.o stack.o *~

# change del to rm