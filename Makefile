# ���������
CXX := g++

# �������ѡ��
CXXFLAGS := -Wall -g

# �����������ɵĿ�ִ���ļ�����
TARGET := main

# Ĭ��Ŀ�ִ꣬�� make ʱ�����ȹ�����Ŀ��
all: $(TARGET)

# �������ɿ�ִ���ļ�
$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# ���� main.cc ���� main.o
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ����������ɵ��ļ�
clean:
	rm -f $(TARGET) *.o

# ����αĿ�꣬������ͬ���ļ���ͻ
.PHONY: all clean