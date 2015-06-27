VERSION = 0.0.1
CC = /mingw32/bin/g++
CFLAGS = -Wall -Wextra -g -DVERSION=\"$(VERSION)\"
LDFLAGS = -static -static-libstdc++

OBJ = Application.o CommandlineInterface.o main.o

all: $(OBJ)
	$(CC) $(CFLAGS) -o FalloutLauncher.exe $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

fo3_dummy:
	$(CC) $(CFLAGS) -o Fallout3.exe ../helloworld.cpp

clean:
	rm *.o *.exe *.out

