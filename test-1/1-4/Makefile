# 1. 定义编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# 2. 定义最终生成的可执行文件名
TARGET = main

# 3. 自动查找所有 .cpp 文件
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标：编译所有东西
all: $(TARGET)

# 链接规则：从.o文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

# 编译规则：从.cpp文件生成.o文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# 清理规则
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean