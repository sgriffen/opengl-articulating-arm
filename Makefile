ifndef VERBOSE
.SILENT:
endif

SUBDIRS = obj bin # Auto generated directories

$(info $(shell mkdir -p $(SUBDIRS))) # Quietly create directories anytime make is ran

CFLAGS_RELEASE 	= -std=c++17 -Wall -Werror
CFLAGS_DEBUG 	= $(CFLAGS_RELEASE) -g3
CC				= g++
LIBS			= -lGL -lglut -lm -lGLU

all: release debug

release: main.cpp
	mkdir -p release
	$(CC) $(CFLAGS_RELEASE) -o release/gl-arm -I. $^ $(LIBS)
	echo done -- made $@/gl-arm

debug: main.cpp
	mkdir -p debug
	$(CC) $(CFLAGS_DEBUG) -o debug/gl-arm -I. $^ $(LIBS)
	echo done -- made $@/gl-arm

.PHONY: all

#####################################################################
# Source Files
#####################################################################

clean:
	rm -rf obj/
	rm -rf bin/
	rm -rf release/
	rm -rf debug/
	rm -rf out/*
	echo done -- cleaned!
