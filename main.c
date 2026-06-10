// importação de bibliotecas + variáveis constantes

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_CONTATOS 50

// structs

struct Contato {
    char nome[25];
    char telefone[17];
    char tipoDeContato[20];
};

// programa principal
int main() {
    int opcao = 0, id = 0, buscarId = 0, indice = 0, usuariosCadastrados = 0, excluirId = 0, escolhaExcluirContato;
    struct Contato c[TAMANHO_CONTATOS];

    while(opcao != 6) {
        printf("Bem-vindo(a) à Agenda de Contatos!\n");
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
                scanf("%s", c[id].nome);

                // informar o telefone do novo contato
                printf("Digite o telefone do novo contato: \n");
                scanf("%s", c[id].telefone);

                // informar o tipo de contato
                printf("Digite o tipo de contato: \n");
                scanf("%s", c[id].tipoDeContato);

                printf("3--------------------------------3 \n");
                printf("Contato adicionado com sucesso!\n");
                printf("3--------------------------------3\n");

                id++;
                usuariosCadastrados++;
                break;
            case 2:
                // excluir um contato
                // verificar se não tem usuário cadastrado
                if(id <= 0) {
                    printf("Não há nenhum usuário cadastrado");
                    return 1;
                }            

                // informar para o usuário o id do contato
                printf("Qual é o id que você deseja excluir? \n");
                scanf("%d", &excluirId);

                indice = excluirId - 1;

                // Verificar se o id existe
                if(indice >= id) {
                    printf("Usuario não encontrado");
                    return 1;
                }


                // mostrar o contato encontrado para o usuário
                printf("ID: %d\n", excluirId); 
                printf("Nome: %20s\n", c[indice].nome);
                printf("Telefone: %17s\n", c[indice].telefone);
                printf("Tipo de contato: %20s\n", c[indice].tipoDeContato);                

                printf("Você deseja excluir esse contato?\n");
                printf("[1] - Sim \n");
                printf("[2] - Não \n");
                scanf("%d", &escolhaExcluirContato);

                switch(escolhaExcluirContato) {
                    case 1:
                        printf("Contato excluido com sucesso!\n");
                        printf("Voltando para o menu principal...\n");
                        break;
                    case 2:
                        printf("Cancelado a opção de excluir contato com sucesso \n");
                        printf("Voltando para o menu principal...\n");
                        printf("---------------------------------\n");
                        break;
                }
                break;
            case 3:
                // alterar um contato 
                break;
            case 4:
                if(id <= 0) {
                    printf("Não há nenhum usuário cadastrado");
                    return 1;
                }

                printf("Lista de contatos\n");
                for(int i = 0; i < id; i++) {
                    printf("ID: %d\n", i + 1); // indice e não ID
                    printf("Nome: %20s\n", c[i].nome);
                    printf("Telefone: %17s\n", c[i].telefone);
                    printf("Tipo de contato: %20s\n", c[i].tipoDeContato);
                }
                break;
            case 5:
                // localizar um contato  
                if(usuariosCadastrados <= 0) {
                    printf("Não há nenhum usuário cadastrado");
                    return 1;
                }                

                printf("Digite o id: \n");
                scanf("%d", &buscarId);
                
                // Converter para índice interno (usuário vê 1, array começa em 0)
                indice = buscarId - 1;

                printf("ID: %d\n", buscarId); 
                printf("Nome: %20s\n", c[indice].nome);
                printf("Telefone: %17s\n", c[indice].telefone);
                printf("Tipo de contato: %20s\n", c[indice].tipoDeContato);
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