.PHONY: clean web run
CXX = g++
CXXFLAGS = -g -Wall -Werror -Wextra -pedantic -std=c++14 $(shell sdl2-config --cflags)
LIBS =  $(shell sdl2-config --libs) -lSDL2_mixer -lSDL2_image
EMXX = em++

FILES = $(wildcard src/*)

all: bgj09

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) -c -o $@ $<

bgj09.bin: $(patsubst %.cpp, %.o, $(FILES))
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $+

run: bgj09.bin
	./bgj09.bin

web:
	source /etc/profile.d/emscripten.sh; $(EMXX) $(CXXFLAGS) -o index.html $(patsubst %.cpp, %.o, $(FILES))

clean:
	rm -f *.o *.bin
