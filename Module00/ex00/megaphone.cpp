/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:25:02 by vsoulas           #+#    #+#             */
/*   Updated: 2025/09/26 13:42:47 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// << std::endl clears buffer and creates new line
int	main(int ac, char **av)
{
	int	i = 1;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] == ' ' && j == 0)
				{
					while (av[i][j] == ' ' && av[i][j])
						j++;
				}
				std::cout << (char)std::toupper(av[i][j]);
				if (av[i][j + 1] == ' ' && av[i][j + 2] == '\0')
					j++;
				j++;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}