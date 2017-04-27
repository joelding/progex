# reference: https://gcc.gnu.org/ml/gcc-help/2004-01/msg00225.html
# the effect of -mwindows: 
# 1. add -lgdi32 and -lcomdlg32 to the list of default libraries
# 2. pass --subsystem windows to the linker.
# -Wl,--subsystem,windows passes `--subsystem=windows' to the linker.

CC=gcc
LD=ld
CFLAGS=-mwindows -Wall
#LDFLAGS=--subsystem=windows -lgdi32 -lcomdlg32 -luser32 -lcomctl32
unicode.exe: main.o
	$(CC) $(CFLAGS) -o $@ $<
#	$(LD) $(LDFLAGS) -o $@ $<
main.o: main.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f *exe *o