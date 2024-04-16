CC := gcc
CFLAGS := -std=c99 -Wall -lm
SRC :=

default:
	# para usar isso, coloque o valor de SRC para ser o arquivo que se quer rodar.
	# exemplo: make SRC=questao_01.c run
	exit 1

run:
	$(CC) $(SRC) $(CFLAGS) -o output.com
	./output.com

.PHONY: default run
