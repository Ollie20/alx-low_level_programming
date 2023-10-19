#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_elf - function to check for ELF file.
 * @e_ident: A pointer to an array
 *
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - function to print the magic nums
 * @e_ident: pointer
 *
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - function to print class
 * @e_ident: pointer
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - function to print the data
 * @e_ident: pointer
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - function to print the version
 * @e_ident: A pointer to an array
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * get_osabi_name - get name of osabi
 * @osabi: name
 *
 * Return: On success, NULL otherwise fail
 */
const char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_NONE: return "UNIX - System V";
		case ELFOSABI_HPUX: return "UNIX - HP-UX";
		case ELFOSABI_NETBSD: return "UNIX - NetBSD";
		case ELFOSABI_LINUX: return "UNIX - Linux";
		case ELFOSABI_SOLARIS: return "UNIX - Solaris";
		case ELFOSABI_IRIX: return "UNIX - IRIX";
		case ELFOSABI_FREEBSD: return "UNIX - FreeBSD";
		case ELFOSABI_TRU64: return "UNIX - TRU64";
		case ELFOSABI_ARM: return "ARM";
		case ELFOSABI_STANDALONE: return "Standalone App";
		default: return NULL;
	}
}
/**
 * print_osabi - function to print the OS/ABI
 * @e_ident: A pointer to an array
 */
void print_osabi(unsigned char *e_ident)
{
	const char *osabi_name;

	printf("  OS/ABI:                            ");
	osabi_name = get_osabi_name(e_ident[EI_OSABI]);
	if (osabi_name)
	{
		printf("%s\n", osabi_name);
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abreviation - function to print abreviation
 * @e_ident: pointer
 */
void print_abreviation(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - function to print type
 * @e_type: elf type.
 * @e_ident: pointer
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - function to print entry point
 * @e_entry: address
 * @e_ident: pointer to an array
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes ELF file.
 * @elf: The file descriptor
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
/**
 * print_elf_header - prints elf headers
 * @header: pointer
 *
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abreviation(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
}
/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The num of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success otherwise fail
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd;
	ssize_t read_byte;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_byte = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_byte == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	print_elf_header(header);
	free(header);
	close_elf(fd);
	return (0);
}
