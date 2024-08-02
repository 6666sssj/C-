# 最终的目标名
TARGET := ../OBJ/main

# 指定一个编译器
CC := arm-linux-g++

# 找到我们的源文件夹 .cpp 文件
# 在当前路径下面找所有的 .cpp 文件
CFILES := $(wildcard ../CODE/SRC/*.cpp)
CFILES += $(wildcard ./*.cpp)

# 去掉路径
CFILES := $(notdir $(CFILES))

# 中间文件的名字 做模式替换
# 将所有的 .cpp 模式替换为 .o
# 到这里为止 没有 .o 文件生成
OBJS := $(patsubst %.cpp,../OBJ/%.o,$(CFILES))

# 头文件搜索路径
INCPATH := -I../CODE/INC
INCPATH += -I./
INCPATH += -I../LIB/inc

# std=c++ 版本
STD := -std=c++11

# 线程库
THREAD_LIB := -pthread

# tftp 路径
TFTPPATH := ~/tftpboot

# 最终的可执行文件依赖 .o 文件
# 将所有的 .o 文件进行链接
$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(INCPATH) $(STD) $(THREAD_LIB)
	cp $(TARGET) $(TFTPPATH)

# 生成 .o 文件的规则
../OBJ/%.o: ../CODE/SRC/%.cpp
	$(CC) -g -Wall -c $< -o $@ $(INCPATH) $(STD)

../OBJ/%.o: ./%.cpp
	$(CC) -g -Wall -c $< -o $@ $(INCPATH) $(STD)

# 打印调试信息
print:
	@echo $(CFILES)
	@echo $(OBJS)

# 清理生成的文件
clean:
	rm -rf $(OBJS) $(TARGET)
