# 定义编译器
CXX := g++

# 定义编译选项
CXXFLAGS := -Wall -g

# 定义最终生成的可执行文件名称
TARGET := main

# 默认目标，执行 make 时会首先构建此目标
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译 main.cc 生成 main.o
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译生成的文件
clean:
	rm -f $(TARGET) *.o

# 声明伪目标，避免与同名文件冲突
.PHONY: all clean