OBJS = main.cpp
OBJS_EDITOR = editor.cpp

BIN = game
BIN_EDITOR = editor
HFILES = game/*.cpp
HFILES_EDITOR = editor/*.cpp
INC = -Ilibs\SDL2\SDL2-2.0.12\i686-w64-mingw32\include -Ilibs\SDL2\SDL2-2.0.12\i686-w64-mingw32\include\SDL2 -Ilibs\SDL2\SDL2_image-2.0.5\i686-w64-mingw32\include
LIB = -Llibs\SDL2\SDL2-2.0.12\i686-w64-mingw32\lib -Llibs\SDL2\SDL2_image-2.0.5\i686-w64-mingw32\lib
DEPENDENCIES = libs\*.dll
WINFLAGS = -w -lmingw32
PRODFLAGS = -Wl,-subsystem,windows
FLAGS = -lSDL2main -lSDL2 -lSDL2_image
ifeq ($(OS),Windows_NT)
	ARGS = $(INC) $(LIB) $(WINFLAGS) $(FLAGS)
else
	ARGS = $(INC) $(LIB) $(FLAGS)
endif


all : $(OBJS)
ifeq ($(OS),Windows_NT)
# build game
	g++ $(HFILES) $(OBJS) $(ARGS) $(PRODFLAGS) -o $(BIN)
	copy $(DEPENDENCIES) bin
	copy $(BIN).exe bin
	del $(BIN).exe
# build editor
	g++ $(HFILES_EDITOR) $(OBJS_EDITOR) $(ARGS) $(PRODFLAGS) -o $(BIN_EDITOR)
	copy $(BIN_EDITOR).exe bin
	del $(BIN_EDITOR).exe
else
# build game
	g++ $(HFILES) $(OBJS) $(ARGS) -o $(BIN)
	cp $(BIN) bin
# build editor
	g++ $(HFILES_EDITOR) $(OBJS_EDITOR) $(ARGS) -o $(BIN_EDITOR)
	cp $(BIN_EDITOR) bin
endif

# build game
g : $(OBJS)
ifeq ($(OS),Windows_NT)
	g++ $(HFILES) $(OBJS) $(ARGS) $(PRODFLAGS) -o $(BIN)
	copy $(DEPENDENCIES) bin
	copy $(BIN).exe bin
	del $(BIN).exe
else
	g++ $(HFILES) $(OBJS) $(ARGS) -o $(BIN)
	cp $(BIN) bin
endif

# build editor
e : $(OBJS_EDITOR)
ifeq ($(OS),Windows_NT)
	g++ $(HFILES_EDITOR) $(OBJS_EDITOR) $(ARGS) $(PRODFLAGS) -o $(BIN_EDITOR)
	copy $(DEPENDENCIES) bin
	copy $(BIN_EDITOR).exe bin
	del $(BIN_EDITOR).exe
else
	g++ $(HFILES_EDITOR) $(OBJS_EDITOR) $(ARGS) -o $(BIN_EDITOR)
	cp $(BIN_EDITOR) bin
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