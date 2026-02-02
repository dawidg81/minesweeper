CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC = src/Game.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = minesweeper

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

