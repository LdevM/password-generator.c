#include <stdio.h>

void menuDificulty(){
    printf("Escolha a dificulade da senha\n\n");
    printf("(1)F�cil\n");
    printf("(2)M�dio\n");
    printf("(3)Dif�cil\n");
    printf("Sua op��o: ");
}

void menuSaveOrAdd(){
    printf("Selecione uma op��o:\n");
    printf("[1] Guardar em um novo arquivo\n");
    printf("[2] Adicionar em um arquivo existente\n");
    printf("Sua op��o: ");
}

void finalMenu(){
    printf("Selecione uma op��o:\n");
    printf("[1]Ler as senhas deste arquivo\n");
    printf("[2]Renomear o arquivo\n");
    printf("[3]Encerrar o programa\n");
    printf("[4]Gerar uma nova senha\n");
    printf("Sua op��o:");
}

void finishOrRestart(){
    printf("Selecione uma op��o:\n");
    printf("[1] Gerar uma nova senha\n");
    printf("[2] Encerrar o programa\n");
    printf("Sua op��o:");
}
