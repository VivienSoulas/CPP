/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:25:02 by vsoulas           #+#    #+#             */
/*   Updated: 2025/10/02 19:54:31 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

// << std::endl clears buffer and creates new line
int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string arg(av[i]);
			for (size_t j = 0; j < arg.length(); j++)
				arg[j] = std::toupper(arg[j]);
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return (0);
}