CC = gcc
CFLAGS = -Wall -g
#CFLAGS += `pkg-config --cflags gstreamer-0.10`
CFLAGS += `pkg-config --cflags gstreamer-1.0`
#LDFLAGS = `pkg-config --libs gstreamer-0.10`
LDFLAGS = `pkg-config --libs gstreamer-1.0`
TARGETS = main_04011630
all : $(TARGETS)

main_04011630 : main_04011630.o
	$(CC) -o $@ $< $(LDFLAGS)

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o $(TARGETS)
