#include <stdio.h>
#define TAMANHO_CONTATOS 100

struct Contato {
    char nome[25];
    char telefone[17];
    char tipoDeContato[20];
};

int main() {
    int opcao, id = 0;
    struct Contato c[TAMANHO_CONTATOS];
    while(opcao != 6) {
        printf("Bem-vindo(a) à Agenda de Contatos\n");
        printf("3--------------------------------3 \n");
        printf("[1] - Adicionar novo contato \n");
        printf("[2] - Excluir um contato \n");
        printf("[3] - Alterar um contato \n");
        printf("[4] - Listar todos os contatos existentes\n");
        printf("[5] - Localizar um contato\n");
        printf("[6] - Sair \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // Informar o nome do novo contato
                printf("Digite o nome do novo contato: \n");
                scanf("%20s", &(c[id].nome));

                // informar o telefone do novo contato
                printf("Digite o telefone do novo contato: \n");
                scanf("%17s", &(c[id].telefone));

                printf("Digite o tipo de contato disponiveis: \n");
                printf("[1] - Pessoal \n");
                printf("[2] - Trabalho \n");
                scanf("%20s", &(c[id].tipoDeContato));

                printf("3--------------------------------3 \n");
                printf("Contato adicionado com sucesso!\n");
                printf("3--------------------------------3\n");

                id++;
                break;
            case 2:
                // excluir um contato
                break;
            case 3:
                // alterar um contato
                break;
            case 4:
                printf("Lista de contatos\n");
                for(int i = 0; i < id; i++) {
                    printf("Id: %d\n", id);
                    printf("Nome: %20s\n", &(c[i].nome));
                    printf("Telefone: %17s\n", &(c[i].telefone));
                    printf("Tipo de contato: %20s\n", &(c[i].tipoDeContato));
                }
                break;
            case 5:
                // localizar um contato
                break;
            case 6:
                printf("Programa encerrado!\n");
                break;
            default: 
                printf("Erro!");
                break;
        }
    }

    return 0;
}