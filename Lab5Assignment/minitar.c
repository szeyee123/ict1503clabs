// 2303631 Tew Sze Yee

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define NAMSIZ 100   // Maximum length of file name
#define SIZELEN 12   // Length for size field (null-padded)
#define RECORDSIZE 512

typedef struct {
    char name[NAMSIZ];
    char size[SIZELEN];
} mini_header;

// Get file size
int get_file_size(const char* filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Write null-padded string to file
void write_padded_string(FILE* fp, const char* str, int max_len, char pad_char) {
    int len = strlen(str);
    fwrite(str, sizeof(char), len, fp);
    for (int i = len; i < max_len; ++i) {
        fputc(pad_char, fp); // Pad string to max_len with specified character
    }
}

// Write a file to archive
void write_file_to_archive(FILE* output_file, const char* filename) {
    int file_size = get_file_size(filename);
    if (file_size == -1) {
        return;
    }

    // Open input file
    FILE* input_file = fopen(filename, "rb");
    if (!input_file) {
        perror("Unable to open input file");
        return;
    }

    // Write file name (null-padded to 100 bytes)
    write_padded_string(output_file, filename, NAMSIZ, '\0');

    // Write file size as a plain integer followed by null padding to reach 12 bytes
    char size_str[SIZELEN];
    int size_len = snprintf(size_str, SIZELEN, "%d", file_size); // Write size as plain integer
    fwrite(size_str, sizeof(char), size_len, output_file);       // Write the size string
    for (int i = size_len; i < SIZELEN; ++i) {                   // Pad remaining bytes with nulls
        fputc('\0', output_file);
    }

    // Copy file content to archive
    char buffer[RECORDSIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <input_files...>\n", argv[0]);
        return 1;
    }

    FILE* output_file = fopen("Result.tar", "wb");
    if (!output_file) {
        perror("Unable to create output file");
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        write_file_to_archive(output_file, argv[i]);
    }

    fclose(output_file);
    printf("Archive created successfully: Result.tar\n");

    return 0;
}
