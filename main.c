#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(void) {
    char input[100];
    char *fim;
    long opcao;

    const char *menu[] = {"Cadastro de veiculos", "Cadastro de clientes", "Cadastro de servicos", "Cadastro de funcionarios", "Sair"};

    while (1) {
      printf("===================================\n");
      printf("        MENU DE OPCOES\n");
      printf("===================================\n\n");
      
      for(int i = 1; i < 6; i++) {
        printf("%d - %s\n", i, menu[i-1]);
      }

      printf("Escolha uma opção: ");

      if (scanf("%99s", input) != 1) {
        break;
      }

      errno = 0;
      opcao = strtol(input, &fim, 10);

      if (fim == input || *fim != '\0' || errno == ERANGE ||
          opcao < 1 || opcao > 5) {
        printf("Opcao invalida! Digite uma opcao entre 1 e 5.\n");
        continue;
      }

      printf("Voce escolheu a opcao %ld\n", opcao);
      
      if(opcao == 5) {
        printf("Saindo do programa...\n");
        break;
      }
    }

    return 0;
}
