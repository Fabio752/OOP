# -------- Variables --------
TARGET=bin/main_prog

OBJECTS=bin/item.o  bin/restricted.o  bin/unrestricted.o  bin/main.o

# -------- Compiler --------
CC=g++
CCFLAGS=-Wall

# -------- Compiling options --------
INCFLAGS=-I ./include
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
	rm bin/*.o $(TARGET)
	
	