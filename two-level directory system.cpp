#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

struct user {
    char name[20];
    int file_count;
    struct file *files[MAX_FILES];
};

struct file {
    char name[20];
};

struct user users[MAX_USERS];

void create_directory(char *name) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] == '\0') {
            strcpy(users[i].name, name);
            users[i].file_count = 0;
            return;
        }
    }
    printf("Maximum number of directories reached\n");
}

void create_file(char *name, char *directory) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, directory) == 0) {
            if (users[i].file_count == MAX_FILES) {
                printf("Maximum number of files reached for directory %s\n", directory);
                return;
            }
            struct file *f = (struct file*)malloc(sizeof(struct file));
            strcpy(f->name, name);
            users[i].files[users[i].file_count++] = f;
            return;
        }
    }
    printf("Directory %s not found\n", directory);
}

void print_directories() {
    int i;
    printf("Directories:\n");
    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] != '\0') {
            printf("%s\n", users[i].name);
        }
    }
}

void print_files(char *directory) {
    int i, j;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, directory) == 0) {
            printf("Files in directory %s:\n", directory);
            for (j = 0; j < users[i].file_count; j++) {
                printf("%s\n", users[i].files[j]->name);
            }
            return;
        }
    }
    printf("Directory %s not found\n", directory);
}

int main() {
    create_directory("user1");
    create_directory("user2");
    create_directory("user3");
    create_file("file1", "user1");
    create_file("file2", "user1");
    create_file("file3", "user1");
    create_file("file4", "user2");
    create_file("file5", "user2");
    create_file("file6", "user3");
    print_directories();
    print_files("user1");
    print_files("user2");
    print_files("user3");
    return 0;
}
