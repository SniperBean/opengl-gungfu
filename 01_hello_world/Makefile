all: builds run

init:
	mkdir -p build; \
	cd build; \
    cmake .. -DCMAKE_TOOLCHAIN_FILE="/usr/local/Cellar/vcpkg/2020.06_1/libexec/scripts/buildsystems/vcpkg.cmake"

builds:
	cmake --build build -ferror-limit=0

run:
	./build/main

clean:
	rm -rf build
