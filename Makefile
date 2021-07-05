CXX := g++
CXXFLAGS := -std=c++17 -m32 -I$(SDIR) -Wall -g -I. -fPIC
LDFLAGS := -m32 -shared -fPIC
TARGET := plug.so

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
		$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $<

clean:
		rm -rf $(TARGET) *.o