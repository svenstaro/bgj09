.PHONY: clean web
CXX = g++
CXXFLAGS = -g -Wall -Werror -Wextra -pedantic -std=c++14
LIBS = -lSDL2 -lSDL2_mixer -lSDL2_image
EMXX = em++

FILES = $(wildcard src/*)

all: bgj09

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bgj09: $(patsubst %.cpp, %.o, $(FILES))
	$(CXX) $(CXXFLAGS) -o $@ $+

web:
	$(EMXX) $(CXXFLAGS) -o index.html $(patsubst %.cpp, %.o, $(FILES))

clean:
	rm -f *.o core.*
