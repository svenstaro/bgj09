.PHONY: web run default clean clang webrun

default:
	mkdir -p build
	cd build; cmake ..; make -j

run:
	build/bgj09

web:
	mkdir -p build-web
	cd build-web; /usr/lib/emscripten/emcmake cmake ..; make -j

webrun:
	cd build-web; python -m http.server

clean:
	rm -rf build
	rm -rf build-web
