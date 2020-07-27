GCC					= g++
FLAGS				= -Wall

MAIN				= src/main.cpp
INPUT				=
OUTPUT				= build/sneaky

INCLUDES			= src/game.cpp
LIBRARIES			=
DEPENDENCIES		= -lSDL2main -lSDL2

all $(MAIN):
	$(GCC) $(FLAGS) $(MAIN) -o $(OUTPUT) $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES)
	$(OUTPUT)