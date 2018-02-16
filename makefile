MINGW_ROOT=$(MW_MINGW64_LOC)/bin
CC=$(MINGW_ROOT)/gcc
CFLAGS = -Wall -g
PRODUCT=circbuff
SRCS=main.c circbuff.c
OBJS = main.o circbuff.o
PREP = main.i circbuff.i

$(PRODUCT) : $(OBJS)
	$(CC) $(OBJS) -o $(PRODUCT).exe

%.i : %.c
	$(CC) -E $< -o $@

preprocess : $(PREP)

clean :
	del $(OBJS) $(PREP) $(PRODUCT).exe 