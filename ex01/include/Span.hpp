/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:10:23 by akostian          #+#    #+#             */
/*   Updated: 2025/07/12 05:18:13 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

# include <vector>

# include <stdexcept>

# include <algorithm>
# include <climits>
# include <numeric>

class Span {
	private:
		std::vector<int>	elems_;
		const unsigned int	max_size_;
		unsigned int		size_;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		friend std::ostream& operator<<(std::ostream& os, const Span& span);

		void			addNumber(int num);
		void			addNumbers(
							const std::vector<int>::iterator &begin,
							const std::vector<int>::iterator &end
		);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif // SPAN_HPP