# Makefile

# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -IC:/Users/brand/OneDrive/Documents/sfml/sfml/include -Wall -g

# Linker Flags
LDFLAGS = -LC:/Users/brand/OneDrive/Documents/sfml/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Target Executable
Target = game

# Source Files
SRCS = oldMain.cpp Shop.cpp Player.cpp Animation.cpp Blueberries.cpp Beets.cpp Coin.cpp Gridmap.cpp Carrots.cpp Tomatoes.cpp Text.cpp Strawberries.cpp UI.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all:$(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Rule to compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)