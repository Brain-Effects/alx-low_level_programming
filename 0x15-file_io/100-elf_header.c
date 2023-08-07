#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include "main.h"

/**
 * check_args - checks the number of arguments
 * @argc: number of arguments
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
}

/**
 * open_file - opens the ELF file
 * @argv: array of arguments
 * @fd: pointer to the file descriptor
 */
void open_file(char *argv[], int *fd)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
}

/**
 * read_elf_header - reads the ELF header from the file
 * @fd: file descriptor
 * @ehdr: pointer to the ELF header structure
 */
void read_elf_header(int fd, Elf64_Ehdr *ehdr)
{
	ssize_t n_read;

	n_read = read(fd, ehdr, sizeof(*ehdr));
	if (n_read == -1 || n_read != sizeof(*ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header\n");
		close(fd);
		exit(98);
	}
}

/**
 * check_elf_header - checks if the file is an ELF file
 * @ehdr: pointer to the ELF header structure
 */
void check_elf_header(Elf64_Ehdr *ehdr)
{
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
	ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
	ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
	ehdr->e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - prints the magic numbers of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_magic(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}

/**
 * print_class - prints the class of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_class(Elf64_Ehdr *ehdr)
{
	printf("  Class:                             ");
	switch (ehdr->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", ehdr->e_ident[EI_CLASS]);
		break;
	}
}

/**
 * print_data - prints the data encoding of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_data(Elf64_Ehdr *ehdr)
{
	printf("  Data:                              ");
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
	break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
	break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
	break;
	default:
		printf("<unknown: %x>\n", ehdr->e_ident[EI_DATA]);
	break;
	}
}

/**
 * print_version - prints the version of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_version(Elf64_Ehdr *ehdr)
{
	printf("  Version:                           %d",
	ehdr->e_ident[EI_VERSION]);

	if (ehdr->e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - prints the OS/ABI of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_osabi(Elf64_Ehdr *ehdr)
{
	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
	break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
	break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
	break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
	break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
	break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
	break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
	break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
	break;
	case ELFOSABI_ARM:
		printf("ARM\n");
	break;
	case ELFOSABI_STANDALONE:
		printf("Standalone (embedded) application\n");
	break;
	default:
		printf("<unknown: %x>\n", ehdr->e_ident[EI_OSABI]);
	break;
	}
}

/**
 * print_abiversion - prints the ABI version of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_abiversion(Elf64_Ehdr *ehdr)
{
	printf("  ABI Version:                       %d\n",
	ehdr->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_type(Elf64_Ehdr *ehdr)
{
	printf("  Type:                              ");
	switch (ehdr->e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
	break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
	break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
	break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
	break;
	case ET_CORE:
		printf("CORE (Core file)\n");
	break;
	default:
	if (ehdr->e_type >= ET_LOPROC)
		printf("Processor Specific: (%x)\n", ehdr->e_type);
	else if ((ehdr->e_type >= ET_LOOS) && (ehdr->e_type <= ET_HIOS))
		printf("OS Specific: (%x)\n", ehdr->e_type);
	else
		printf("<unknown: %x>\n", ehdr->e_type);
	}
}


/**
 * print_entry - prints the entry point address of the ELF header
 * @ehdr: pointer to the ELF header structure
 */
void print_entry(Elf64_Ehdr *ehdr)
{
	printf("  Entry point address:               %#lx\n", ehdr->e_entry);
}

/**
 * main - entry point for the elf_header program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exit with code 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	check_args(argc);

	open_file(argv, &fd);

	read_elf_header(fd, &ehdr);

	check_elf_header(&ehdr);

	print_magic(&ehdr);

	print_class(&ehdr);

	print_data(&ehdr);

	print_version(&ehdr);

	print_osabi(&ehdr);

	print_abiversion(&ehdr);

	print_type(&ehdr);

	print_entry(&ehdr);

	close(fd);

	return (0);
}
