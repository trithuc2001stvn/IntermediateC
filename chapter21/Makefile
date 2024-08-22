# CH21: Makefile
GCC = gcc
CFLAGS = -g -Wall -Wshadow
VALGRIND = valgrind --tool=memcheck --verbose --log-file=valog
SRCS = treeinsert.c treedelete.c treeprint.c
SRCS += treedestroy.c treemain.c treesearch.c
OBJS = $(SRCS:%.c=%.o)

tree: $(OBJS)
	$(GCC) $(CFALGS) $(OBJS) -o $@
	./tree
	$(VALGRIND) ./tree
	grep "ERROR SUMMARY" valog

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean: 
	/bin/rm -f *.o tree valog
