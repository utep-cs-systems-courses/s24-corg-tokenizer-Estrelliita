# compiler flags.  -g for debug, -O3 for optimization

CFLAGS=-g -O3


all: tokenizer

# include file dependencies

history.o: history.h
tokenizer.o: tokenizer.h

# target and prerequisites
tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

#Compile uimain.c 
uimain.o: uimain.c tokenizer.h history.h
	cc -o $@ -c $< $(CFLAGS)

# deletes files generated by compilation

clean:
	rm -f *.o tokenizer

# Run everything
run:

	./tokenizer
