#include <stdio.h>

/**
 * __attribute__ - prints ou're beat! and yet, you must allow,\nI ... etc
 *
 * Return: nothing
 */
void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
