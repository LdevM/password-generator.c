#ifndef ARCHIVEFUNCTIONS_H
#define ARCHIVEFUNCTIONS_H

void SaveNewArchive(const char *password, char *nameArchive);
void ReadArchive(char *nameArchive);
void SaveExistingArchive(const char *password, char *nameArchive);
void renameArchive(const char *nameArchive, char *newName);


#endif // ARCHIVEFUNCTIONS
