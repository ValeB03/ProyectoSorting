CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

SRC = $(wildcard src/*.cpp) \
      $(wildcard src/algoritmos/*.cpp)

OBJ = $(SRC:.cpp=.o)

TARGET = programa

ifeq ($(OS),Windows_NT)
    TARGET := build/programa.exe
    RM = del /Q
    RUN = .\$(TARGET)
    MKDIR = if not exist build mkdir build
else
    TARGET := build/programa
    RM = rm -f
    RUN = ./$(TARGET)
    MKDIR = mkdir -p build
endif

all: $(TARGET) cleanobj

$(TARGET): $(OBJ)
	$(MKDIR)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	$(RUN)

cleanobj:
ifeq ($(OS),Windows_NT)
	-if exist src\*.o $(RM) src\*.o
	-if exist src\algoritmos\*.o $(RM) src\algoritmos\*.o
else
	-$(RM) src/*.o
	-$(RM) src/algoritmos/*.o
endif

clean:
ifeq ($(OS),Windows_NT)
	-if exist src\*.o $(RM) src\*.o
	-if exist src\algoritmos\*.o $(RM) src\algoritmos\*.o
	-if exist $(TARGET) $(RM) $(TARGET)
else
	-$(RM) src/*.o
	-$(RM) src/algoritmos/*.o
	-$(RM) $(TARGET)
endif