#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "VerifyingAndAddFunctions.h"





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


void addFinalTxt(char *nameArchive){
    const char extension[4] = ".txt";
    strncat(nameArchive, extension, 50 - strlen(nameArchive) - 1);
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
