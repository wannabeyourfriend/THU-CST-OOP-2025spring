CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp dragon.cpp weapon.cpp ninja.cpp fire_ninja.cpp ice_ninja.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)