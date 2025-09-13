#include <stdio.h>

void menuDificulty(){
    printf("Escolha a dificulade da senha\n\n");
    printf("(1)Fácil\n");
    printf("(2)Médio\n");
    printf("(3)Difícil\n");
    printf("Sua opção: ");
}

void menuSaveOrAdd(){
    printf("Selecione uma opção:\n");
    printf("[1] Guardar em um novo arquivo\n");
    printf("[2] Adicionar em um arquivo existente\n");
    printf("Sua opção: ");
}

void finalMenu(){
    printf("Selecione uma opção:\n");
    printf("[1]Ler as senhas deste arquivo\n");
    printf("[2]Renomear o arquivo\n");
    printf("[3]Encerrar o programa\n");
    printf("[4]Gerar uma nova senha\n");
    printf("Sua opção:");
}

void finishOrRestart(){
    printf("Selecione uma opção:\n");
    printf("[1] Gerar uma nova senha\n");
    printf("[2] Encerrar o programa\n");
    printf("Sua opção:");
}
