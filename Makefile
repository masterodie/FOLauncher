VERSION = 0.0.1
CC = /mingw32/bin/g++
CFLAGS = -Wall -Wextra -g -Iinclude -DVERSION=\"$(VERSION)\"
LDFLAGS = -static -static-libstdc++

OBJ = lib/Application.o lib/CommandlineInterface.o main.o

all: $(OBJ)
	$(CC) $(CFLAGS) -o dist/FalloutLauncher.exe $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

fo3_dummy:
	$(CC) $(CFLAGS) -o dist/Fallout3.exe ../helloworld.cpp
