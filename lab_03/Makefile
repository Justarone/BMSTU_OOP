CC = g++
INCLUDE_DIR = include/
BINARIES = $(patsubst src/%.cpp,bin/%.o, $(wildcard src/*.cpp))
GTK_FLAGS = `pkg-config gtkmm-3.0 --libs --cflags`
COMPILE_FLAGS = -Wall -g -Werror

.PHONY: all test clean
all: app.exe

app.exe: $(BINARIES)
	$(CC) $^ -o $@ $(GTK_FLAGS) 

bin/%.o: src/%.cpp
	mkdir -p bin
	$(CC) -c -o $@ $(GTK_FLAGS) $(COMPILE_FLAGS) $^ -I$(INCLUDE_DIR)

clean:
	rm -rf bin/ app.exe

# g++ main.cpp -o app.exe `pkg-config gtkmm-3.0 --cflags --libs`
