// CH14:onewaystreet.c
#include <stdio.h>
#include <stdlib.h>
int func (int dx, int dy)
{
	if (dx == 0 || dy == 0) return 1;
	return ((func(dx-1, dy) + func(dx, dy -1)));
}
int func2(int dx, int dy)
{
	if (dx == 0 && dy == 0) return 0;
	if (dx > 0 && dy == 0) return 1;
	if (dx == 0 && dy > 0) return 1;
	return (func2(dx-1, dy) + func2(dx, dy -1));
}
int main(int argc, char ** argv)
{
	if (argc < 5)
	{
		printf("Need provide arg\n");
		return EXIT_FAILURE;
	}
	int x1, y1, x2, y2;
	x1 = (int) strtol(argv[1], NULL, 10);
	y1 = (int) strtol(argv[2], NULL, 10);
	x2 = (int) strtol(argv[3], NULL, 10);
	y2 = (int) strtol(argv[4], NULL, 10);
	int dx, dy;
	int np;
	dx = x2 - x1;
	dy = y2 - y1;
	np = func2(dx, dy);
	printf("There is %d routes from x(%d, %d) to y(%d, %d).\n", np, x1, x2, y1, y2);
	return EXIT_SUCCESS;
}
