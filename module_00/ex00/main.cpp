#include <iostream>

int	main(int argc, char **argv)
{
	int		i = 0;
	int		b = 1;
	char	c;

	if (argc > 1)
	{
		while (b < argc)
		{
			i = 0;
			while (argv[b][i])
			{
				c = argv[b][i];
				if (argv[b][i] >= 'a' && argv[b][i] <= 'z')
				{
					c -= 32;
					std::cout << c;
				}
				else
					std::cout << c;
				i++;
			}
			b++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
