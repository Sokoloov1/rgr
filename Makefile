# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = app.exe

# Исходные файлы (только для Атбаша, Цезаря и Гронсфельда)
SRCS = main.cpp Atbash.cpp Cezar.cpp Gronsfeld.cpp
OBJS = $(SRCS:.cpp=.o)

# Сборка проекта
all: $(TARGET)

# Создание исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	del $(OBJS)
	cls

# Компиляция каждого .cpp файла в .o
%.o: %..cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	del $(OBJS)
	del $(TARGET)
.PHONY: all clean
