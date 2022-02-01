CYAN  =\033[95m
GREEN =\033[96m
RESET =\033[0m

CC         = g++
CXFLAGS    = -Wall -fPIC -std=c++11
LIB_DIR    = ./lib
BUILD_DIR  = ./build
INCLUDE_LIB= ./include/candybar.h
LIB        = libcandybar.so
INCLUDE    = -Iinclude/
SRC        = $(wildcard src/*.cpp)
OBJECTS   := $(SRC:%.cpp=$(BUILD_DIR)/%.o)

MAJOR_V := 1
MINOR_V := 3
BUILD_V := 4

.PHONY: all build clean install

all: build $(LIB_DIR)/$(LIB) $(BUILD_DIR)/$(TARGET)
	@ echo -e "$(GREEN)[i] Done $(RESET)"

$(LIB_DIR)/$(LIB): $(OBJECTS)
	@ echo -e "$(GREEN)[i] Compiling the candy-bar library ...\n $(RESET)"
	@ $(CC) --shared $^ -o $@

$(BUILD_DIR)/%.o: %.cpp 
	@ mkdir -p $(@D)
	@ echo -e "${CYAN}    $^ ${RESET}"
	@ $(CC) $(CXFLAGS) $(INCLUDE) -c -o $@ $^

build:
	@ echo -e "${GREEN}[i] Starting the build process ${RESET}"
	@ mkdir -p $(BUILD_DIR)
	@ mkdir -p $(LIB_DIR)

install: $(LIB_DIR)/$(LIB)
	@ echo -e "$(GREEN)[i] Installing the candy-bar library ...\n $(RESET)"
	@ sudo cp $(LIB_DIR)/$(LIB) /usr/lib/$(LIB).${MAJOR_V}.${MINOR_V}.${BUILD_V}
	@ sudo cp $(INCLUDE_LIB) /usr/include
	@ sudo ln -sf /usr/lib/$(LIB).${MAJOR_V}.${MINOR_V}.${BUILD_V} /usr/lib/$(LIB).${MAJOR_V}
	@ sudo ln -sf /usr/lib/$(LIB).${MAJOR_V}.${MINOR_V}.${BUILD_V} /usr/lib/$(LIB)
	@ sudo chmod 755 /usr/lib/$(LIB)
	@ echo -e "$(GREEN)[i] Done $(RESET)"

clean:
	@ echo -e "${GREEN} Cleaning up ${RESET}"
	@ rm -rf $(BUILD_DIR)/*
	@ rm -rf $(LIB_DIR)/*
