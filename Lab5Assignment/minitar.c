#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define NAMSIZ 100   // Maximum length of the file name
#define SIZELEN 12   // Length for the size field (zero-padded)
#define RECORDSIZE 512

typedef struct {
    char name[NAMSIZ];
    char size[SIZELEN];
} mini_header;

// Function to get the file size
int get_file_size(const char* filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to write a null-padded string to the file
void write_null_padded_string(FILE* fp, const char* str, int max_len) {
    int len = strlen(str);
    fwrite(str, sizeof(char), len, fp);
    for (int i = len; i < max_len; ++i) {
        fputc('\0', fp); // Null pad the string to max_len
    }
}

// Function to write a file to the archive
void write_file_to_archive(FILE* output_file, const char* filename) {
    // Get the file size
    int file_size = get_file_size(filename);
    if (file_size == -1) {
        return;
    }

    // Open the input file
    FILE* input_file = fopen(filename, "rb");
    if (!input_file) {
        perror("Unable to open input file");
        return;
    }

    // Write the file name (null-padded)
    write_null_padded_string(output_file, filename, NAMSIZ);

    // Write the file size (zero-padded)
    mini_header header;
    snprintf(header.size, SIZELEN, "%011d", file_size);
    fwrite(header.size, sizeof(char), SIZELEN, output_file);

    // Copy the file content to the archive
    char buffer[RECORDSIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
}

int main(int argc, char* argv[]) {
    // Ensure that there are at least two files and one output file
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <input_files...>\n", argv[0]);
        return 1;
    }

    // Open the output archive file (Result.tar)
    FILE* output_file = fopen("Result.tar", "wb");
    if (!output_file) {
        perror("Unable to create output file");
        return 1;
    }

    // Write each input file to the archive
    for (int i = 1; i < argc; ++i) {
        write_file_to_archive(output_file, argv[i]);
    }

    fclose(output_file);
    printf("Archive created successfully: Result.tar\n");

    return 0;
}
