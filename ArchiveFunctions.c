#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "ArchiveFunctions.h"
#include "VerifyingAndAddFunctions.h"


void SaveNewArchive(const char *password, char *nameArchive) {
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



void SaveExistingArchive(const char *password, char *nameArchive) {
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
