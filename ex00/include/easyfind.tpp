/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:01:53 by akostian          #+#    #+#             */
/*   Updated: 2025/07/09 04:37:45 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator	easyfind(T haystack, const int &needle)
{
	const typename T::iterator	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
