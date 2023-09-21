#include <stdio.h>

/**
 * premain - Function that runs before the main function.
 *
 * Description: This function is marked with the constructor attribute,
 * so it will be executed automatically before the main function.
 * It prints a specific message to the standard output.
 */
void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
