#include "../lib/libft/libft.h"

/* Test code */
int	main(int ac, char **av)
{
	int	i = -1;
	while (++i < ac)
		ft_putendl_fd(av[i], 1);

}
