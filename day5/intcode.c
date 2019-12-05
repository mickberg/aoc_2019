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

// Print integer array function used for testing
void	print_code(int len, int *intcode)
{
	int		i;

	printf("%d", intcode[0]);
	i = 1;
	while (i < len)
		printf(", %d", intcode[i++]);
	printf("\n");
}

// Get pointer to parameter based on mode
// mode 1: parameter points to own value
// mode 0: parameter points to index of intcode[pos]'s value
int		*get_parameter(int *intcode, int *pos, int mode)
{
	if (mode == 1)
		return (pos);
	else if (mode == 0)
		return (&(intcode[ *pos ]));
	else
		return (NULL);
}

// Read and execute intcode
void	exec_intcode(int *intcode)
{
	int		opcode;
	int		*arg1, *arg2, *respointer;
	int		*input;
	int		*instrp;

	instrp = intcode;
	while (*instrp != 99)
	{
		// opcode is first 2 digits 
		opcode = *instrp % 100;

		// Get parameter for arguments
		arg1 = get_parameter(intcode, instrp + 1, *instrp / 100 % 10);
		arg2 = get_parameter(intcode, instrp + 2, *instrp / 1000 % 10);
		// res pointer (where the result will be stored)
		// SHOULD always be in position mode
		respointer = get_parameter(intcode, instrp + 3, *instrp / 10000 % 10);

		// opcode 1: add arg1 and arg2 and put sum in respointer's address
		if (opcode == 1)
			*respointer = (*arg2 + *arg1);
		// opcode 1: multiply arg1 and arg2 and put result in respointer's address
		else if (opcode == 2)
			*respointer = (*arg2 * *arg1);
		// read input and put in arg1's address
		else if (opcode == 3)
		{
			if (!readcode(NULL, &input))
				exit(0);
			*arg1 = input[0];
			instrp += 2;
			continue ;;
		}
		// output value at arg1
		else if (opcode == 4)
		{
			printf(">%d\n", *arg1);
			instrp += 2;
			continue ;
		}
		else 
		{
			printf("Something wrong with the code?? opcode: %d\n", opcode);
			break;
		}
		
		// each block of code is 4 indexes long (except input and output which are 2 long)
		instrp += 4;
	}
}

int		main(int argc, char **argv)
{
	int len;
	int	*intcode;

	if (argc < 2)
		return (0);

	// Read code from file and convert it to an integer array
	if ((len = readcode(argv[1], &intcode)) < 1)
		return (0);

	// execute code
	exec_intcode(intcode);
	
	// print executed code for testing
	print_code(len, intcode);
	return (0);
}
