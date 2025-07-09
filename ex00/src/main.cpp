/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:00:41 by akostian          #+#    #+#             */
/*   Updated: 2025/07/09 04:36:48 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	{
		std::vector<int> vec(3);

		vec[0] = 1;
		vec[1] = 42;
		vec[2] = 2;

		std::cout << *easyfind(vec, 42) << "\n";

		try {
			std::cout << *easyfind(vec, 233) << "\n";
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::list<int>	lst(3);

		lst.push_front(0);
		lst.push_front(52);
		lst.push_front(2);

		std::cout << *easyfind(lst, 52) << "\n";

		try {
			std::cout << *easyfind(lst, 233) << "\n";
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::deque<int>	dq(3);

		dq.push_front(255);
		dq.push_front(0);
		dq.push_front(2);

		std::cout << *easyfind(dq, 255) << "\n";

		try {
			std::cout << *easyfind(dq, 233) << "\n";
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}
