/**
 * Advent of Code, day 6, part 1
 * Universal orbital map
 *
 * File              : uom.c
 * Author            : Mikael Berglund <mikael.berglund2@gmail.com>
 * Date              : 07.12.2019
 * Last Modified Date: 07.12.2019
 * Last Modified By  : Mikael Berglund <mikael.berglund2@gmail.com>
 */

#include "uom.h"	

void	print_map(int len, t_edge **map)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%s - %s, orbits %d\n", map[i]->src, map[i]->trg, map[i]->orbits);
		++i;
	}
}

void	visit(int len, t_edge **map, t_edge *cedge, int count)
{
	int	i;

	cedge->visited = 1;
	cedge->orbits = count;

	i = 0;
	while (i < len)
	{
		if (strcmp(map[i]->src, cedge->trg) == 0 && !map[i]->visited)
			visit(len, map, map[i], count + 1);
		++i;
	}
}

int		reduce_map(int len, t_edge **map)
{
	int i;
	int	sum;

	// find COM (first node)
	i = 0;
	while (i < len && strcmp(map[i]->src, "COM") != 0)
		++i;
	
	visit(len, map, map[i], 1);

	i = 0;
	sum = 0;
	while (i < len)
		sum += map[i++]->orbits;

	return (sum);
}

int		main(int argc, char **argv)
{
	t_edge	**mapp;
	int		len;
	int		orbits;

	if (argc != 2)
		return (0);

	len = readmap(argv[1], &mapp);
	orbits = reduce_map(len, mapp);

	printf("orbits %d\n", orbits);
	return (0);
}
