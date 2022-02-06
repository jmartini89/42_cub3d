NAME = lodev
CC = clang++
CFLAGS = $(HEADERS)
HEADERS = -I./inc
DEBUG = -g
DEBUG_ADDR = -fsanitize=address
RM = rm -f

SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = lib

SOURCES = $(shell find $(SRCDIR) -name "*.cpp")
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/$(NAME)
HEADERS_UPD = $(shell find inc -name "*.hpp")

all : $(TARGET)

$(NAME) : all

clean :
	@$(RM) $(TARGET) $(OBJECTS)
	@echo "\033[33m"$(NAME)" clean completed\033[0m"

fclean :
	@rm -rf bin obj

re : clean all

#Link
$(TARGET) : $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ $^ -lSDL
	@echo "\033[32m"$@" compiled successfully\033[0m"

#Compile
$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS_UPD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[34m"$<" compiled successfully\033[0m"