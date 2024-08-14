# CH17: Makefile
GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = person5.c personconstruct.c persondestruct.c personprint.c
OBJS = $(SRCS:%.c=%.o)
person: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o person5

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	/bin/rm -f *.o person5 a.out *~ *bak output*
