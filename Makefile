# name of the executable: sinewave
# rules: all, rm

# clean: delete the executable

# CC: the compiler to be used
# CFLAGS: -std=c++11
# RM: the program to delete files

CC = g++
CFLAGS = -std=c++11
RM = rm -f

all: sinewave

sinewave: main.cpp value_select.cpp wavetypes.cpp
	$(CC) $(CFLAGS) $^ -o $@
clean:
	$(RM) sinewave
.PHONY: sinewave all clean
