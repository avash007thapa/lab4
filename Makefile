#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, and date.o to executable main
main: main.o time.o date.o calendar.o
	g++ -g -o main main.o time.o date.o calendar.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the calendar.cpp to calendar.o
calendar.o: calendar.cpp
	g++ -g -c calendar.cpp -std=c++11

#remove built files
clean:
	del -rf main main.o time.o date.o calendar.o *~

# change del to rm