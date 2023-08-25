#include "main.h"

/**
 * free_glob -frees the global variables
 *
 * Return: no return
 */
void free_glob(void)
{
	free_list(glob.head);
	free(glob.buff);
	free(glob.fdis);
}

/**
 * start_glob - initialize the global variables
 *
 * @fdis: file desciptor
 * Return: no return
 */

void start_glob(FILE *fdis)
{
	glob.lifo = 1;
	glob.curr = 1;
	glob.sec = NULL;
	glob.head = NULL;
	glob.fdis = fdis;
	glob.buff = NULL;
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdis;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fdis = fopen(argv[1], "r");
	if (!fdis)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	start_glob(fdis);
	nlines = getline(&glob.buff, &size, fdis);
	while (nlines != -1)
	{
		lines[0] = strtok(glob.buff, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob.curr);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glob();
				exit(EXIT_FAILURE);
			}
			glob.sec = strtok(NULL, " \t\n");
			f(&glob.head, glob.curr);
		}
		nlines = getline(&glob.buff, &size, fdis);
		glob.curr++;
	}
	free_glob();
	fclose(fdis);
}
