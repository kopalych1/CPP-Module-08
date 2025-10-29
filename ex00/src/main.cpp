/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:00:41 by akostian          #+#    #+#             */
/*   Updated: 2025/10/29 14:54:57 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "colors.hpp"
#include "easyfind.hpp"

/* printing templates */
template <typename T>
std::ostream& operator<<(std::ostream& os, std::list<T> lst) {
	os << '[';
	for (; lst.size();) {
		os << colors::cyan << lst.front() << colors::reset;
		if (lst.size() != 1) os << ", ";
		lst.pop_front();
	}
	os << ']';

	return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	os << '[';
	for (size_t i = 0; i < vec.size(); ++i) {
		os << colors::cyan << vec[i] << colors::reset;
		if (i + 1 < vec.size()) os << ", ";
	}
	os << ']';

	return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& dq) {
	os << '[';
	for (size_t i = 0; i < dq.size(); ++i) {
		os << colors::cyan << dq[i] << colors::reset;
		if (i + 1 < dq.size()) os << ", ";
	}
	os << ']';

	return os;
}

int main(void) {
	{
		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(42);
		vec.push_back(2);

		std::cout << colors::magenta_bbold << *easyfind(vec, 42) << colors::reset << " found in " << vec << "\n";

		try {
			std::cout << *easyfind(vec, 233) << "\n";
		} catch (const std::exception& e) {
			std::cerr << colors::magenta << 233 << colors::reset << ": " << colors::red_bbold << e.what()
			          << colors::reset << '\n';
		}
	}
	{
		std::list<int> lst;

		lst.push_back(0);
		lst.push_back(52);
		lst.push_back(2);

		std::cout << colors::magenta_bbold << *easyfind(lst, 52) << colors::reset << " found in " << lst << "\n";

		try {
			std::cout << *easyfind(lst, 89) << "\n";
		} catch (const std::exception& e) {
			std::cerr << colors::magenta << 89 << colors::reset << ": " << colors::red_bbold << e.what()
			          << colors::reset << '\n';
		}
	}
	{
		std::deque<int> dq;

		dq.push_back(255);
		dq.push_back(0);
		dq.push_back(2);

		std::cout << colors::magenta_bbold << *easyfind(dq, 255) << colors::reset << " found in " << dq << "\n";

		try {
			std::cout << *easyfind(dq, -22) << "\n";
		} catch (const std::exception& e) {
			std::cerr << colors::magenta << -22 << colors::reset << ": " << colors::red_bbold << e.what()
			          << colors::reset << '\n';
		}
	}
}
