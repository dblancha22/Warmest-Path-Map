#This is the Makefile for the CSE 20312 course Lecture 15

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj

# Command: make testGraph1
# Initial Examples of Graph
testGraph1Objs := $(OBJ)/testGraph1.o

testGraph1: $(testGraph1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testGraph1 $(testGraph1Objs)

$(OBJ)/testGraph1.o: $(SRC)/testGraph1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testGraph1.cpp -o $@

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize:
	mkdir $(OBJ) $(EXE)

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
