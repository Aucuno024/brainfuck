.PHONY: all clean fclean make_dir display

CC      = gcc
SRCDIR  = src
OBJDIR  = obj
EXECDIR = bin
DECIMAL = ast.o
ASCII   = ast_ascii.o
SRCS    = $(wildcard $(SRCDIR)/*.c)
ALL_OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS    = $(filter-out $(OBJDIR)/$(ASCII), $(ALL_OBJS))
OBJSD   = $(filter-out $(OBJDIR)/$(DECIMAL), $(ALL_OBJS))
CFLAGS   = -Wall -g
CPPFLAGS = -Iinclude

all: make_dir $(EXECDIR)/brainfuck $(EXECDIR)/brainfuckd

display:
	@echo "Objets pour brainfuck : $(OBJS)"
	@echo "Objets pour brainfuckd : $(OBJSD)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(EXECDIR)/brainfuck: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXECDIR)/brainfuckd: $(OBJSD)
	$(CC) -o $@ $^ $(LDFLAGS)

make_dir:
	@mkdir -p $(OBJDIR) $(EXECDIR)

clean:
	@echo "Suppression des objets"
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Suppression des binaires"
	rm -rf $(EXECDIR)
