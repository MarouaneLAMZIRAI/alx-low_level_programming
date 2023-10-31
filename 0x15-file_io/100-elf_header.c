#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

void print_class(unsigned char elf_class)
{
	printf("  Class:                             ");
	switch (elf_class)
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %02x>\n", elf_class);
			break;
	}
}

void print_data(unsigned char elf_data)
{
	printf("  Data:                              ");
	switch (elf_data)
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %02x>\n", elf_data);
			break;
	}
}

void print_version(unsigned char elf_version)
{
	printf("  Version:                           %u ", elf_version);
	printf("(current)\n");

}

void print_osabi(unsigned char osabi)
{
	char *osabi_name = "<unknown>";  /* Default OS/ABI name */

	switch (osabi)
	{
		case ELFOSABI_NONE:
			osabi_name = "UNIX - System V";
			break;
		case ELFOSABI_HPUX:
			osabi_name = "UNIX - HP-UX";
			break;
		case ELFOSABI_NETBSD:
			osabi_name = "UNIX - NetBSD";
			break;
		case ELFOSABI_LINUX:
			osabi_name = "UNIX - Linux";
			break;
		case ELFOSABI_SOLARIS:
			osabi_name = "UNIX - Solaris";
			break;
		case ELFOSABI_AIX:
			osabi_name = "AIX";
			break;
		case ELFOSABI_IRIX:
			osabi_name = "IRIX";
			break;
		case ELFOSABI_FREEBSD:
			osabi_name = "UNIX - FreeBSD";
			break;
		case ELFOSABI_TRU64:
			osabi_name = "UNIX - TRU64";
			break;
		case ELFOSABI_MODESTO:
			osabi_name = "Novell - Modesto";
			break;
		case ELFOSABI_OPENBSD:
			osabi_name = "UNIX - OpenBSD";
			break;
		case ELFOSABI_ARM_AEABI:
			osabi_name = "ARM - EABI";
			break;
		case ELFOSABI_ARM:
			osabi_name = "ARM";
			break;
		default:
			osabi_name = "<unknown>";
			break;
	}

	printf("  OS/ABI:                            %s\n", osabi_name);
}

void print_abiversion(unsigned char elf_abiversion)
{
	printf("  ABI Version:                       %u\n", elf_abiversion);
}

void print_type(uint16_t e_type)
{
	char *type_name = "NONE";  /* Default type name */

	switch (e_type)
	{
		case ET_NONE:
			type_name = "NONE";
			break;
		case ET_REL:
			type_name = "REL (Relocatable file)";
			break;
		case ET_EXEC:
			type_name = "EXEC (Executable file)";
			break;
		case ET_DYN:
			type_name = "DYN (Shared object file)";
			break;
		case ET_CORE:
			type_name = "CORE (Core file)";
			break;
		case ET_LOPROC:
			type_name = "<unknown: LOPROC>";
			break;
		case ET_HIPROC:
			type_name = "<unknown: HIPROC>";
			break;
		default:
			type_name = "<unknown>";
			break;
	}

	printf("  Type:                              %s\n", type_name);
}

void print_entry(uint64_t e_entry)
{
	printf("  Entry point address:               ");
	printf("0x%lx\n", (unsigned long)e_entry);
}

int handle_error(const char *filename)
{
	dprintf(2, "Error: Not an ELF file: %s\n", filename);
	return (98);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Cannot read file: %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
		return (handle_error(argv[1]));

	if (ehdr.e_ident[0] != ELFMAG0 || ehdr.e_ident[1] != ELFMAG1 ||
		ehdr.e_ident[2] != ELFMAG2 || ehdr.e_ident[3] != ELFMAG3)
		return (handle_error(argv[1]));

	printf("ELF Header:\n");
	print_magic(ehdr.e_ident);
	print_class(ehdr.e_ident[EI_CLASS]);
	print_data(ehdr.e_ident[EI_DATA]);
	print_version(ehdr.e_ident[EI_VERSION]);
	print_osabi(ehdr.e_ident[EI_OSABI]);
	print_abiversion(ehdr.e_ident[EI_ABIVERSION]);
	print_type(ehdr.e_type);
	print_entry(ehdr.e_entry);

	close(fd);
	return (0);
}
