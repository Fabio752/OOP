# -------- Variables --------
TARGET=bin/main_prog

OBJECTS=bin/item.o  bin/book.o  bin/dvd.o  bin/main.o

# -------- Compiler --------
CC=g++
CCFLAGS=-Wall

# -------- Compiling options --------
INCFLAGS=-I ./inc
#LIBFLAGS=-L ./lib

# -------- Compiling --------
bin/%.o : src/%.cpp
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

# -------- Linking --------
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

#note: if using an external library, placed in folder lib/, then use the variable LIBFLAGS
#$(CC) $(LIBFLAGS) $(OBJECTS) -o bin/$(TARGET)

	
# -------- Running --------
run:
	./$(TARGET)

# -------- Cleaning --------
clean:
	rm ./librarystate.txt bin/*.o $(TARGET)
	
	
###########################
# Documentation/Reminders #
###########################
# file name: either makefile or Makefile
# (not Make, nor Makefile.txt, nor Makefile.mk nor Makefile.mak etc...)
#
#
#Format of a rule:
#
#target: dependency(ies)
#[TAB]	command(s)
#
#(the second line has to start with a TABULATION)
#
#Warning about TAB:
#when copying/pasting from a PDF file e.g, re-check ALL the tabulations
#
#
#User-defined variables:
#definition: VAR_NAME=value
#use: $(VAR_NAME)
#