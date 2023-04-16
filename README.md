## Framework
- libmariadb-dev-compat:i386

## Comando de compilação (Linux/Windows)
E necessário estar no diretório *src* para executar o comando abaixo.

```
$ gcc -o crud main.c conexao/mysqli.c usuario/usuarioFucoes.c -lmariadbD
```

## Execução do aplicativo
### Linux
```
$ ./crud
```
### Windows
Após a compilação terá um arquivo *crud.exe* no diretório *src*, basta executar.

## Configurando sistema 

No arquivo */src/mysqli.c* é necessario configurar o *mysql_real_connect*, como exemplo abaixo:
```
mysql_real_connect(connect(Não mudar),"O ip da conexão MySQL", "seu_usuario_do_banco_de_dados", "senha_do_banco_de_dados", "Nome_do_Banco_de_dados", 0, NULL, 0)
```
Em seu banco de dados deve conter uma tabela *usuarios* com a seguntes colunas:

- id
- nome
- idade

Caso essa tabela não seja defina, o sistema pode apresentar algumas instabilidade.
