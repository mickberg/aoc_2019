/**
 * AoC 2019 Day 6, Universal Orbital Map
 *
 * File              : intcode.h
 * Author            : Mikael Berglund <mikael.berglund2@gmail.com>
 * Date              : 05.12.2019
 * Last Modified Date: 05.12.2019
 * Last Modified By  : Mikael Berglund <mikael.berglund2@gmail.com>
 */

#ifndef UOM_H
# define UOM_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_edge
{
	char	*src;
	char	*trg;
	int		visited;
	int		orbits;
}				t_edge;

int		readmap(char *filenme, t_edge ***mapp);

#endif
