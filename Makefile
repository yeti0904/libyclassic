c   = gcc
src = $(wildcard src/*.c)
arg = -shared -fPIC
out = bin/libyclassic.so

build:
	$(c) $(src) $(arg) -o $(out)

example:
	$(c) example/*.c -lyclassic -o example/bin

install:
	cp $(out) /usr/lib/
	mkdir -p /usr/include/yclassic
	cp src/*.h /usr/include/yclassic/