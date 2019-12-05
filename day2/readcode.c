#include "intcode.h"

static int	convert(char *codestr, int **codep)
{
	int		len;
	int		i;
	char	*tmp;
	int		*code;

	len = 1;
	tmp = codestr;
	while (*tmp != '\0')
		if (*tmp++ == ',')
			++len;

	if (!(code = (int*)malloc(sizeof(int) * (len))))
		return (0);
	
	i = 0;
	while (i < len)
	{
		code[i] = atoi(codestr);
		tmp = strchr(codestr, ',');
		if (tmp)
			codestr = (tmp + 1);
		++i;
	}

	*codep = code;
	return (len);
}

int			readcode(char *filename, int **codep)
{
	char	buff[1001];
	int		fd;
	ssize_t	br;

	if ((fd = open(filename, O_RDONLY)) < 0 ||
		!(br = read(fd, buff, 1000)))
		return (0);
	buff[br] = '\0';

	int len = convert(buff, codep);
	return (len);
}
