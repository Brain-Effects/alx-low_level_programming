#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

#define BUFSIZE 1024

/**
 * check_args - checks the number of arguments
 * @argc: number of arguments
 */
void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_files - opens the source and destination files
 * @argv: array of arguments
 * @fd_from: pointer to the source file descriptor
 * @fd_to: pointer to the destination file descriptor
 */
void open_files(char *argv[], int *fd_from, int *fd_to)
{
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	*fd_from = open(argv[1], O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	*fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(*fd_from);
		exit(99);
	}
}

/**
 * copy_file - copies the content of a file to another file
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @argv: array of arguments
 */
void copy_file(int fd_from, int fd_to, char *argv[])
{
	ssize_t n_read, n_written;
	char buffer[BUFSIZE];

	while ((n_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
	n_written = write(fd_to, buffer, n_read);
	if (n_written == -1 || n_written != n_read)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		close(fd_to);
		exit(99);
	}
	}

	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_files - closes the source and destination files
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - entry point for the cp program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exit with code 97, 98, 99 or 100 on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	check_args(argc);

	open_files(argv, &fd_from, &fd_to);

	copy_file(fd_from, fd_to, argv);

	close_files(fd_from, fd_to);

	return (0);
}
