/**
 * AoC 2019 Day 2, intcode computer
 *
 * File              : intcode.c
 * Author            : Mikael Berglund <mikael.berglund2@gmail.com>
 * Date              : 05.12.2019
 * Last Modified Date: 05.12.2019
 * Last Modified By  : Mikael Berglund <mikael.berglund2@gmail.com>
 */

#include "intcode.h"

void	print_code(int len, int *intcode)
{
	int i;

	printf("%d", intcode[0]);
	i = 1;
	while (i < len)
		printf(", %d", intcode[i++]);
	printf("\n");
}

void	exec_intcode(int len, int *intcode)
{
	int		i;

	i = 0;
	while (intcode[i] != 99 && i < len)
	{
		if (intcode[i] == 1)
			intcode[ intcode[i + 3] ] = intcode[ intcode[i + 1] ] + intcode[ intcode[i + 2] ];
		else if (intcode[i] == 2)
			intcode[ intcode[i + 3] ] = intcode[ intcode[i + 1] ] * intcode[ intcode[i + 2] ];
		else
			break;
		i += 4;
	}
}

int		main(int argc, char **argv)
{
	int len;
	int	*intcode;

	if (argc < 2)
		return (0);

	// parse code from file
	if ((len = readcode(argv[1], &intcode)) < 1)
		return (0);

	// execute code
	exec_intcode(len, intcode);
	print_code(len, intcode);

	return (0);
}
