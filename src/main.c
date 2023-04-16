#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mariadb/mysql.h>
#include "usuario/usuarioFuncoes.h"
#include "main.h"

MYSQL* inicializar_conecao(void);
MYSQL* connect;
void limparConsole(void);

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
               case 2:
                    mostrarListaDeUsuarios(); 
                    return;
                    break;
               case 7: 
                    rodando--;
                    break;
                    return;
          }
     }
}

void mostrarListaDeUsuarios() {
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
          printf("\n \033[32m 1 - Recarregar Lista | 2 - pagina Anterior | 3 - Proxima página | 4 - Sair \033[0m\n");
          
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
                    mostrarInicial();
                    return;
                    break;
               default:
                printf("Selecione uma opcao valida\n");
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