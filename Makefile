CXX     	:= c++
CXXFLAGS  	:= -g -Wall
LDFLAGS  	:=
LDLIBS		:= 
SRC		  	:= src
BIN 		:= bin
TARGET    	:= pianoImac
INCLUDE   	:= -Iinc/
OBJECTS 	:=  $(wildcard src/*.cpp)

ifdef ComSpec
    RM			= del /F /Q
	CXXFLAGS 	+= -static-libgcc -static-libstdc++
else
    RM			= rm -f
	CXXFLAGS 	+= -std=c++11 
endif


.PHONY: all build clean

all: build $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(BIN)/$(TARGET) $(OBJECTS) $(LDLIBS)

clean:
	$(RM) *.o
