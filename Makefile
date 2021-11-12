# Temp until I make a cmakelist.txt
ifndef VERBOSE
.SILENT:
endif

SUBDIRS = obj bin # Auto generated directories

CFLAGS_DEBUG 	= -Wall -Werror -g3 -std=c++17
CFLAGS_RELEASE 	= -Wall -Werror -std=c++17
CC				= g++

all: test release debug

test: 

release: main.cpp
	mkdir -p release
	$(CC) $(CFLAGS_RELEASE) -o release/gl-arm -I. $^
	echo done -- made $@/gl-arm

debug: main.cpp
	mkdir -p debug
	$(CC) $(CFLAGS_DEBUG) -o debug/gl-arm -I. $^
	echo done -- made $@/gl-arm

.PHONY: all clean subdirs $(SUBDIRS)

#####################################################################
# Source Files
#####################################################################

subdirs: $(SUBDIRS)

$(SUBDIRS):
	mkdir -p $@

clean:
	rm -rf obj/
	rm -rf bin/
	rm -rf release/
	rm -rf debug/
	rm -rf out/*
	echo done -- cleaned!
