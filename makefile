##############################################################################
# Makefile
##############################################################################

BUILD_DIR := build
RELEASE_DIR := release

THREADS := 1

.PHONY: clean clean-all all run test release
.SILENT: clean clean-all all run test release

all:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && \
	cmake .. && \
	cmake --build . --parallel $(THREADS)

# 	cp $(BUILD_DIR)/Debug/_cubik_python.pyd $(BUILD_DIR)/_cubik_python.pyd
# 	cp -r $(BUILD_DIR)/tests/solutions $(BUILD_DIR)/tests/Debug

release:
	mkdir -p $(RELEASE_DIR) && cd $(RELEASE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && \
	cmake --build . --config Release --parallel $(THREADS)

# 	cp $(RELEASE_DIR)/Release/_cubik_python.pyd $(RELEASE_DIR)/_cubik_python.pyd
# 	cp -r $(RELEASE_DIR)/tests/solutions $(RELEASE_DIR)/tests/Release

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

clean-all:
	rm -rf $(BUILD_DIR)
	rm -rf $(RELEASE_DIR)
