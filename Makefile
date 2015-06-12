.PHONY: clean web run
CXX = g++
CXXFLAGS = -g -Wall -Werror -Wextra -pedantic -std=c++14
LIBS =  $(shell sdl2-config --libs) -lSDL2_mixer -lSDL2_image
EMXX = em++
EMXXFLAGS = -Oz -s USE_SDL=2

FILES = $(wildcard src/*.cpp)

all: bgj09.bin

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) -c -o $@ $<

bgj09.bin: $(patsubst %.cpp, %.o, $(FILES))
	$(CXX) $(CXXFLAGS) $(shell sdl2-config --cflags) $(LIBS) -o $@ $+

run: bgj09.bin
	./bgj09.bin

web:
	source /etc/profile.d/emscripten.sh; $(EMXX) $(CXXFLAGS) $(EMXXFLAGS) -o index.html $(wildcard src/*.cpp)

clean:
	rm -f *.o *.bin
