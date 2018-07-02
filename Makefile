CC = g++
FLAGS = -c -Wall -Wpedantic -Wextra -Werror

output: main.o square.o shape.o rectangle.o circle.o
	$(CC) main.o Square.o Shape.o Rectangle.o Circle.o -o output

main.o: Square.hpp Shape.hpp Rectangle.hpp Circle.hpp main.cpp
	$(CC) $(FLAGS) main.cpp 

square.o: Square.cpp Square.hpp
	$(CC) $(FLAGS) Square.cpp  

shape.o: Shape.cpp Shape.hpp
	$(CC) $(FLAGS) Shape.cpp 
 
rectangle.o: Rectangle.cpp Rectangle.hpp
	$(CC) $(FLAGS) Rectangle.cpp  

circle.o: Circle.cpp Circle.hpp
	$(CC) $(FLAGS) Circle.cpp  

clean:
	rm *.o output

