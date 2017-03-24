CC = clang
CFLAGS = -g -Wall

PROG = test
PROG1 = suggest

OBJDIR = objects
OBJS = $(OBJDIR)/test.o $(OBJDIR)/engine.o $(OBJDIR)/table.o $(OBJDIR)/levenshtein.o
OBJS1 = $(OBJDIR)/suggest.o $(OBJDIR)/engine.o $(OBJDIR)/table.o $(OBJDIR)/levenshtein.o

# ... and in the darkness bind them (er, link them)
$(PROG): $(OBJS) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)
 
$(PROG1): $(OBJS1) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS1) -o $(PROG1)

$(OBJDIR)/levenshtein.o:
	$(MAKE) -C levenshtein.c
	cp levenshtein.c/levenshtein.o $(OBJDIR)

# One rule to build them all...
$(OBJDIR)/%.o: %.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# $@ is a variable with the name of the file that caused the rule
# to run. We've got multiple .c files, and thus multiple .o files,
# so each one of the .c files will create a separate .o file.
# $< is the name of the first prerequisite (in this case the .c)
# file. So our recipe will expand to something like:
# 	$(CC) $(CFLAGS) -c -o myfile.o myfile.c

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROG) $(PROG1)