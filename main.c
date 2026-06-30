// importação de bibliotecas + variáveis constantes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_CONTATOS 20

// structs

struct Contato {
    char nome[25];
    char telefone[17];
    char tipoDeContato[20];
};

// prototipo das funções e procedimento

int verificarIDCadastrado(int idUser);
int verificarID(int index, int idUser);
void mostrarContato(int idUser, const struct Contato *contato);
void mensagemDeCancelarExclusao();
void listarContato(int idUser, const struct Contato *contato);
void alterarContatoNome(int idUser, const struct Contato *contato);
void alterarContatoTelefone(int idUser, const struct Contato *contato);
void alterarContatoTipoDeContato(int idUser, const struct Contato *c);

// programa principal
int main() {
    // declaração de variáveis
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
    int opcaoTipo = 0;
    struct Contato c[TAMANHO_CONTATOS];

    // menu de interação principal 
    while(opcao != 6) {
        printf("Bem-vindo(a) à Agenda de Contatos!\n");
        printf("-------------------------------- \n");
        printf("[1] - Adicionar novo contato \n");
        printf("[2] - Excluir um contato \n");
        printf("[3] - Alterar um contato \n");
        printf("[4] - Listar todos os contatos existentes\n");
        printf("[5] - Localizar um contato\n");
        printf("[6] - Sair \n");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número.\n");

            while (getchar() != '\n');
            continue;
        }   

        switch(opcao) {
            case 1:
                if(id >= TAMANHO_CONTATOS) {
                    printf("O limite de contatos foi atingido \n");
                    break;
                }

                // Informar o nome do novo contato
                printf("Digite o nome do novo contato: \n");
                getchar(); // Remove o '\n' deixado pelo scanf anterior
                fgets(c[id].nome, sizeof(c[id].nome), stdin);
                c[id].nome[strcspn(c[id].nome, "\n")] = '\0';
                

                // informar o telefone do novo contato
                printf("Digite o telefone do novo contato: \n");
                scanf("%s", c[id].telefone);

                // informar o tipo de contato
                do {
                    printf("Selecione o tipo de contato:\n");
                    printf("[1] - Pessoal\n");
                    printf("[2] - Trabalho\n");
                    
                    // verifica se o tipo de contato é válido
                    if (scanf("%d", &opcaoTipo) != 1) {
                        printf("Entrada inválida! Digite apenas 1 ou 2.\n");

                        while (getchar() != '\n');

                        opcaoTipo = 0;
                        continue;
                    }
                        
                    switch(opcaoTipo) {
                        case 1:
                            strcpy(c[id].tipoDeContato, "Pessoal");
                            break;
                        case 2:
                            strcpy(c[id].tipoDeContato, "Trabalho");
                            break;
                        default:
                            printf("Opção inválida! Digite apenas '1' ou '2'.\n\n");
                            break;
                    }
                } while(opcaoTipo != 1 && opcaoTipo != 2);

                printf("3--------------------------------3 \n");
                printf("Contato adicionado com sucesso!\n");
                printf("3--------------------------------3\n");

                id++;
                usuariosCadastrados++;
                break;
            case 2:
                // excluir um contato
                // verificar se não tem usuário cadastrado
                if(!verificarIDCadastrado(id)) {
                    break;
                } 

                // informar para o usuário o id do contato
                printf("Qual é o id que você deseja excluir? \n");
                scanf("%d", &excluirId);

                indice = excluirId - 1;

                // Verificar se o id existe
                
                if(!verificarID(indice, id)) {
                    break;
                }

                // mostrar o contato encontrado para o usuário                
                mostrarContato(excluirId, &c[indice]);

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
                        break;
                    case 2:
                        mensagemDeCancelarExclusao();
                        break;
                    default:
                        printf("Erro! Tente novamente mais tarde");
                        break;
                }
                break;
            case 3:
                // alterar um contato 
                if(!verificarIDCadastrado(id)) {
                    break;
                }

                // Informar ao usuário o id
                printf("Digite o id do contato que deseja alterar: \n");
                scanf("%d", &alterarId);
                
                indice = alterarId - 1;

                // verificando se o id existe
                if(!verificarID(indice, id)) {
                    break;
                }

                // mostrar o contato encontrado para o usuário
                mostrarContato(alterarId, &c[indice]);

                printf("---------------------------------\n");                
                printf("Você deseja alterar esse contato? \n");
                printf("[1] - Sim \n");
                printf("[2] - Não \n");
                printf("----------------------- \n");
                scanf("%d", &escolhaAlterarContato);

                switch(escolhaAlterarContato) {
                    case 1:
                        printf("------------------------ \n");
                        printf("Contato encontrado\n");
                        printf("-------------------------\n");
                        mostrarContato(alterarId, &c[indice]);
                        printf("---------------------------------\n");
                        
                                   
                        printf("O que você deseja alterar? \n");
                        printf("[1] - Nome \n");
                        printf("[2] - Telefone \n");
                        printf("[3] - Tipo de contato \n");
                        printf("[4] - Cancelar \n");
                        scanf("%d", &alterarContato);

                        switch(alterarContato) {
                            case 1:
                                alterarContatoNome(indice, c);
                                break;
                            case 2:
                                alterarContatoTelefone(indice, c);
                                break;
                            case 3:
                                alterarContatoTipoDeContato(indice, c);   
                                break;
                            case 4:
                                printf("Alteração do contato foi cancelado\n");
                                printf("Voltando para o menu principal...\n");
                                printf("------------------------------------\n");
                                break;
                            default:
                                printf("Erro desconhecido! Tente mais tarde \n");
                                printf("------------------------------------\n");
                                break;
                        }
                        break;
                    case 2:
                        printf("Voltando para o menu principal.....\n");
                        printf("-----------------------------------\n");
                        break;
                }
                break;
            case 4:
                // verifica se não tem um id cadastrado
                if(!verificarIDCadastrado(id)) {
                    break;
                } 

                printf("Lista de contatos\n");
                listarContato(id, c);
                break;
            case 5:
                // localizar um contato  

                // verifica se não tem um id cadastrado
                if(!verificarIDCadastrado(id)) {
                    break;
                }                 

                printf("Digite o id: \n");
                scanf("%d", &buscarId);
                
                // Converter para índice interno (usuário vê 1, array começa em 0)
                indice = buscarId - 1;

                // verifica a existência do id
                if(!verificarID(indice, id)) {
                    break;
                }

                mostrarContato(buscarId, &c[indice]);
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

// declarações das funções e procedimento

// função para verificar se tem algum id cadastrado
int verificarIDCadastrado(int idUser) {
    if(idUser <= 0) {
        printf("Não há nenhum contato cadastrado \n");
        return 0;
    }
    return 1;
}

// verificar se o indice é maior que o id

int verificarID(int index, int idUser) {
    if(index >= idUser) {
        printf("Usuário não encontrado.\n");
        return 0;
    }
    return 1;
}

// exibir o id do contato encontrado

void mostrarContato(int idUser, const struct Contato *contato) {
    printf("ID: %d\n", idUser); 
    printf("Nome: %20s\n", contato->nome);
    printf("Telefone: %17s\n", contato->telefone);
    printf("Tipo de contato: %20s\n", contato->tipoDeContato);    
}

// exibe a mensagem de cancelamento de excluir contato
void mensagemDeCancelarExclusao() {
    printf("Cancelado a opção de excluir contato com sucesso \n");
    printf("Voltando para o menu principal...\n");
    printf("---------------------------------\n");
}

// listar contato
void listarContato(int idUser, const struct Contato *c) {
    for(int i = 0; i < idUser; i++) {
        printf("ID: %d\n", i + 1); // indice e não ID
        printf("Nome: %20s\n", c[i].nome);
        printf("Telefone: %17s\n", c[i].telefone);
        printf("Tipo de contato: %20s\n", c[i].tipoDeContato);
    }
}

// alterar o nome do contato
void alterarContatoNome(int idUser, const struct Contato *c) {
    printf("Digite o novo nome do contato: \n");
    scanf("%25s", c[idUser].nome);
    printf("-------------------------------\n");
    printf("Nome: %25s\n", c[idUser].nome);
    printf("Novo nome do contato foi atualizado com sucesso! \n");
    printf("------------------------------\n");
}

// altera o telefone do contato

void alterarContatoTelefone(int idUser, const struct Contato *c) {
    printf("Digite o novo telefone do contato: \n");
    scanf("%s", c[idUser].telefone);
    printf("-------------------------------\n");
    printf("Telefone: %s\n", c[idUser].telefone);
    printf("Novo telefone do contato foi atualizado com sucesso! \n");
    printf("------------------------------\n");
}

// altera o tipo de contato do contato

void alterarContatoTipoDeContato(int idUser, const struct Contato *c) {
    printf("Digite o novo tipo de contato: \n");
    scanf("%s", c[idUser].tipoDeContato);
    printf("-------------------------------\n");
    printf("Telefone: %s\n", c[idUser].tipoDeContato);
    printf("Novo tipo de contato foi atualizado com sucesso! \n");
    printf("------------------------------\n");
}