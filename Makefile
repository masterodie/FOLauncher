VERSION = 0.0.1
CC = /mingw32/bin/clang++
CFLAGS = -Wall -g -DVERSION=\"$(VERSION)\"
LDFLAGS = -static -static-libstdc++

OBJ = Application.o CommandlineInterface.o main.o

all: $(OBJ)
	$(CC) $(CFLAGS) -o FalloutLauncher.exe $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


