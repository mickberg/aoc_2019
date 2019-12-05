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
	int		i;

	printf("%d", intcode[0]);
	i = 1;
	while (i < len)
		printf(", %d", intcode[i++]);
	printf("\n");
}

int		*get_parameter(int *intcode, int pos, int mode)
{
	if (mode == 1)
		return (intcode + pos);
	else if (mode == 0)
		return (&(intcode[ intcode[pos] ]));
	else
		return (NULL);
}

void	exec_intcode(int len, int *intcode)
{
	int		i;
	int		opcode;
	int		*arg1, *arg2, *arg3;

	i = 0;
	while (intcode[i] != 99)
	{
		opcode = intcode[i] % 100;

		arg1 = get_parameter(intcode, i + 1, intcode[i] / 100 % 10);
		arg2 = get_parameter(intcode, i + 2, intcode[i] / 1000 % 10);
		arg3 = get_parameter(intcode, i + 3, intcode[i] / 10000 % 10);

		if (opcode == 1)
			*arg3 = (*arg2 + *arg1);
		else if (opcode == 2)
			*arg3 = (*arg2 * *arg1);
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
