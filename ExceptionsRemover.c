#include <stdio.h>
#include <stdlib.h>
#include "ExceptionsRemover.h"


void removeExceptions(const int length, char *password) {
    for (int i = 0; i < length; i++) {
        if (*(password + i) == 34 || *(password + i) == 39 || *(password + i) == 40 ||
            *(password + i) == 41 || *(password + i) == 60 || *(password + i) == 62 ||
            *(password + i) == 91 || *(password + i) == 93 || *(password + i) == 96) {
            *(password + i) = rand() % 94 + 33;
            i--;
        }
    }
}
