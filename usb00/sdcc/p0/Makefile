# MAKEFILE 
#
# reference: https://sourceforge.net/p/sdcc/mailman/message/11632749/
#

CC = sdcc 

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.rel,$(SRCS))

VERBOSE = --verbose
TARGET = -mmcs51
INCLUDES = -I.
OPTIMIZE = --opt-code-size --no-xinit-opt
CFLAGS = -c $(VERBOSE) $(TARGET) $(INCLUDES) $(OPTIMIZE)
LFLAGS = $(VERBOSE) $(TARGET)
LIBS = 
RM = rm

all : rom.hex

rom.hex : $(OBJS)
	$(CC) -o $(patsubst %.hex,%.ihx,$@) $(LFLAGS) $(LIBS) $^ 
	packihx rom.ihx > rom.hex

%.rel : %.c
	$(CC) $(CFLAGS) $< 

clean:
	$(RM) -f *.rel *.s *.asm *.lst *.sym *.rst *.txt *.mem *.map *.lk *.ihx *.hex
