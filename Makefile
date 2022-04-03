SRC_DIR = src
BUILD_DIR = build/debug
CC = g++ -arch x86_64
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -I./libs -F./Frameworks -framework SDL2_image -F./Frameworks -framework SDL2

clean:
	rm build/debug/play
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
