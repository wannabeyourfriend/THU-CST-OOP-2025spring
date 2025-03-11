CXX = g++
CXXFLAGS = -Wall

SRCS = main.cpp sum.cpp minus.cpp product.cpp divide.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

.PHONY: all clean debug minus product divide

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

debug: CXXFLAGS += -D DEBUG
debug: clean all

minus: CXXFLAGS += -D MINUS
minus: clean all

product: CXXFLAGS += -D PRODUCT
product: clean all

divide: CXXFLAGS += -D DIVIDE
divide: clean all

# 添加组合命令
debug_minus: CXXFLAGS += -D DEBUG -D MINUS
debug_minus: clean all

debug_product: CXXFLAGS += -D DEBUG -D PRODUCT
debug_product: clean all

debug_divide: CXXFLAGS += -D DEBUG -D DIVIDE
debug_divide: clean all

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)