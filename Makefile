##############################################################################
# Makefile
##############################################################################

MAKEFLAGS += --no-print-directory

BUILD_DIR := build
RELEASE_DIR := release

THREADS := 1

.PHONY: clean clean-all all run test release wheel
.SILENT: clean clean-all all run test release wheel

all:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && \
	cmake -DENABLE_TESTING=ON .. && \
	cmake --build . --parallel $(THREADS)

	cp $(BUILD_DIR)/_cubik.so ./cubik
	cp $(BUILD_DIR)/cubik.py ./cubik

	cp $(BUILD_DIR)/_cubik_moves.so ./cubik
	cp $(BUILD_DIR)/moves.py ./cubik

release:
	mkdir -p $(RELEASE_DIR) && cd $(RELEASE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && \
	cmake --build . --config Release --parallel $(THREADS)

wheel:
	./wheel.sh

run:
	cd $(BUILD_DIR)/Debug && ./cubik.exe

test:
	cd build/tests && ./cubik_tests
#	cd build/tests/Debug && ./cubik_tests.exe

clean:
	rm -f src/a.exe
	mv $(BUILD_DIR)/_deps _deps
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	mv _deps $(BUILD_DIR)/_deps

	rm -rf $(RELEASE_DIR)

	rm -f ./cubik/*.so
	rm -f ./cubik/cubik.py

clean-all:
	rm -rf $(BUILD_DIR)
	rm -rf $(RELEASE_DIR)
