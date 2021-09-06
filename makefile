#
#
#
#

CC := g++ # Compilador
SRCDIR := src
BUILDDIR := build
LIBDIR := lib
TARGET := bin/paging-simulation.o

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)) $(wildcard lib/*.o)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS	:= -std=c++17 -Wall -Wextra -pedantic-errors # FLAGS de compilacao
LIB := -lpthread -pthread # Bibliotecas utilizadas
INC := -I include

# Variaveis do tipo executavel
BUILD := *.so

# Comando para limpar arquivo
RM := rm -rf

# Compila e executa o programa e depois apaga todos os arquivos .o e o
# executavel criado
#all: run clean

# Compila e executa o programa
$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)";
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<";
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# Apaga todos os arquivos .o e o executavel criado
clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)";
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: all clean
#------------------------------------------------------------------------------#
