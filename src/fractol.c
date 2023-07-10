#include "fractol.h"

/* type_cmp:
 * 	Parses the given fractial type argument and checks against
 *	the name (i.e. "julia"), the associated letter (i.e. "J")
 *	and the associated number (i.e. "2").
 *	Returns true if the argument matches one of these requirements,
 *	false if not.
 */

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

/* get_set:
 * 	Retrieves the set specified in program arguments.
 * 	If no valid set was provided, it displays a help
 * 	message and quits the program.
 */

static void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->set = MANBDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (type_cmp(av[1], "burning ship", 'b', '3'))
		f->set = BURNING_SHIP;
	else if (type_cmp(av[1], "tricorn", 't', '4'))
		f->set = TRICORN;
	else if (type_cmp(av[1], "mandelbox", 'x', '5'))
		f->set = MANDELBOX;
	else
		// help_msg(f);
}

/* handle_args:
 * 	Retrieves the set, the julia starting values and the color from
 * 	the arguments passed at the program launch.
 */

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		// help_msg(f);
	else if (f->set == JULIA && ac > 5)
		// help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
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
