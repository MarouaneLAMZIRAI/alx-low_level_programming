#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define EI_NIDENT 16

/**
 * print_elf_header - Prints the ELF header information.
 * @ehdr: Pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", ehdr->e_ident[i]);
        if (i != EI_NIDENT - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    printf("  Class:    %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:     %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:   %d (current)\n", ehdr->e_ident[EI_VERSION]);
    printf("  OS/ABI:   %s\n", ehdr->e_ident[EI_OSABI] == ELFOSABI_UNIX ? "UNIX - System V" : "<unknown>");
    printf("  ABI Version:   %d\n", ehdr->e_ident[EI_ABIVERSION]);
    printf("  Type:      %s\n", ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" : "<unknown>");
    printf("  Entry point address:               0x%lx\n", ehdr->e_entry);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(98);
    }

    // Read the ELF header.

    Elf64_Ehdr ehdr;
    int nread = read(fd, &ehdr, sizeof(ehdr));
    if (nread != sizeof(ehdr))
    {
        perror("read");
        exit(98);
    }

    // Check if the file is an ELF file.

    if (!ElfW(valid_magic)(&ehdr))
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

    // Print the ELF header.

    print_elf_header(&ehdr);

    close(fd);

    return 0;
}

