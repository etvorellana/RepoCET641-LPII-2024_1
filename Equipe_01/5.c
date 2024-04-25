#include <stdio.h>
#include <stdlib.h>

// Função que preenche um array com asteriscos de acordo com o tamanho especificado

int desenhaLinha(int tamanho, char linha[]) {
  
    // Verifica se o tamanho é válido
  
    if (tamanho < 1 || tamanho > 20) {
        return 1;
      // Retorna 1 se o tamanho for inválido
    }

    // Preenche o array com asteriscos até o tamanho especificado
  
    for (int i = 0; i < tamanho; i++) {
        linha[i] = '*';
    }

    // Adiciona o caractere nulo no final para terminar a string
  
    linha[tamanho] = '\0';

    return 0; 
  // Retorna 0 indicando sucesso
}

int main() {
    char linha[21]; 
  // Declara um array com tamanho suficiente para o máximo de asteriscos + '\0'
  
    int resultado;
    int tamanho;

    // Solicita ao usuário o tamanho da linha de asteriscos
  
    printf("Digite o tamanho da linha de asteriscos (1-20): ");
    scanf("%d", &tamanho);

    // Chama a função desenhaLinha
  
    resultado = desenhaLinha(tamanho, linha);

    // Verifica o resultado da função
  
    if (resultado == 0) {
        printf("Linha desenhada: %s\n", linha);
      
      // Exibe a linha se for bem-sucedido
      
    } else {
        printf("Erro: tamanho deve ser entre 1 e 20.\n"); 
      
      // Informa o erro se o tamanho for inválido
      
    }

    return 0;
}
