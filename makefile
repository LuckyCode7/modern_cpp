CXX = g++
CXXFLAGS = -c -g -Wall -Wpedantic -Wextra -Werror
OBJ = Circle.o Rectangle.o Shape.o Square.o main.o

output: $(OBJ)
	$(CXX) $(OBJ) -o output

main.o: main.cpp Square.hpp Shape.hpp Rectangle.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

square.o: Square.cpp Square.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

shape.o: Shape.cpp Shape.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

rectangle.o: Rectangle.cpp Rectangle.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

circle.o: Circle.cpp Circle.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o output
