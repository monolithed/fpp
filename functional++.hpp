// -*- coding: utf-8; indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

/*
 * functional++
 *
 * functional::each, functional::map, functional::filter, functional::reduce
 *
 * @author: Alexander Guinness
 * @version: 0.0.3
 * @license: MIT
 * @date: 9/1/2013 01:55 AM
 */

#ifndef __FUNCTIONAL_PP__
#define __FUNCTIONAL_PP__

#include <functional>
#include <algorithm>
#include <iterator>

namespace functional
{
	using uint = std::size_t;

	namespace details
	{
		template <typename __container>
		using value_type = typename __container::value_type;

		template <typename __container, typename __callback =
			std::function <value_type<__container> (value_type<__container>, value_type<__container>)>
		>
		using callback = __callback;
	}

	/*
	 * functional::each ( container, function );
	 * Executes a provided function once per container element.
	 *
	 * { container } - STL-container
	 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
	 *   value - The current element being processed in the sequence container.
	 *
	 * @returns { container<T> }
	 *
	 * Example:
	 * std::vector<int> vector = {0, 1, 2, 3, 4};
	 *
	 * functional::each(vector, [](const int value) {
	 *    std::cout << value << std::endl;
	 * });
	 */

	template <typename __container, typename __callback = details::callback<__container>>
	static inline __container each(__container &&container, __callback &&callback) noexcept
	{
		std::for_each(container.begin(), container.end(), callback);

		return container;
	};


	/*
	 * functional::map ( container, function );
	 * Modifies the sequence container with the results of calling a provided
	 * function on every element in this container.
	 *
	 * { container } - STL-container
	 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
	 *   value - The current element being processed in the sequence container.
	 *
	 * @returns { container<T> }
	 *
	 * Example:
	 * std::vector<int> vector = {0, 1, 2, 3, 4};
	 *
	 * functional::each(vector, [](const int value) {
	 *    std::cout << value << std::endl;
	 * });
	 */

	template <typename __container, typename __callback = details::callback<__container>>
	static inline __container map(__container &container, __callback &&callback) noexcept
	{
		std::transform(container.begin(), container.end(), container.begin(), callback);
		return container;
	};


	/*
	 * functional::filter ( container, function, init );
	 *
	 * Filters the sequence container with all elements that pass the test implemented by the provided function.
	 *
	 * { container } - STL-container
	 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
	 *    value  - The current element being processed in the sequence container.
	 *
	 * @returns { container<T> }
	 *
	 * Example:
	 * std::vector<int> vector = {0, 1, 2, 3, 4};
	 *
	 * int result = functional::filter(vector, [](const int item) -> int {
	 *    return item % 2 == 0;
	 * });
	 *
	 * result; // {1, 3}
	 */

	template <typename __container, typename __callback = details::callback<__container>>
	static inline __container filter(__container &&container, __callback &&callback) noexcept
	{
		container.erase(std::remove_if(container.begin(), container.end(), callback), container.end());

		return container;
	};


	/*
	 * functional::reduce ( container, function, [ initial ] );
	 *
	 * Apply a function against an accumulator and each value of the sequence container (from left-to-right)
	 * as to reduce it to a single value.
	 *
	 * { container } - STL-container
	 * { callback }  - Function to execute on each value in the sequence container, taking two arguments:
	 *     previous_value - The value previously returned in the last invocation of the callback, or initialValue.
	 *     current_value  - The current element being processed in the sequence container.
	 *
	 * { init } - Optional initial value
	 *
	 * @returns { container<T>::value_type }
	 *
	 * Example 1:
	 * std::vector<int> vector = {0, 1, 2, 3, 4};
	 *
	 * int result = functional::reduce(vector, [](const int current, const int prev) -> int {
	 *     return current + next;
	 * });
	 *
	 * result; // 10
	 *
	 * Example 2:
	 *
	 * std::vector<int> vector = {0, 1, 2, 3, 4};
	 *
	 * int result = functional::reduce(vector, [](const int current, const int prev) -> int {
	 *     return current + next;
	 * }, 10);
	 *
	 * result; // 20
	 *
	 * Example 3:
	 *
	 * std::vector<std::string> vector = {"0", "1", "2", "3", "4"};
	 *
	 * int result = functional::reduce(vector, [](const std::string current, const std::string prev) ->
	 * std::string {
	 *     return current + next;
	 * });
	 *
	 * result; // 0, 1, 2, 3, 4
	 */

	template <typename __container, typename __callback = details::callback<__container>>
	static inline details::value_type<__container> reduce (
		__container &container, __callback &&callback, const details::value_type<__container> &initial = {}
	) noexcept
	{
		typename __container::const_iterator it = container.begin();
		details::value_type<__container> current = initial;

		while (it != container.end())
			current = callback(current, *it++);

		return current;
	};
}

#endif
