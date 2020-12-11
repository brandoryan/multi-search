# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
# -std=c++11 using the 2011 version of c++
CFLAGS = -std=c++11

# the build target executable:
PART3 = multi-search

all: $(PART3)

$(PART3): Assignment1Part3.cpp
	$(CC) $(CFLAGS) -o $(PART3) Assignment1Part3.cpp
	./$(PART3) strings.txt abcd 10

clean:
	$(RM) $(PART3)
