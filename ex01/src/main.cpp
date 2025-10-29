/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:13:27 by akostian          #+#    #+#             */
/*   Updated: 2025/10/29 15:18:29 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ctime>
#include <iostream>

#include "Span.hpp"

// #include <cstdlib>

// class Generator
// {
// 	public:
// 		static int	genInt(const int min, const int max) { return min + std::rand() % (max - min + 1);}
// 		static int	genInt() { return genInt(0, RAND_MAX);}
// };

template <typename T>
void printArray(T arr, size_t size) {
	std::cout << '[';
	for (size_t i = 0; i < size; i++) std::cout << arr[i] << ((i + 1 < size) ? ", " : "");
	std::cout << ']';
}

int main() {
	// std::srand(std::time(0));
	// {
	// 	std::cout << "\nRandom values test:\n" << "\n";
	// 	for (size_t i = 0; i < 10; i++)
	// 		std::cout << Generator::genInt(0, 100) << "\n";
	// }
	{
		std::cout << "\nClock test:\n"
		          << "\n";

		std::clock_t start, end;

		start = std::clock();
		usleep(50000);
		end = std::clock();
		std::cout << "Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
	}
	{
		std::cout << "\nBig amount test:\n"
		          << "\n";

		std::clock_t start, end;

		Span a(100 * 1000);

		start = std::clock();
		for (size_t i = 0; i < 100 * 1000; i++) a.addNumber(i);
		end = std::clock();

		std::cout << "Elapsed: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";

		std::cout << "a.longestSpan():\t" << a.longestSpan() << "\n";
		std::cout << "a.shortestSpan():\t" << a.shortestSpan() << "\n";
	}
	{
		std::cout << "\nBasic test:\n"
		          << "\n";

		Span span(10);

		span.addNumber(1);
		span.addNumber(5);
		span.addNumber(55);

		std::cout << "span.longestSpan():\t" << span.longestSpan() << "\n";
		std::cout << "span.shortestSpan():\t" << span.shortestSpan() << "\n";
	}
	{
		std::cout << "\nVectors insertion:\n"
		          << "\n";

		std::vector<int> a;
		std::vector<int> b;

		b.push_back(2);
		b.push_back(4);
		b.push_back(6);
		b.push_back(8);
		b.push_back(10);

		a.push_back(1);
		a.push_back(3);
		a.push_back(5);
		a.push_back(7);
		a.push_back(9);

		std::cout << "a: ";
		printArray(a, a.size());
		std::cout << "\n";
		std::cout << "b: ";
		printArray(b, b.size());
		std::cout << "\n";

		// To show how vector insert() works
		a.insert(a.begin() + a.size(), b.begin(), b.end());

		std::cout << "a: ";
		printArray(a, a.size());
		std::cout << "\n";

		// Now the same with span
		Span smallSpan(5);
		Span span(20);

		try {
			smallSpan.addNumbers(a.begin(), a.end());
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		span.addNumber(-42);
		span.addNumber(0);
		span.addNumbers(a.begin(), a.end());
		span.addNumber(1000);

		std::cout << "span: " << span << "\n";

		std::cout << "span.longestSpan():\t" << span.longestSpan() << "\n";
		std::cout << "span.shortestSpan():\t" << span.shortestSpan() << "\n";
	}
}
