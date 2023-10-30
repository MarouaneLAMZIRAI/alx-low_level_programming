#include "main.h"

/**
 * append_text_to_file - Append text to the end of a file
 * @filename: The name of the file to append to
 * @text_content: The content to append to the file (NULL terminated string)
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, w_count, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;

		w_count = write(fd, text_content, len);
		if (w_count == -1 || w_count != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
