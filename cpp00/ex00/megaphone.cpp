/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:21:54 by heolivei          #+#    #+#             */
/*   Updated: 2024/04/25 13:22:04 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
		if (argc == 1)
				std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		else
		{
				for (int i = 1; i < argc; i++)
						for (int j = 0; argv[i][j] != '\0'; j++)
								std::cout << (char)(argv[i][j] >= 'a' && argv[i][j] <= 'z'
										? argv[i][j] - 32 : argv[i][j]);
		}
		std::cout << std::endl;
		return 0;
}
