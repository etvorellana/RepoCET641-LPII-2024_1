#include <stdio.h>

/*
Este programa define duas funções principais:
1. desenhaLinha: preenche um array com asteriscos até um tamanho especificado e termina com '\0'.
2. desenhaTriangulo: desenha triângulos de diferentes tipos, utilizando a função desenhaLinha para gerar as linhas.

Modificações feitas para integrar desenhaLinha na função desenhaTriangulo:
- Cada tipo de triângulo utiliza desenhaLinha para simplificar a criação de linhas de asteriscos.
- O preenchimento e alinhamento dos triângulos são ajustados com espaços para manter a forma correta.

Função desenhaTriangulo:
- Tipo 1: Triângulo retângulo com linhas de asteriscos incrementadas.
- Tipo 2: Triângulo retângulo invertido.
- Tipo 3: Triângulo retângulo invertido e espelhado.
- Tipo 4: Triângulo retângulo alinhado à direita.

Uso de printf com espaçamento para alinhar asteriscos e formar triângulos adequados aos tipos 3 e 4.
*/

// Função que preenche um array com asteriscos e termina com '\0'
int desenhaLinha(int tamanho, char linha[]) {
    if (tamanho < 1 || tamanho > 20) {
        return 1;
    }
    for (int i = 0; i < tamanho; i++) {
        linha[i] = '*';
    }
    linha[tamanho] = '\0';
    return 0;
}

// Função que desenha um triângulo de acordo com o tipo e tamanho especificado
int desenhaTriangulo(int tamanho, int tipo) {
    char linha[21]; // Buffer para armazenar uma linha de asteriscos
    if (tamanho < 1 || tamanho > 20) {
        printf("Tamanho inválido\n");
        return 1;
    }

    switch (tipo) {
    case 1:
        for (int i = 1; i <= tamanho; i++) {
            if (desenhaLinha(i, linha) == 0) {
                printf("%s\n", linha);
            }
        }
        break;
    case 2:
        for (int i = tamanho; i >= 1; i--) {
            if (desenhaLinha(i, linha) == 0) {
                printf("%s\n", linha);
            }
        }
        break;
    case 3:
        for (int i = tamanho; i >= 1; i--) {
            printf("%*s", 2 * (tamanho - i), "");
            if (desenhaLinha(i, linha) == 0) {
                printf("%s\n", linha);
            }
        }
        break;
    case 4:
        for (int i = 1; i <= tamanho; i++) {
            printf("%*s", 2 * (tamanho - i), "");
            if (desenhaLinha(i, linha) == 0) {
                printf("%s\n", linha);
            }
        }
        break;
    default:
        printf("Tipo de triângulo inválido.\n");
        return 2;
    }
    return 0;
}

int main() {
    int tamanho, tipo;
    printf("Digite a altura do triângulo: ");
    scanf("%d", &tamanho);
    printf("Escolha o tipo de triângulo (1-4):\n");
    printf("1 - Tipo 1\n");
    printf("2 - Tipo 2\n");
    printf("3 - Tipo 3\n");
    printf("4 - Tipo 4\n");
    scanf("%d", &tipo);

    if (desenhaTriangulo(tamanho, tipo) != 0) {
        printf("Erro ao desenhar o triângulo.\n");
    }

    return 0;
}
