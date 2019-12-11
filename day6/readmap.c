#include "uom.h"

static int	convert(char *mapstr, t_edge ***mapp)
{
	int			len;
	int			i;
	char		*tmp;
	t_edge		**map;
	t_edge		*edge;

	len = 0;
	tmp = mapstr;
	while (*tmp != '\0')
		if (*tmp++ == '\n')
			++len;
	if (!(map = (t_edge**)malloc(sizeof(t_edge*) * len)))
		return (0);
	
	i = 0;
	while (i < len)
	{
		if (!(edge = (t_edge*)malloc(sizeof(t_edge))) ||
			!(tmp = strchr(mapstr, ')')))
			return (0);
		edge->src = strndup(mapstr, tmp - mapstr);
		mapstr = tmp;
		tmp = strchr(mapstr, '\n');
		edge->trg = strndup(mapstr + 1, tmp - (mapstr + 1)); 
		edge->visited = 0;
		edge->orbits = 0;
		map[i] = edge;
		if (tmp)
			mapstr = (tmp + 1);
		++i;
	}
	
	*mapp = map;
	return (len);
}

int			readmap(char *filename, t_edge ***mapp)
{
	char	buff[100001];
	int		fd;
	ssize_t	br;

	if (filename == NULL)
		fd = 0;
	else if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if (!(br = read(fd, buff, 100000)))
		return (0);
	buff[br] = '\0';

	int len = convert(buff, mapp);
	return (len);
}
