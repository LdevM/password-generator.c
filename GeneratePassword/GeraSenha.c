#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <ctype.h>
#include <locale.h>
#include "ArchiveFunctions.h"
#include "VerifyingAndAddFunctions.h"
#include "ExceptionsRemover.h"
#include "MenusFunctions.h"


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
            menuDificulty();
            if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 3))
                break;
            else {
                printf("Resposta inválida!\nTente novamente\n");
                Sleep(3000);
                system("cls");
                clearInputBuffer();
            }
        } while (true);

        generatePassword(size, choice, password);
        printf("%s\n", password);

        clearInputBuffer();

        do {
            printf("Você gostaria de salvar a senha em um arquivo de texto? [S/N]\n");
            printf("Sua opção: ");
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
                printf("Resposta inválida! Tente novamente\n");
            }
        } while (true);

        do {
            menuSaveOrAdd();
            if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 2)){
                break;
            }
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
                printf("Digite o nome do arquivo existente (O nome deve ser exato, caso contrário será criado um novo arquivo): ");
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

        do{
            finalMenu();
            if (scanf("%d", &choice) == 1 && (choice > 0 && choice <= 4)){
                break;
            }
            else{
                printf("Resposta inválida!\nTente novamente\n");
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
                    printf("Arquivo com extensão não permitida! Tente novamente\n");
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
            Sleep(3000);
            system("cls");
            clearInputBuffer();
        }
        do{
            if(choice == 4)
                break;
            finishOrRestart();
            if (scanf("%d", &choice) == 1 && (choice > 0 && choice <= 2)){
                break;
            }
            else{
                printf("Resposta inválida!\nTente novamente\n");
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
