c   = gcc
src = $(wildcard src/*.c)
arg = -shared -fPIC
out = bin/libyclassic.so

build:
	mkdir -p bin
	$(c) $(src) $(arg) -o $(out)

example: example/main.c
	$(c) example/main.c -lyclassic -o example/bin

install:
	cp $(out) /usr/lib/
	mkdir -p /usr/include/yclassic
	cp src/*.h /usr/include/yclassic/