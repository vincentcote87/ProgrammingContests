# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -std=c++11 -Wall

OBJECTS = 4882 4883 4884 4885 4886 4887 4888 4889 4890

.PHONY: all

all:
	$(OBJECTS)

$(OBJECTS): %:%.cpp

clean:
	rm -f $(OBJECTS)