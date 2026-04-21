#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* csv_filename = "table.csv";

char** get_header(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char** header = malloc(sizeof(char*) * 100); // Assuming max 100 columns
    char line[1024];

    if (fgets(line, sizeof(line), file)){
        char* token = strtok(line, ",");
        int index = 0;
        while (token != NULL) {
            // Remove trailing newline
            size_t len = strlen(token);
            if (len > 0 && token[len - 1] == '\n') {
                token[len - 1] = '\0';
            }
            header[index] = strdup(token);
            token = strtok(NULL, ",");
            index++;
        }
        header[index] = NULL; // NULL-terminate the array
    }
    fclose(file);
    return header;
}

char**get_row(char* filename, int row_number) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    char** row = malloc(sizeof(char*) * 100); // Assuming max 100 columns
    char line[1024];
    int current_row = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_row == row_number) {
            char* token = strtok(line, ",");
            int index = 0;
            while (token != NULL) {
                // Remove trailing newline
                size_t len = strlen(token);
                if (len > 0 && token[len - 1] == '\n') {
                    token[len - 1] = '\0';
                }
                row[index] = strdup(token);
                token = strtok(NULL, ",");
                index++;
            }
            row[index] = NULL; // NULL-terminate the array
            break;
        }
        current_row++;
    }
    fclose(file);
    return row;
}