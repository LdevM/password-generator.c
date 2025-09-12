#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <strings.h>


void removeExceptions(const int length, char *password) {
    for (int i = 0; i < length; i++) {
        if (*(password + i) == 34 || *(password + i) == 39 || *(password + i) == 40 || *(password + i) == 41 || *(password + i) == 60 || *(password + i) == 62 || *(password + i) == 91 || *(password + i) == 93 || *(password + i) == 96) {
            *(password + i) = rand() % 94 + 33;
            i--;
        }
    }
}


void generatePassword(const int length, const int dificulty, char *password) {
    int aux = 0;
    switch (dificulty) {
        case 1:
            for (int i = 0; i < length; i++) {
                *(password + i) = rand() % 26 + 97;
            }
            break;
        case 2:
            for (int i = 0; i < length; i++) {
                aux = rand() % 2;
                if (aux == 0)
                    *(password + i) = rand() % 26 + 97;
                if (aux == 1)
                    *(password + i) = rand() % 10 + 48;
            }
            break;
        case 3:
            for (int i = 0; i < length; i++) {
                *(password + i) = rand() % 94 + 33;
            }
            removeExceptions(length, password);
            break;
    }
    *(password + length) = '\0';
}


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addFinalTxt(char *nameArchive){
    const char extension[4] = ".txt";
    strncat(nameArchive, extension, 50 - strlen(nameArchive) - 1);
}

bool VerifyExtensionExisting(const char *nameArchive){
    char *extension;
    bool haveExtension = false;

    extension = strrchr(nameArchive, '.');
    if(extension != NULL){
        haveExtension = true;
    }
    else{
        haveExtension = false;
    }
    return haveExtension;
}


void SaveNewArchive(char *password, char *nameArchive) {
    FILE *GuardaSenha;
    if (!VerifyExtensionExisting(nameArchive)){
        addFinalTxt(nameArchive);
    }

    GuardaSenha = fopen(nameArchive, "w");
    if (GuardaSenha == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    fprintf(GuardaSenha, "%s\n", password);
    fclose(GuardaSenha);
}



void SaveExistingArchive(char *password, char *nameArchive) {
    FILE *GuardaSenha;
    if (!VerifyExtensionExisting(nameArchive));{
        addFinalTxt(nameArchive);
    }

    GuardaSenha = fopen(nameArchive, "a");
    if (GuardaSenha == NULL) {
        printf("Erro ao abrir arquvio!\n");
        return;
    }
    fprintf(GuardaSenha, "%s\n", password);
    fclose(GuardaSenha);

}



bool IsExtensionTxt(const char *nameArchive) {
    const char Txt[] = ".txt";
    char *extensao_ptr;


    extensao_ptr = strrchr(nameArchive, '.');


    if (extensao_ptr != NULL && strcmp(extensao_ptr, Txt) == 0) {
        return true;
    }

    return false;
}

int main() {
    srand(time(NULL));
    int size, choice = 0;
    char *password = NULL;
    char nameArchive[50];
    char answerYN;

    do {
        printf("Tamanho da senha (Máx: 20):");
        if (scanf("%d", &size) == 1 && (size > 0) && (size <= 20))
            break;
        else {
            printf("Dado inválido!\nTente novamente\n");
            clearInputBuffer();
        }
    } while (true);

    password = (char*)malloc((size + 1) * sizeof(char));

    if (password == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    do {
        printf("Escolha a dificulade da senha\n\n");
        printf("(1)Fácil\n");
        printf("(2)Médio\n");
        printf("(3)Difícil\n");
        if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 3))
            break;
        else {
            printf("Dado inválido!\nTente novamente\n");
            Sleep(3000);
            system("cls");
            clearInputBuffer();
        }
    } while (true);

    generatePassword(size, choice, password);
    printf("%s\n", password);

    clearInputBuffer();

    do {
        printf("Você gostaria de salvar a senha em um arquivo de texto? [S/N]");
        scanf("%c", &answerYN);
        clearInputBuffer();
        answerYN = toupper(answerYN);

        if (answerYN == 'S' || answerYN == 'N') {
            if (answerYN == 'N')
                return 0;
            break;
        } else {
            printf("Resposta inválida! Tente novamente\n");
        }
    } while (true);

    do {
        printf("Selecione uma opção:\n");
        printf("[1] Guardar em um novo arquivo\n");
        printf("[2] Adicionar em um arquivo existente\n");
        if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 2))
            break;
        else {
            printf("Resposta inválida! Tente novamente\n");
            Sleep(3000);
            system("cls");
            clearInputBuffer();
        }
    } while (true);

    if (choice == 1){
        do{
            printf("Como deseja salvar o nome do arquivo?\n");
            scanf("%49s", nameArchive);
            if(VerifyExtensionExisting(nameArchive) && !IsExtensionTxt(nameArchive)){
                printf("Extensão não permitida, use .txt ou salve sem extensão!\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();
            }
            else{
                SaveNewArchive(password, nameArchive);
                break;
            }
        } while(true);


    }
    if (choice == 2) {
        do{
            printf("Digite o nome do arquivo existente (O nome deve ser exato, caso contrário será criado um novo arquivo):");
            scanf("%s", nameArchive);
            if (VerifyExtensionExisting(nameArchive) && !IsExtensionTxt(nameArchive)){
                printf("Extensão não permitida, use .txt ou salve sem extensão!\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();

            }
            else{
                SaveExistingArchive(password, nameArchive);
                break;
            }
        } while(true);
    }



    free(password);

    return 0;
}
