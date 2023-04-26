#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer void
 * @old_size: unsigned int
 * @new_size: unsigned int
 *
 * Return: the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, tp = new_size;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size > old_size)
		tp = old_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);

	for (i = 0; i < tp; i++)
	{
		p[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (p);
}

