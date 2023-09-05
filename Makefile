# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
# add person class here when made 
EXE_OBJ = main.o
OBJS = main.o graph.o algorithms.o readFile.o

# Use the cs225 makefile template:
include make/cs225.mk

