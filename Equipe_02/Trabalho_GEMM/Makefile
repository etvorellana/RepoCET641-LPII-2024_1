CC := gcc
OUTPUT := out.com

CFLAGS := -Wall -std=c99 -pedantic -O3

questao1: aviso $(SRC)
	$(CC) -o questao1.com src/questao1.c src/common.c $(CFLAGS)
	./questao1.com

questao2: aviso $(SRC)
	$(CC) -o questao2.com src/questao2.c src/common.c $(CFLAGS)
	./questao2.com

aviso:
	@echo AVISO - Esse comando aqui está compilando com flags de otimização.

.PHONY: questao1 questao2 aviso run
