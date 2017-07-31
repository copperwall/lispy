CXX=clang++
LDFLAGS=-g -std=c++11
CFLAGS=$(LDFLAGS)

RM=rm -f

TARGET ?= lispy
SRC_DIRS ?= src
INC_DIRS ?= include

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(addsuffix .o,$(basename $(SRCS)))

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) $(CFLAGS)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
