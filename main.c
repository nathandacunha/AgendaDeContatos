#include <stdio.h>

int main() {
    int opcao, idContato = 0;

    while(opcao != 6) {
        printf("Bem-vindo(a) à Agenda de Contatos\n");
        printf("[1] - Adicionar novo contato \n");
        printf("[2] - Excluir um contato \n");
        printf("[3] - Alterar um contato \n");
        printf("[4] - Listar todos os contatos existentes\n");
        printf("[5] - Localizar um contato\n");
        printf("[6] - Sair");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // lógica de adicionar um novo contato
                break;
            case 2:
                // excluir um contato
                break;
            case 3:
                // alterar um contato
                break;
            case 4:
                // listar todos os contatos
                break;
            case 5:
                // localizar um contato
                break;
            case 6:
                break;
            default: 
                printf("Erro!");
                break;
        }
    }

    return 0;
}