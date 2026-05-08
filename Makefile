CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

all: ex4

ex4: ex4.cpp
	$(CXX) $(CXXFLAGS) -o ex4 ex4.cpp

clean:
	rm -f ex4
