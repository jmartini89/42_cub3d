NAME = cub3d
CC = gcc
CFLAGS = $(CWARN) $(HEADERS)
CWARN = -Wall -Werror -Wextra
HEADERS = -I./inc $(addprefix -I./, $(LIBPATH))
DEBUG = -g
DEBUG_ADDR = -fsanitize=address
RM = rm -f

SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = lib

SOURCES = $(shell find $(SRCDIR) -name "*.c")
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/$(NAME)

LIB = libft #mlx
LIB_BIN = libft.a #libmlx.dylib
LIB_BIN_PATH = $(addprefix $(LIBDIR)/, $(LIB_BIN))
LIBPATH = $(addprefix $(LIBDIR)/, $(LIB))

INCLUDE = -Llib -lft #libmlx.dylib


all : $(TARGET)

$(NAME) : all

$(LIB_BIN_PATH) :
	@make -s -C $(LIBDIR) -f lib.mk

clean :
	@$(RM) $(TARGET) $(OBJECTS)
	@echo "\033[33m"$(NAME)" clean completed\033[0m"

fclean : clean
	@make -s clean -C $(LIBDIR) -f lib.mk
	@$(RM) -r $(OBJDIR) $(BINDIR)
	@echo "\033[33mfull clean completed\033[0m"

re : clean all

debug : CFLAGS += $(DEBUG)
debug : all
	@echo "\033[31mDEBUG\033[0m"

leak : CFLAGS += $(DEBUG) $(DEBUG_ADDR)
leak : all
	@echo "\033[31mDEBUG ADDRESS\033[0m"

#Link
$(TARGET) : $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)
	@echo "\033[32m"$@" compiled successfully\033[0m"

#Compile
$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.c | $(LIB_BIN_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[34m"$<" compiled successfully\033[0m"

# TODO INCLUDE DEPENDANCIES