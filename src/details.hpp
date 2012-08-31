// -*- coding: utf-8; indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

/*
* functional::is_container<T>::value;
* functional<T>::of(value);
*
* @version: 0.0.1
* @license: MIT
* @date: 26/11/2012 04:18 PM
*/

#ifndef __FUNCTIONAL_PP_DETAILS__
#define __FUNCTIONAL_PP_DETAILS__

#include <type_traits>
#include <valarray>

namespace functional {
	namespace details {
		template <typename T, T, T> struct is final {
			typedef void type;
		};
	}

	/** functional::is_container<std::array<int>>::value; */
	template <typename T, typename = void>
		struct is_container : std::false_type { };
	;

	template <typename T> 
		struct is_container <
			T,
			typename details::is <typename T::const_iterator(T::*)() const,
		 	&T::begin, 
			&T::end>::type
		> : 
	std::is_class<T> { };

	/** functional<T>::of(value); */
	template <typename __type>
		struct type {
			template <typename __value> static const bool of (__value) noexcept {
				return std::is_same<__type, __value>::value;
			};
		}
	;
}

#endif

