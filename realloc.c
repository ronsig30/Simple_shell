#include "shell.h"

/**
 * _memset - Fills memory with a constant byte.
 * @dest: Pointer to the memory area to be filled.
 * @byte: The byte value to fill the memory with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area 'dest'.
 */
char *_memset(char *dest, char byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = byte;
	return (dest);
}

/**
 * free_string_array - Frees an array of strings.
 * @str_array: The array of strings to be freed.
 */
void free_string_array(char **str_array)
{
	char **temp = str_array;

	if (!str_array)
		return;
	while (*str_array)
		free(*str_array++);
	free(temp);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previously allocated block of memory.
 * @old_size: Size in bytes of the previous block.
 * @new_size: Size in bytes of the new block.
 *
 * Return: A pointer to the newly allocated block of memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new_ptr);
}

