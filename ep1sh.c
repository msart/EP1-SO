/*************************************************
* Felipe de Oliveira Campos Moreira nº - 8516347 *
*                                                *
*************************************************/


/****
Para compilar to usando:
 gcc -lreadline ep1sh.c -o ep1sh

 HTtp://linux.die.net/man/3/execv
*/

#include <stdio.h>              //Printfs
#include <stdlib.h>             //Alocar coisas

#include <readline/readline.h>  //Leitor de linha pedido
#include <readline/history.h>   //Historico do GNU linux pedido

#include <unistd.h>             //Forks


char *remover_espacos(char *linha){
    int i;
    char *linha_sem_branco;

    for(i = 0; linha[i] != '\0'; i++){
        if(linha[i] )
        printf("%c \n", linha[i]);
    }

    return linha_sem_branco;
}

int testar_ls(){
    int pid = fork();
    char *args[] = {"/bin/ls", "-l", 0};
    char *envp[] = {0};
    int status;
    if(pid == 0){
        //Vou tester o ls -s aqui



        execve(args[0], &args[0],envp);

        return 0;
    }else{
        printf("Processo Pai\n");
        waitpid(pid, &status, 0);
    }

    //Ele cria vários forks, hu3
}


int main(){

    char *linha_de_comando, diretorio_atual[1024];
    int is_executando = 1;

    sprintf(diretorio_atual,"(%s/): ", get_current_dir_name());
    /*Pega o Diretório atual e formata, não vejo a necessidade de se colocar num laço para pegar toda hora*/


    while( is_executando ){


        linha_de_comando = readline(diretorio_atual);

        if(linha_de_comando != NULL && linha_de_comando[0] != '\0'){
            /*Verifica se a linha não é nula*/
            add_history(linha_de_comando); //Adiciono na historia do terminal
            remover_espacos(linha_de_comando); //Vou remover os espacos para facilitar a comparacao entre comandos, pq pode ser que ele digite "ls-l" ou "     ls      -l"

        }

        free(linha_de_comando);

    }


}
