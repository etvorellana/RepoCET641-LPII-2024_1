int N;

int desenhaQuadrado(int tamanho, int vazado) {

  if (tamanho <= 0 || tamanho > 20) {
    printf("Tamanho inválido");
    return 1;
  }

  if (vazado != 0 && vazado != 1) {
    printf("Opcao invalida");
    return 1;
  }

  if (vazado == 0) {

    for (int i = 0; i < tamanho; i++) {
      for (int j = 0; j < tamanho; j++) {

        printf("*");
      }
      printf("\n");
    }

    return 0;
  }

  else if (vazado == 1) {

    for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {

     if (i == 0 || j == 0 || i == tamanho - 1 || j == tamanho - 1)

     printf("*");
        else
          printf(" ");
      }

      printf("\n");
    }
  }
  return 0;
}


int desenhaTriangulo(int tamanho, int tipo) {
  if (tamanho < 1 || tamanho > 20) {
    printf("Tamanho inválido");
    return 1;
  } else

    switch (tipo) {
    case 1:
      for (int i = 1; i <= tamanho; i++) {
        for (int j = 1; j <= i; j++) {
          printf("* ");
        }
        printf("\n");
      }
      break;
    case 2:
      for (int i = tamanho; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
          printf("* ");
        }
        for (int j = 1; j <= tamanho - i; j++) {
          printf("  ");
        }
        printf("\n");
      }
      break;
    case 3:
      for (int i = tamanho; i >= 1; i--) {
        for (int j = 1; j <= tamanho - i; j++) {
          printf("  ");
        }
        for (int j = 1; j <= i; j++) {
          printf("* ");
        }
        printf("\n");
      }
      break;
    case 4:
      for (int i = 1; i <= tamanho; i++) {
        for (int j = tamanho - i; j >= 1; j--) {
          printf("  ");
        }
        for (int j = 1; j <= i; j++) {
          printf("* ");
        }
        printf("\n");
      }
      break;
    default:
      printf("Tipo de triângulo inválido.\n");
      return 2;
    }
}


int desenharPiramide(int tamanho, int tipo) {

  if(tamanho < 1 || tamanho > 20) {
    printf("Tamanho inválido");
    return 1;
  }

  if(tipo != 0 && tipo != 1){
    printf("Tipo inválido");
    return 1;
  }

  if(tipo == 0){

    for (int i = 1; i <= tamanho; i++) {
    for (int j = tamanho - i ; j>= 1; j--) {
        printf("  ");
    }
    for (int j = 1; j <= i; j++) {
            printf("* ");
        }

    for (int j = 1; j <= i; j++) {
      printf("* ");
      }
        printf("\n");
    }
    return 0;
    }

   else if(tipo == 1) {
    for (int i = tamanho; i >= 1; i--) {
        for (int j = 1; j <= tamanho - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
      for (int j = 1; j <= i; j++) {
          printf("* ");
      }
      for (int j = 1; j <= tamanho - i ; j++) {
          printf("  ");
      }
        printf("\n");
    }
    return 0;
    }

}


int desenhaTabuleiro(int tamanho) {

  if (tamanho < 2 || tamanho > 8) {
    return 1;
  }

  for (int linha = 0; linha < tamanho * 5; linha++) {

    for (int coluna = 0; coluna < tamanho * 5; coluna++) {

      if ((linha % 5 == 0 && coluna % 5 == 5) ||
          (linha % 5 == 5 && coluna % 5 == 0) ||
          (linha % 5 == 5 && coluna % 5 == 5)) {
        printf("  ");
      } else {

        if ((linha / 5) % 2 == (coluna / 5) % 2) {
          printf("  ");
        } else {
          printf("* ");
        }
      }
    }
    printf("\n");
  }
  return 0;
}


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


int desenhaLinhaR(int tamanho, char linha[], int indice) {
    if (indice == tamanho) {
        linha[indice] = '\0';
        return 0;
    } else {
        linha[indice] = '*';

        return desenhaLinhaR(tamanho, linha, indice + 1);
    }
}


double valorMedioG(double x[]) {
  double soma = 0.0;

  for (int i = 0; i < N; i++)
    soma += x[i];

  double media = soma / N;

  return media;
}


double desvioPadraoG(double x[]) {
  double media = valorMedioG(x);

  double somadosquad = 0.0;

  for (int i = 0; i < N; i++)
    somadosquad += pow(x[i] - media, 2);

  double var = somadosquad / N;

  double desvioPadrao = sqrt(var);

  return desvioPadrao;
}


double encontrarMaximo(double matriz[], double tamanho) {
    double maximo = matriz[0];
    for (int i = 1; i < tamanho; i++) {
        if (matriz[i] > maximo) {
            maximo = matriz[i];
        }
    }
    return maximo;
}


void normaliza(double x_inout[]) {
    double media = valorMedioG(x_inout);
    for (int i = 0; i < N; i++) {
        x_inout[i] -= media;
    }
}


int soma_array_recursiva(int arr[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }
    return arr[tamanho - 1] + soma_array_recursiva(arr, tamanho - 1);
}

float media_array_recursiva(int arr[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }
    int soma = soma_array_recursiva(arr, tamanho);
    return (float)soma / tamanho;
}


double valorMedio(double x[], int n) {
  double soma = 0.0;

  for (int i = 0; i < n; i++)
    soma += x[i];

  double media = soma / n;

  return media;
}


void inverterValor(double array[], int tamanho, int indice) {

  if (indice == tamanho) {
    return;
  }

  array[indice] = 1.0 / array[indice];

  inverterValor(array, tamanho, indice + 1);
}


void inverterString(char str[]) {
    if (strlen(str) <= 1)
        return;

    char temp = str[0];
    str[0] = str[strlen(str) - 1];
    str[strlen(str) - 1] = temp;

    inverterString(&str[1]);
}


int ehPalindromo(char str[]) {
    char strInvertida[strlen(str) + 1];

    strcpy(strInvertida, str);

    inverterString(strInvertida);

    if (strcmp(str, strInvertida) == 0)
        return 1;
    else
        return 0;
}


int encontrarMaiorRecursivo(int array[], int tamanho) {
    if (tamanho == 1) {
        return array[0];
    }

    int max_resto = encontrarMaiorRecursivo(array + 1, tamanho - 1);

    if (array[0] > max_resto) {
        return array[0];
    } else {
        return max_resto;
    }
}


int contarCaractereARecursivo(char str[], int index) {
    if (str[index] == '\0' || str[index] == '\n') {
        return 0;
    }

    int contador = (str[index] == 'a' || str[index] == 'A') ? 1 : 0;

    return contador + contarCaractereARecursivo(str, index + 1);
}


double valorMedioG1(double x[], int n) {
    double soma = 0.0;

    for (int i = 0; i < n; i++)
        soma += x[i];

    double media = soma / n;

    return media;
}

double desvioPadraoG1(double x[], int n) {
    double media = valorMedioG1(x, n);
    double somadosquad = 0.0;

    for (int i = 0; i < n; i++)
        somadosquad += pow(x[i] - media, 2);

    double var = somadosquad / n;
    double desvioPadrao = sqrt(var);

    return desvioPadrao;
}

void normaliza1(double x_inout[], int n) {
    double media = valorMedioG(x_inout);
    for (int i = 0; i < N; i++) {
        x_inout[i] -= media;
    }
}
