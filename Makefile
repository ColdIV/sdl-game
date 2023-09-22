OBJS = *.cpp

HFILES = inc/*.cpp
INC = -Ilibs\SDL2\SDL2-2.0.12\x86_64-w64-mingw32\include
LIB = -Llibs\SDL2\SDL2-2.0.12\x86_64-w64-mingw32\lib
DEPENDENCIES = libs\*.dll
WINFLAGS = -w -lmingw32
PRODFLAGS = -Wl,-subsystem,windows
FLAGS = -lSDL2main -lSDL2 -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
ifeq ($(OS),Windows_NT)
	ARGS = $(INC) $(LIB) $(WINFLAGS) $(FLAGS)
	BIN = bin/game.exe
else
	ARGS = $(INC) $(LIB) $(FLAGS)
	BIN = bin/game
endif

$(BIN) : $(OBJS)
ifeq ($(OS),Windows_NT)
	g++ $(HFILES) $(OBJS) $(ARGS) $(PRODFLAGS) -o $(BIN)
	copy $(DEPENDENCIES) bin
else
	g++ $(HFILES) $(OBJS) $(ARGS) -o $(BIN)
endif

all : $(BIN)

dev : $(OBJS)
	g++ $(HFILES) $(OBJS) $(ARGS) -o $(BIN)
ifeq ($(OS),Windows_NT)
	copy $(DEPENDENCIES) bin
else
	cp $(BIN) bin
endif

clean:
ifeq ($(OS),Windows_NT)
	del $(BIN)
	del bin\*.dll
else
	rm -f $(BIN)
	rm -f bin/$(BIN)
endif
