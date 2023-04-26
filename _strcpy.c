#include "shell.h"

/**
 * _strcpy - copies a string from
 * a source to another pointer to chars
 * @dest: the pointer copy to
 * @src: source to copy from
 * Return: a pointer to the dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = strlen(src); /* gets the length of the src string */
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return (dest);
}
