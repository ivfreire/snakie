GCC					= g++
FLAGS				= -Wall

MAIN				= src/main.cpp
INPUT				=
OUTPUT				= build/snaky

INCLUDES			= src/game.cpp src/world.cpp src/snake.cpp src/apple.cpp
LIBRARIES			=
DEPENDENCIES		= -lSDL2main -lSDL2

all $(MAIN):
	$(GCC) $(FLAGS) $(MAIN) -o $(OUTPUT) $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES)
	$(OUTPUT)