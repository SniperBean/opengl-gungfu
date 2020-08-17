all: builds run

init:
	mkdir -p build; \
	cd build; \
    cmake .. -DCMAKE_TOOLCHAIN_FILE="${VCPKG}/scripts/buildsystems/vcpkg.cmake"

builds:
	cmake --build build -ferror-limit=0

run:
	./build/main

clean:
	rm -rf build
