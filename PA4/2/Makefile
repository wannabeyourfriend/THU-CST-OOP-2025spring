CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Part.cpp Robot.cpp Alice.cpp Bob.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)