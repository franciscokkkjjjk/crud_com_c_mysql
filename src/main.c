#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mariadb/mysql.h>
#include "usuario/usuarioFuncoes.h"
#include "main.h"

MYSQL* inicializar_conecao(void);
MYSQL* connect;

void limparConsole(void);

void mostrarListaDeUsuarios(void);

void mostrarUmUsuarioEspecifico(void);

void mostrarEdicaoDeUsuario(void);

int main(void) {
     connect = inicializar_conecao();
     mostrarInicial();
     return 0;
}


void mostrarInicial() {
     int rodando= 0;
     while (rodando == 0){
          limparConsole();
          printf("\033[41m \033[1m \033[29m*************Bem vindo ao crud de usuarios!************\033[0m\n\n");
          int optSelecionadaUsuario = 0;
          printf("Escolha uma das acoes abaixo: \n\n");
          printf("\033[32m 1 - Mostrar usuario especifico \033[0m | ");     
          printf("\033[32m2 - Mostrar lista de usuario \033[0m\n\n");     
          printf("\033[32m 3 - Cadastrar um novo usuario  \033[0m| ");     
          printf("\033[32m4 - Excluir um usuario  \033[0m\n\n");     
          printf("\033[32m 5 - Editar um usuario          \033[0m| ");     
          printf("\033[32m6 - Deletar o seu sistema operacional \033[0m\n\n");
          printf("\033[32m 7 - Sair\n\n \033[0m");
          printf("\033[1mDigite a opcao desejada: \033[0m");
          scanf("%i", &optSelecionadaUsuario);


          switch(optSelecionadaUsuario) {
               case 1:
                    mostrarUmUsuarioEspecifico();
                    break;
               case 2:
                    mostrarListaDeUsuarios(); 
                    break;
               case 5:
                    mostrarEdicaoDeUsuario();
                    break;
               case 7: 
                    rodando--;
                    break;
                    return;
          }
     }
}

void mostrarListaDeUsuarios(void) {
     int numPag = 0;
     while (1)
     {
          limparConsole();
          if(numPag < 0) {
               numPag = 0;
          }
          int opt = 0;
          printf("Todos usuarios cadastrados no banco de dados: \n\n");
          mostrarTodosUsuarios(connect, numPag);
          printf("\n \033[32m 1 - Recarregar Lista | 2 - pagina Anterior | 3 - Proxima página | 4 - Voltar \033[0m\n");
          
          scanf("%i", &opt);
          switch(opt) {
               case 1: 
                    continue;
               case 2:
                    numPag--; 
                    continue;
               case 3: 
                    numPag++;
                    continue;
               case 4:
                    return;
                    break;
               default:
                printf("Selecione uma opcao valida\n");
          }
          
     }
     
}

void mostrarUmUsuarioEspecifico(void) {
     int rodando = 0;
     while(rodando == 0) {
          int opt;
          int id;
          limparConsole();
          printf("Digite o id do usuario: ");
          scanf("%i", &id);
          mostrarUsuario(connect, id);
          printf("\033[32m 1 - Buscar outro usuario | 2 - Voltar \033[0m\n"); // excluir  e editar
          scanf("%i", &opt);
          switch(opt) {
               case 1:
                    continue;
               case 2:
                    rodando--;
                    return;
                    break;
               default:
                    printf("Selecione uma opcao valida");
          }
     }
}

void mostrarEdicaoDeUsuario(void) {
     int rodando = 0;
     while(rodando == 0) {
          int id;
          char novoNome[255];
          int novaIdade;
          int nomeMudar = 0;
          int idadeMudar = 0;
          int opt;
          limparConsole();
          printf("\033[41m \033[1m \033[29m ************* EDICAO DE USUARIOS *************\033[0m\n\n");
          printf("\033[32m 1 - Procurar usuario para edicao | 2 - Voltar \033[0m\n");
          scanf("%i", &opt);
          if(opt == 2) {
               return;
               break;
          }
          printf("Digite o id do usuario que será editado: ");
          scanf("%i", &id);
          if((procurarUsuario(connect, id)) == 1) {
               printf("Usuario encontrado: \n\n");
               mostrarUsuario(connect, id);
               printf("Eh esse usuario? \n\n");
               printf("\033[32m 1 - sim | 2 - nao | 3 - Voltar \033[0m\n");
               scanf("%i", &opt);
               if(opt == 1){
                    printf("Digite o novo nome: ");
                    scanf("%s", novoNome);
                    printf("Digite o Nova idade: ");
                    scanf("%i", &novaIdade);
                    editarUsuario(connect, novoNome, novaIdade, id);
                    printf("Dados Atualizados: \n\n");
                    mostrarUsuario(connect, id);
                    printf("\033[32m 1 - Editar um novo usuario | 2 - Voltar \033[0m\n");
                    scanf("%i", &opt);
                    switch(opt) {
                         case 1: 
                              continue;
                              break;
                         case 2: 
                              return;
                              break;
                    }
               } else if(opt == 3) {
                    return;
                    break;
               } else {
                    continue;
               }
          } else {
               continue;
          }
     }
}

void limparConsole(void) {
     #ifdef _WIN32
          system("cls");
     #else
          system("clear");
      #endif
}