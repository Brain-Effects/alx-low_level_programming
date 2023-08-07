#ifndef MAIN_H
#define MAIN_H

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void check_args(int argc);
void open_files(char *argv[], int *fd_from, int *fd_to);
void copy_file(int fd_from, int fd_to, char *argv[]);
void close_files(int fd_from, int fd_to);
int main(int argc, char *argv[]);
void open_file(char *argv[], int *fd);
void read_elf_header(int fd, Elf64_Ehdr *ehdr);
void check_elf_header(Elf64_Ehdr *ehdr);
void print_magic(Elf64_Ehdr *ehdr);
void print_class(Elf64_Ehdr *ehdr);
void print_data(Elf64_Ehdr *ehdr);
void print_version(Elf64_Ehdr *ehdr);
void print_osabi(Elf64_Ehdr *ehdr);
void print_abiversion(Elf64_Ehdr *ehdr);
void print_type(Elf64_Ehdr *ehdr);
void print_entry(Elf64_Ehdr *ehdr);

#endif /* MAIN_H */
