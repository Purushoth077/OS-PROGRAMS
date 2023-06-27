#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
} File;
typedef struct {
    File files[MAX_FILES];
    int count;
} Directory;
void initializeDirectory(Directory* directory) {
    directory->count = 0;
}
void addFile(Directory* directory, const char* name, int size) {
    if (directory->count >= MAX_FILES) {
        printf("Directory is full. Cannot add more files.\n");
        return;
    }
    File file;
    strncpy(file.name, name, MAX_FILENAME_LENGTH - 1);
    file.size = size;
    directory->files[directory->count] = file;
    directory->count++;
    printf("File '%s' added to the directory.\n", name);
}
void displayFiles(const Directory* directory) {
    if (directory->count == 0) {
        printf("Directory is empty.\n");
        return;
    }
    printf("Files in the directory:\n");
    printf("-----------------------\n");
    for (int i = 0; i < directory->count; i++) {
        printf("Name: %s\tSize: %d KB\n", directory->files[i].name, directory->files[i].size);
    }

    printf("-----------------------\n");
}
int main() {
    Directory directory;
    initializeDirectory(&directory);

    addFile(&directory, "file1.txt", 1024);
    addFile(&directory, "file2.doc", 2048);
    addFile(&directory, "file3.jpg", 3072);
    addFile(&directory, "file4.mp3", 4096);
    addFile(&directory, "file5.pdf", 5120);
    displayFiles(&directory);
    return 0;
}
