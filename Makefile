OBJS = *.cpp

BIN = game
HFILES = inc/*.cpp
INC = -ID:\programs\SDL2\SDL2-2.0.12\i686-w64-mingw32\include
LIB = -LD:\programs\SDL2\SDL2-2.0.12\i686-w64-mingw32\lib
DEPENDENCIES = libs\*.dll
WINFLAGS = -w -lmingw32
PRODFLAGS = -Wl,-subsystem,windows
FLAGS = -lSDL2main -lSDL2
ifeq ($(OS),Windows_NT)
	ARGS = $(INC) $(LIB) $(WINFLAGS) $(FLAGS)
else
	ARGS = $(INC) $(LIB) $(FLAGS)
endif


all : $(OBJS)
	g++ $(HFILES) $(OBJS) $(ARGS) $(PRODFLAGS) -o $(BIN)
ifeq ($(OS),Windows_NT)
	copy $(DEPENDENCIES) bin
	copy $(BIN).exe bin
	del $(BIN).exe
else
	cp $(BIN) bin
endif

dev : $(OBJS)
	g++ $(HFILES) $(OBJS) $(ARGS) -o $(BIN)
ifeq ($(OS),Windows_NT)
	copy $(DEPENDENCIES) bin
	copy $(BIN).exe bin
	del $(BIN).exe
else
	cp $(BIN) bin
endif

clean:
ifeq ($(OS),Windows_NT)
	del bin\$(BIN).exe
	del bin\*.dll
else
	rm -f $(BIN)
	rm -f bin/$(BIN)
endif