# Makefile for studiomdl
# Put from hlsdk-xash3d into hlsdk folder:
# engine/studio.h
# dlls/activity.h
# dlls/activitymap.h
MODULE = studiomdl

CC	?= gcc
CFLAGS	?= -O3 -pipe -DHAVE_TGMATH_H
LDFLAGS	?= -Wl,--no-undefined

SYS = $(shell $(CC) -dumpmachine)

ifneq (, $(findstring mingw, $(SYS)))
EXT = .exe
else
EXT =
endif

APP = $(MODULE)$(EXT)

SRC = 	bmpread.c \
	cmdlib.c \
	mathlib.c \
	scriplib.c \
	studiomdl.c \
	trilib.c \
	tristrip.c \
	write.c

INCLUDE = -I. \
	  -I../../common \
	  -I../../engine \
	  -I../../engine/common \
	  -I../../engine/common/imagelib \
	  -I../../public

LIBS = -lm

OBJS = $(SRC:%.c=%.o)

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(LDFLAGS) -o $(APP) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean

clean:
	$(RM) $(OBJS)
	$(RM) $(APP)
