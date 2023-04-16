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
