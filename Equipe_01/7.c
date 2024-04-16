#include <stdio.h>

// Função recursiva que preenche um array com asteriscos e termina com '\0'
int desenhaLinhaR(int tamanho, char linha[], int indice) {
    // Caso base: se o índice atingiu o tamanho, termina a string com '\0' e retorna sucesso
    if (indice == tamanho) {
        linha[indice] = '\0'; // Finaliza a string
        return 0; // Retorna sucesso
    } else {
        linha[indice] = '*'; // Coloca o asterisco na posição atual
        // Chamada recursiva para a próxima posição
        return desenhaLinhaR(tamanho, linha, indice + 1);
    }
}

// Função que desenha um triângulo de acordo com o tipo e tamanho especificado
int desenhaTriangulo(int tamanho, int tipo) {
    if (tamanho < 1 || tamanho > 20) {
        printf("Tamanho inválido\n");
        return 1;
    }

    // Baseado no tipo de triângulo, chama a função desenhaLinhaR com os parâmetros apropriados
    for (int i = 1; i <= tamanho; i++) {
        char linha[tamanho + 1]; // Buffer para armazenar uma linha de asteriscos

        // Limpa a linha antes de desenhar
        for (int j = 0; j < tamanho; j++) linha[j] = ' ';

        int sucesso;
        switch (tipo) {
            case 1: // Triângulo retângulo
                sucesso = desenhaLinhaR(i, linha, 0);
                break;
            case 2: // Triângulo retângulo invertido
                sucesso = desenhaLinhaR(tamanho - i + 1, linha, 0);
                break;
            case 3: // Triângulo retângulo invertido espelhado
                sucesso = desenhaLinhaR(tamanho - i + 1, linha, 0); // Corrigido para usar índice 0
                break;
            case 4: // Triângulo retângulo alinhado à direita
                sucesso = desenhaLinhaR(i, linha, tamanho - i);
                break;
            default:
                printf("Tipo de triângulo inválido.\n");
                return 2;
        }
        // Se a linha foi desenhada com sucesso, imprime
        if (sucesso == 0) {
            printf("%s\n", linha);
        }
    }
    return 0;
}

int main() {
    int tamanho, tipo;
    printf("Digite a altura do triângulo: ");
    scanf("%d", &tamanho);
    printf("Escolha o tipo de triângulo (1-4):\n");
    printf("1 - Triângulo retângulo\n");
    printf("2 - Triângulo retângulo invertido\n");
    printf("3 - Triângulo retângulo invertido espelhado\n");
    printf("4 - Triângulo retângulo alinhado à direita\n");
    scanf("%d", &tipo);

    if (desenhaTriangulo(tamanho, tipo) != 0) {
        printf("Erro ao desenhar o triângulo.\n");
    }

    return 0;
}
