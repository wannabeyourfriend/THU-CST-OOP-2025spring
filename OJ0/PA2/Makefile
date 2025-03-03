# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11

# 目标文件
OBJS = main.o editor.o judge.o

# 可执行文件
TARGET = main

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 编译源文件为目标文件
main.o: main.cpp editor.h judge.h
	$(CXX) $(CXXFLAGS) -c main.cpp

editor.o: editor.cpp editor.h
	$(CXX) $(CXXFLAGS) -c editor.cpp

judger.o: judge.cpp judge.h
	$(CXX) $(CXXFLAGS) -c judger.cpp

# 清理规则
clean:
	rm -f $(OBJS) $(TARGET)
