CC = gcc

CFLAGS = -Wall -g
#CFLAGS += `pkg-config --cflags gstreamer-0.10`
CFLAGS += `pkg-config --cflags gstreamer-1.0`
#CFLAGS += `pkg-config --cflags glib-2.0`

#LDFLAGS = `pkg-config --libs gstreamer-0.10`
LDFLAGS = `pkg-config --libs gstreamer-1.0`
#LDFLAGS += `pkg-config --libs glib-2.0`

SRCS = $(wildcard *.c)
TGTS = $(basename $(SRCS))

all: $(TGTS)

% : %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) 

clean :
#	rm -f *.o $(TARGETS)
	rm -f *.o $(TGTS)
