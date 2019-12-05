/**
 * AoC 2019 Day 2, intcode computer
 *
 * File              : intcode.h
 * Author            : Mikael Berglund <mikael.berglund2@gmail.com>
 * Date              : 05.12.2019
 * Last Modified Date: 05.12.2019
 * Last Modified By  : Mikael Berglund <mikael.berglund2@gmail.com>
 */

#ifndef INTCODE_H
# define INTCODE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

int		readcode(char *filenme, int **codep);

#endif
