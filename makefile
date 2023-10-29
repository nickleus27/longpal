CXX = clang++
CXXFLAGS = -std=c++17
CC = clang
CCFLAGS = -std=c17

all: longpal

longpal: longpal.cpp
	$(CXX) $(CXXFLAGS) -o longpal longpal.cpp

clean:
	rm -rf longpal longpal_debug
