// -*- coding: utf-8; indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

/*
* functional::join
*
* Joins all elements of a container into a string.
* The delimiter specifies a value to separate each element of the container.
* Join algorithm is a counterpart to split algorithms.
*
* @version: 0.0.1
* @license: MIT
* @date: 26/11/2012 02:22 PM
*/

#ifndef __FUNCTIONAL_PP_STRING__
#define __FUNCTIONAL_PP_STRING__

#include <sstream>

namespace functional {
	/*
	 * functional::join ( iterator_begin &&, iterator_end &&, const type &delimiter = ',' );
	*/
	template <typename __type, typename __delimiter = char>
		std::string join (__type &&begin, __type &&end, const __delimiter &delimiter = ',') {
			__type i = begin;

			std::string result;
			std::ostringstream stream;

			if (i != end) {
				stream << *i++;
			}

			while (i != end) {
				stream << delimiter << *i++;
				result = stream.str();
			}

			return result;
		}
	;

	/**
	* functional::join ( container<T>, const type &delimiter = ',' );
	*/
	template <typename __type, typename __delimiter = char>
		std::string join (__type &&data, const __delimiter &delimiter = ',') {
			return join(data.begin(), data.end(), delimiter);
		}
	;
}

#endif

