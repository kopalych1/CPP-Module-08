/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:35:15 by akostian          #+#    #+#             */
/*   Updated: 2025/10/29 15:18:19 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main(void) {
	{
		MutantStack<int> a;

		a.push(-42);
		a.push(0);
		a.push(42);

		std::cout << "*a.begin(): " << *a.begin() << "\n";
		std::cout << "*a.end(): " << *(a.end() - 1) << "\n";

		MutantStack<int>::iterator it;

		std::cout << "a: " << a << "\n";
	}
	{
		MutantStack<std::string> a;

		a.push("123");
		a.push("HELLO");
		a.push("Campus");

		std::cout << "a: " << a << "\n";

		std::cout << "*a.begin(): " << *a.begin() << "\n";
		std::cout << "*a.end(): " << *(a.end() - 1) << "\n";
	}
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "mstack.size(): " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
}
