#include "main.h"

/**
 * main - Copy the content of one file to another
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
  
    int fd_from, fd_to;
    ssize_t r_count, w_count;
    char buffer[1024];


    off_t offset = 0;

    if (argc != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

   
    lseek(fd_from, offset, SEEK_SET);

    do
    {
        r_count = read(fd_from, buffer, 1024);
        if (r_count == -1)
        {
            dprintf(2, "Error: Can't read from file %s\n", argv[1]);
            close(fd_from);
            close(fd_to);
            exit(98);
        }

      
        offset += r_count;

        w_count = write(fd_to, buffer, r_count);
        if (w_count == -1 || w_count != r_count)
        {
            dprintf(2, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
			exit(99);
		}
	} while (r_count > 0);

	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

