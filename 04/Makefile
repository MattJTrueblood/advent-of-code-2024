.PHONY: build run

build:
	@echo "Building..."
	g++-11 -std=c++17 -o solution solution.cpp ../utils/util.cpp -I../utils

run:
	@if [ -z "$(file)" ]; then \
		echo "Error: 'file' argument missing. Usage: make run file=somefile.txt"; \
	else \
		./solution $(file); \
	fi
