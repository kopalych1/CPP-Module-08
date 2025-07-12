/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:13:29 by akostian          #+#    #+#             */
/*   Updated: 2025/07/13 01:05:35 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span() :
	elems_(0),
	max_size_(0),
	size_(0)
{
}

Span::Span(unsigned int N) :
	elems_(N),
	max_size_(N),
	size_(0)
{
}

Span::Span(const Span& other) :
	elems_(other.elems_),
	max_size_(other.max_size_),
	size_(other.size_)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		if (this->max_size_ < other.max_size_)
			throw std::out_of_range("Cannot assign: source Span is larger than destination Span");

		this->elems_ = other.elems_;
		this->size_ = other.size_;
	}
	return *this;
}

Span::~Span()
{
}


std::ostream	&operator<<(std::ostream& os, const Span& span)
{
	os << '[';
	for (size_t i = 0; i < span.size_; i++)
		os << static_cast<int>(span.elems_[i]) << ((i + 1 < span.size_) ? ", ": "");
	os << ']';

	return os;
}


void			Span::addNumber(int num)
{
	if (size_ >= this->max_size_)
		throw std::out_of_range("Span::addNumber: cannot add more numbers, span is full");

	this->elems_[this->size_++] = num;
}

unsigned int	Span::shortestSpan() const
{
	if (this->size_ < 2)
		throw std::length_error("Span::shortestSpan: need at least two numbers to compute a span");

	std::vector<int>	tmp(this->elems_);

	std::sort(tmp.begin(), tmp.begin() + this->size_);
	std::adjacent_difference(tmp.begin(), tmp.begin() + this->size_, tmp.begin());

	return *std::min_element(tmp.begin() + 1, tmp.begin() + this->size_);
}

unsigned int	Span::longestSpan() const
{
	if (this->size_ < 2)
		throw std::length_error("Span::shortestSpan: need at least two numbers to compute a span");

	std::vector<int>	tmp(this->elems_);

	std::sort(tmp.begin(), tmp.begin() + this->size_);

	return tmp[this->size_ - 1] - tmp.front();
}

void			Span::addNumbers(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
	if ((end - begin) > (this->max_size_ - this->size_))
		throw std::out_of_range("Span::addNumbers: not enough space to add all numbers");

	this->elems_.insert(this->elems_.begin() + this->size_, begin, end);
	this->size_ += end - begin;
}
