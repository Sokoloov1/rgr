CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I.
TARGET = cipher_app
SRCS = main.cpp Atbash.cpp Cezar.cpp Gronsfeld.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@del $(OBJS) 2> nul || true

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@del $(OBJS) $(TARGET) 2> nul || true

.PHONY: all clean
