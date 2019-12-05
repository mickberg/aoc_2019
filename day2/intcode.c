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

void	exec_intcode(int len, int *intcode)
{
	int		i;
	int		opcode;
	int		arg1, arg2, arg3;

	i = 0;
	while (intcode[i] != 99 && i < len)
	{
		opcode = intcode[i];
		arg1 = intcode[i + 1];
		arg2 = intcode[i + 2];
		arg3 = intcode[i + 3];

		if (opcode == 1)
			intcode[arg3] = (intcode[arg1] + intcode[arg2]);
		else if (opcode == 2)
			intcode[arg3] = (intcode[arg1] * intcode[arg2]);
		else
			break;
		i += 4;
	}
}

int		main(int argc, char **argv)
{
	int len;
	int	*intcode;
	int	*intcode_cpy;

	if (argc < 2)
		return (0);

	// parse code from file
	if ((len = readcode(argv[1], &intcode)) < 1)
		return (0);

	// reset to error state 1202
	intcode[1] = 12;
	intcode[2] = 2;

	if (!(intcode_cpy = (int*)malloc(sizeof(int) * len)))
		return (0);

	// execute code
	memcpy(intcode_cpy, intcode, sizeof(int) * len);
	exec_intcode(len, intcode_cpy);
	printf("Part 1: %d\n", intcode_cpy[0]);

	int ix = 0;
	int jx = 0;
	while (ix < 99)
	{
		jx = 0;
		while (jx < 99)
		{
			memcpy(intcode_cpy, intcode, sizeof(int) * len);
			intcode_cpy[1] = ix;
			intcode_cpy[2] = jx;
			exec_intcode(len, intcode_cpy);
			if (intcode_cpy[0] == 19690720)
			{
				printf("Part 2: %d\n", 100 * ix + jx);
				break ;
			}
			++jx;
		}
		++ix;
	}
	return (0);
}
