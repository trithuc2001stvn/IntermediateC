// CH09: fgetline.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	FILE * stream;
	char * line = NULL;
	size_t len = 0;
	ssize_t nread;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		printf("Fail open file");
		return EXIT_FAILURE;
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("Retrieved line of length %zu: \n", nread);
		fwrite(line, nread, 1, stdout);
	}
	free(line);
	fclose(stream);
	return EXIT_SUCCESS;
}
