# Nome do projeto
PROJ_NAME = labirinto

# Arquivos .c
C_SOURCE = $(wildcard ./source/*.c)

# Arquivos objeto
OBJ = $(subst source,objects,$(C_SOURCE:.c=.o))

# Compilador
CC = gcc

# Flags para o compilador
CC_FLAGS = -c         \
           -W         \
           -Wall      \
           -pedantic

# Comando utilizado como target do clean
RM = rm -rf

#########################
# Compilação e linkagem #
#########################
all: objFolder $(PROJ_NAME)

# Linka os arquivos objeto em um executável
$(PROJ_NAME): $(OBJ)
	@ echo 'Construindo o binário usando o linker GCC: $@'
	$(CC) $^ -o $@
	@ echo 'Binário pronto!: $@'
	@ echo ' '

# Regra para compilar cada arquivo .c em um .o
./objects/%.o: ./source/%.c
	@ echo 'Compilando o target usando o GCC: $<'
	$(CC) $(CC_FLAGS) $< -o $@
	@ echo ' '

# Compila main.o
./objects/main.o: ./source/main.c $(H_SOURCE)
	@ echo 'Compilando o target usando o GCC: $<'
	$(CC) $(CC_FLAGS) $< -o $@
	@ echo ' '

# Cria a pasta objects se não existir
objFolder:
	@ mkdir -p objects

# Limpeza dos arquivos objeto e binário
clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean