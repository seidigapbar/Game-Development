SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g

clean:
	rm build/debug/play
all:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
