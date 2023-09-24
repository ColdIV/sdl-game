# Define the compiler and compiler flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++11
INCLUDES := -I./include
LDFLAGS := -lSDL2 

# Define the source and object directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# List of source files and their corresponding object files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
MAIN := main.cpp

# Set platform-specific variables and commands
ifeq ($(OS),Windows_NT)
	# Windows settings
	INCLUDES += -Ilibs\SDL2\SDL2-2.0.12\x86_64-w64-mingw32\include
	LDFLAGS += -Llibs\SDL2\SDL2-2.0.12\x86_64-w64-mingw32\lib -w -lmingw32 -Wl,-subsystem,windows -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
	EXECUTABLE := $(BIN_DIR)/game.exe
else
	# Linux settings
	INCLUDES += `sdl2-config --cflags`
	LDFLAGS += `sdl2-config --libs`
	EXECUTABLE := $(BIN_DIR)/game
endif

# Default target
all: $(EXECUTABLE)

# Link the object files to create the executable
$(EXECUTABLE): $(MAIN) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

# Compile the source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

# Generate dependencies using makedepend
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ | sed -E 's/(^[a-zA-Z]+).o:/$(OBJ_DIR)\/\1.o:/g' >> ./.depend;

# Clean the generated files
clean:
	rm -f ./.depend
	rm -f $(EXECUTABLE) $(OBJECTS) ./.depend

# Include the generated dependencies
include .depend

.PHONY: all clean depend
