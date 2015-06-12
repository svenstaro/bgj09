.PHONY: web run

default:
	mkdir -p build
	cd build; cmake ..; make -j

run:
	build/bgj09

web:
	mkdir -p build-web
	cd build-web; /usr/lib/emscripten/emcmake cmake ..; make -j

clean:
	rm -rf build
	rm -rf build-web
