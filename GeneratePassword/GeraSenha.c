#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

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
    FILE *savePassword;
    if (!VerifyExtensionExisting(nameArchive)){
        addFinalTxt(nameArchive);
    }

    savePassword = fopen(nameArchive, "w");
    if (savePassword == NULL) {
        perror("Erro ao abrir arquivo!");
        return;
    }

    fprintf(savePassword, "%s\n", password);
    fclose(savePassword);
}



void SaveExistingArchive(char *password, char *nameArchive) {
    FILE *savePassword;
    if (!VerifyExtensionExisting(nameArchive)){
        addFinalTxt(nameArchive);
    }

    savePassword = fopen(nameArchive, "a");

    if (savePassword == NULL) {
        perror("Erro ao abrir arquvio!");
        return;
    }
    fprintf(savePassword, "%s\n", password);
    fclose(savePassword);

}



bool IsExtensionTxt(const char *nameArchive) {
    const char Txt[] = ".txt";
    char *extensao_ptr;
    bool extensionTxt = false;


    extensao_ptr = strrchr(nameArchive, '.');


    if (extensao_ptr != NULL && strcmp(extensao_ptr, Txt) == 0) {
        return true;
    }

    return extensionTxt;
}

void ReadArchive(char *nameArchive) {
    FILE *savePassword;
    char bufferLine[30];

    savePassword = fopen(nameArchive, "r");

    if (savePassword == NULL){
        perror("Erro ao abrir arquivo");
        return;
    }

    while(fgets(bufferLine, 30, savePassword) != NULL){
        printf("%s", bufferLine);
    }

    fclose(savePassword);
}

void renameArchive(const char *nameArchive, char *newName){
    int aux = 0;
    if (!VerifyExtensionExisting(newName)){
        addFinalTxt(newName);
    }

    aux = rename(nameArchive, newName);

    if (aux == 0){
        printf("Nome alterado de: %s para %s!\n", nameArchive, newName);
    }
    else{
        perror("Erro ao renomear arquivo!\n");
    }
}

int main() {
    srand(time(NULL));
    int size, choice = 0;
    char *password = NULL;
    char nameArchive[50];
    char answerYN;
    char newNameArchive[50];
    bool keepRunningProgram = false;
    setlocale(LC_ALL, "");
    do{
        do {
            printf("Tamanho da senha (M�x: 20):");
            if (scanf("%d", &size) == 1 && (size > 0) && (size <= 20))
                break;
            else {
                printf("Dado inv�lido!\nTente novamente\n");
                clearInputBuffer();
            }
        } while (true);

        password = (char*)malloc((size + 1) * sizeof(char));

        if (password == NULL) {
            printf("Erro ao alocar mem�ria\n");
            return 1;
        }

        do {
            printf("Escolha a dificulade da senha\n\n");
            printf("(1)F�cil\n");
            printf("(2)M�dio\n");
            printf("(3)Dif�cil\n");
            printf("Sua op��o: ");
            if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 3))
                break;
            else {
                printf("Resposta inv�lida!\nTente novamente\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();
            }
        } while (true);

        generatePassword(size, choice, password);
        printf("%s\n", password);

        clearInputBuffer();

        do {
            printf("Voc� gostaria de salvar a senha em um arquivo de texto? [S/N]\n");
            printf("Sua op��o: ");
            scanf("%c", &answerYN);
            clearInputBuffer();
            answerYN = toupper(answerYN);

            if (answerYN == 'S' || answerYN == 'N') {
                if (answerYN == 'N'){
                    free(password);
                    return 0;
                }
                break;
            } else {
                printf("Resposta inv�lida! Tente novamente\n");
            }
        } while (true);

        do {
            printf("Selecione uma op��o:\n");
            printf("[1] Guardar em um novo arquivo\n");
            printf("[2] Adicionar em um arquivo existente\n");
            printf("Sua op��o: ");
            if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 2)){
                break;
            }
            else {
                printf("Resposta inv�lida! Tente novamente\n");
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
                    printf("Extens�o n�o permitida, use .txt ou salve sem extens�o!\n");
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
                printf("Digite o nome do arquivo existente (O nome deve ser exato, caso contr�rio ser� criado um novo arquivo): ");
                scanf("%s", nameArchive);
                if (VerifyExtensionExisting(nameArchive) && !IsExtensionTxt(nameArchive)){
                    printf("Extens�o n�o permitida, use .txt ou salve sem extens�o!\n");
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

        do{
            printf("Selecione uma op��o:\n");
            printf("[1]Ler as senhas deste arquivo\n");
            printf("[2]Renomear o arquivo\n");
            printf("[3]Encerrar o programa\n");
            printf("[4]Gerar uma nova senha\n");
            printf("Sua op��o:");
            if (scanf("%d", &choice) == 1 && (choice > 0 && choice <= 4)){
                break;
            }
            else{
                printf("Resposta inv�lida!\nTente novamente\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();
            }
        } while(true);

        if (choice == 1){
            ReadArchive(nameArchive);
        }

        if (choice == 2){
            do{
                printf("Qual o nome que deseja renomear?\n");
                scanf("%49s", newNameArchive);
                if(VerifyExtensionExisting(newNameArchive) && !IsExtensionTxt(newNameArchive)){
                    printf("Arquivo com extens�o n�o permitida! Tente novamente\n");
                    Sleep(3000);
                    system("cls");
                    clearInputBuffer();
                }
                else{
                    rename(nameArchive, newNameArchive);
                    break;
                }
            } while(true);
        }

        if (choice == 3){
            free(password);
            return 0;
        }
        if (choice == 4){
            keepRunningProgram = true;
            sleep(3000);
            system("cls");
            clearInputBuffer();
        }
        do{
            if(choice == 4)
                break;
            printf("Selecione uma op��o:\n");
            printf("[1] Gerar uma nova senha\n");
            printf("[2] Encerrar o programa\n");
            printf("Sua op��o:");
            if (scanf("%d", &choice) == 1 && (choice > 0 && choice <= 2)){
                break;
            }
            else{
                printf("Resposta inv�lida!\nTente novamente\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();
            }
        } while(true);

        if (choice == 1)
            keepRunningProgram = true;
        if (choice == 2)
            keepRunningProgram = false;
        free(password);
        Sleep(3000);
        system("cls");
        clearInputBuffer();
    } while(keepRunningProgram);
    return 0;
}
