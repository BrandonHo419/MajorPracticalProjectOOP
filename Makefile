# Compiler and flags
CXX = g++
CXXFLAGS = -g -I/path/to/OOP/include
LDFLAGS = -L/path/to/OOP/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Executable and object files
EXEC = code
OBJS = wholeGameMain.o GridMap.o Animation.o Strawberries.o Carrots.o \
       Beets.o Tomatoes.o Blueberries.o UIElement.o Button.o \
       Player.o Weather.o Shop.o Scroll.o Fences.o Audio.o

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compile cpp files
wholeGameMain.o: wholeGameMain.cpp
	$(CXX) $(CXXFLAGS) -c wholeGameMain.cpp

GridMap.o: GridMap.cpp
	$(CXX) $(CXXFLAGS) -c GridMap.cpp

Animation.o: Animation.cpp
	$(CXX) $(CXXFLAGS) -c Animation.cpp

Strawberries.o: Strawberries.cpp
	$(CXX) $(CXXFLAGS) -c Strawberries.cpp

Carrots.o: Carrots.cpp
	$(CXX) $(CXXFLAGS) -c Carrots.cpp

Beets.o: Beets.cpp
	$(CXX) $(CXXFLAGS) -c Beets.cpp

Tomatoes.o: Tomatoes.cpp
	$(CXX) $(CXXFLAGS) -c Tomatoes.cpp

Blueberries.o: Blueberries.cpp
	$(CXX) $(CXXFLAGS) -c Blueberries.cpp

UIElement.o: UIElement.cpp
	$(CXX) $(CXXFLAGS) -c UIElement.cpp

Button.o: Button.cpp
	$(CXX) $(CXXFLAGS) -c Button.cpp

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Weather.o: Weather.cpp
	$(CXX) $(CXXFLAGS) -c Weather.cpp

Shop.o: Shop.cpp
	$(CXX) $(CXXFLAGS) -c Shop.cpp

Scroll.o: Scroll.cpp
	$(CXX) $(CXXFLAGS) -c Scroll.cpp

Fences.o: Fences.cpp
	$(CXX) $(CXXFLAGS) -c Fences.cpp

Audio.o: Audio.cpp
	$(CXX) $(CXXFLAGS) -c Audio.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)