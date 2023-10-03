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
