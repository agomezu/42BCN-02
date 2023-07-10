#include "fractol.h"

static void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->set = MANBDELBROT;
}

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		return (0); // help_msg(&f)
	clean_init(&f);
	handle_args(&f, ac, av);

	return (i);
}
