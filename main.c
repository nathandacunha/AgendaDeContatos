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
    int opcao = 0;
    int id = 0; 
    int buscarId = 0; 
    int indice = 0;
    int usuariosCadastrados = 0;
    int excluirId = 0; 
    int escolhaExcluirContato = 0;
    int alterarId = 0;
    int escolhaAlterarContato = 0;
    int alterarContato = 0; 
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
                printf("Digite o tipo de contato de acordo com as opções abaixo: \n");
                printf("- Pessoal \n");
                printf("- Trabalho \n");
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
                        for(int i = indice; i < id - 1; i++) {
                            c[i] = c[i + 1]; // o contato da frente sobrescreve o de trás
                        }

                        printf("Contato excluido com sucesso!\n");
                        printf("Voltando para o menu principal...\n");

                        id--;
                        usuariosCadastrados--;

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
                if(id <= 0) {
                    printf("Não há nenhum contato registrado");
                    return 1;
                }

                // Informar ao usuário o id
                printf("Digite o id que deseja alterar: \n");
                scanf("%d", &alterarId);
                
                indice = alterarId - 1;

                // verificando se o id existe
                if(indice >= id) {
                    printf("Usuário não encontrado");
                    return 1;
                }

                // mostrar o contato encontrado para o usuário
                printf("ID: %d\n", alterarId); 
                printf("Nome: %20s\n", c[indice].nome);
                printf("Telefone: %17s\n", c[indice].telefone);
                printf("Tipo de contato: %20s\n", c[indice].tipoDeContato);
                printf("---------------------------------\n");                
                printf("Você deseja alterar esse contato? \n");
                printf("[1] - Sim \n");
                printf("[2] - Não \n");
                printf("----------------------- \n");
                scanf("%d", &escolhaAlterarContato);

                switch(escolhaAlterarContato) {
                    case 1:
                        printf("Contato encontrado \n");
                        printf("------------------------- \n");
                        printf("ID: %d\n", alterarId); 
                        printf("Nome: %20s\n", c[indice].nome);
                        printf("Telefone: %17s\n", c[indice].telefone);
                        printf("Tipo de contato: %20s\n", c[indice].tipoDeContato);
                        printf("---------------------------------\n");            
                        printf("O que você deseja alterar? \n");
                        printf("[1] - Nome \n");
                        printf("[2] - Telefone \n");
                        printf("[3] - Tipo de contato \n");
                        printf("[4] - Cancelar \n");
                        scanf("%d", &alterarContato);

                        switch(alterarContato) {
                            case 1:
                                printf("Digite o novo nome do contato: \n");
                                scanf("%25s", c[indice].nome);
                                printf("-------------------------------\n");
                                printf("Nome: %25s\n", c[indice].nome);
                                printf("Novo nome do contato foi atualizado com sucesso! \n");
                                printf("------------------------------\n");
                                break;
                        }
                        break;
                    case 2:
                        printf("Voltando para o menu principal.....");
                        printf("-----------------------------------");
                        break;
                }
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