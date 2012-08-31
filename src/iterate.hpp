// -*- coding: utf-8; indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

/*
 * @version: 0.0.5
 * @license: MIT
 * @date: 9/1/2013 01:55 AM
 */

#ifndef __FUNCTIONAL_PP_ITERATE__
#define __FUNCTIONAL_PP_ITERATE__

#include <functional>
#include <algorithm>
#include <iterator>

namespace functional {
	using uint = std::size_t;

	namespace details {
		template <typename __container> 
			using value_type = typename __container::value_type;

		template <typename __container, typename __callback =
			std::function <value_type<__container> (value_type<__container>, value_type<__container>)>
		>
			using callback = __callback
		;
	}

	/*
	 * functional::range ( container, from, to, [ step ] );
	 *
	 * Generates a sequence of numbers or characters.
	 * The last parameter is optional to iterate by step.
	 *
	 * @returns { container<T> }
	 */

	template <typename __container, typename __position, typename __step = uint>
		static inline __container range(
			__container &container,
			__position from,
			__position to,
			__step step = 1
		) noexcept {
			typename std::back_insert_iterator<__container> it = std::back_inserter(container);

			do {
				*it++ = from;
			}
			while ((from += step) <= to);

			return container;
		}
	;

	/*
	 * functional::reduce ( container, function, [, initial ] );
	 *
	 * Apply a function against an accumulator and each value of the sequence container (from left-to-right)
	 * as to reduce it to a single value.
	 *
	 * @returns { container<T>::value_type }
	 */

	template <typename __container, typename __callback =
		details::callback<__container>
	>
		static inline details::value_type<__container> reduce(
			__container &container, __callback &&callback,
			const details::value_type<__container> &initial = {}
		) noexcept
		{
			typename __container::const_iterator it = container.cbegin();
			details::value_type<__container> current = initial;

			while (it != container.cend())
				current = callback(current, *it++);

			return current;
		}
	;


	/*
	 * functional::each ( container<T>, function );
	 *
	 * Executes a provided function once per container element.
	 *
	 * @returns { container<T> }
	 */

	template <typename __container, typename __callback =
		details::callback<__container>
	>
		static inline __container each(__container &&container, __callback &&callback) noexcept {
			std::for_each(container.begin(), container.end(), callback);

			return container;
		}
	;


	/*
	 * functional::map ( container<T>, function );
	 *
	 * Modifies the sequence container with the results of calling a provided
	 * function on every element in this container.
	 *
	 * @returns { container<T> }
	 */

	template <typename __container, typename __callback =
		details::callback<__container>
	>
		static inline __container map(__container &container, __callback &&callback) noexcept {
			std::transform(container.begin(), container.end(), container.begin(), callback);

			return container;
		}
	;


	/*
	 * functional::filter ( container<T>, function, init );
	 *
	 * Filters the sequence container with all elements
	 * that pass the test implemented by the provided function.
	 *
	 * @returns { container<T> }
	 */

	template <typename __container, typename __callback =
		details::callback<__container>
	>
		static inline __container filter(__container &&container, __callback &&callback) noexcept {
			container.erase(std::remove_if (
				container.begin(), container.end(), callback), container.end()
			);

			return container;
		}
	;


	/*
	 * functional::every ( container<T>, function );
	 *
	 * Tests whether all elements in the container pass the test
	 * implemented by the provided function.
	 *
	 * @returns { bool }
	 */

	template <typename __container, typename __callback =
		std::function <bool (details::value_type<__container>)>
	>
		static inline bool every (__container &&container, __callback &&callback) noexcept {
			return std::all_of(container.cbegin(), container.cend(), callback);
		}
	;


	/*
	 * functional::some ( container, function );
	 *
	 * Tests whether some element in the container passes
	 * the test implemented by the provided function.

	 * @returns { bool }
	 */

	template <typename __container, typename __callback =
		std::function <bool (details::value_type<__container>)>
	>
		static inline bool some (__container &&container, __callback &&callback) noexcept {
			return std::any_of(container.cbegin(), container.cend(), callback);
		}
	;

	/*
	 * functional::some ( container, function );
	 *
	 * Tests whether none element in the container passes
	 * the test implemented by the provided function.
	 *
	 * @returns { bool }
	 */

	template <typename __container, typename __callback =
		std::function <bool (details::value_type<__container>)>
	>
		static inline bool none (__container &&container, __callback &&callback) noexcept {
			return std::none_of(container.cbegin(), container.cend(), callback);
		}
	;
}

#endif
