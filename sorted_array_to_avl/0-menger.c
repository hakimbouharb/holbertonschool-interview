#include "menger.h"

/**
 * pchar - pchar
 * @row: int
 * @column: int
 * Return: char
 */
char pchar(size_t row, size_t column)
{
	while (row && column)
	{
		if (row % 3 == 1 && column % 3 == 1)
			return (' ');
		row /= 3, column /= 3;
	}
	return ('#');
}


/**
 * menger - menger
 * @level: int
 * Return: none
 */
void menger(int level)
{
	size_t size, row, column;

	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; ++row)
	{
		for (column = 0; column < size; ++column)
			putchar(pchar(row, column));
		putchar('\n');
	}
}
