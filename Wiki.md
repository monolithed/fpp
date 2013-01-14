## functional::each ( container, function );

```c++
/*
 * Executes a provided function once per container element.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { container<T> }
 *
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	functional::each(vector, [](const int value) {
		std::cout << value << std::endl; // 0, 1, 2, 3, 4
	});

	return 0;
}
```


## functional::map ( container, function );

```c++
/*
 * Modifies the sequence container with the results of calling a provided
 * function on every element in this container.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { container<T> }
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	functional::map(vector, [](const int value) {
		return value * 2;
	});

	for (auto value: vector)
		std::cout << value << std::endl; // 0, 2, 4, 6, 8

	return 0;
}
```

## functional::filter ( container<T>, function );

```c++
/*
 * Filters the sequence container with all elements
 * that pass the test implemented by the provided function.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { container<T> }
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	functional::filter(vector, [](const int value) {
		return item % 2 == 0;
	});

	for (auto value: vector)
		std::cout << value << std::endl; // 1, 3

	return 0;
}
```

## functional::reduce ( container <T>, function, [ initial ] );

```c++
/*
 * Apply a function against an accumulator and each value of
 * the sequence container (from left-to-right) as to reduce it to a single value.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking two arguments:
 *     current  - The current element being processed in the sequence container.
 *     previous - The value previously returned in the last invocation of the callback, or initialValue.
 *
 * { init } - Optional initial value
 *
 * @returns { container<T>::value_type }
 */


#include <vector>
#include <string>
#include <iostream>
#include "functional++.hpp"

int mail () {
	// Example 1:

	std::vector<int> vector = {0, 1, 2, 3, 4};

	int result = functional::reduce(vector, [](const int current, const int prev) -> int {
	    return current + next;
	});

	std::cout << result << std::endl; // 10


	// Example 2:

	std::vector<int> vector = {0, 1, 2, 3, 4};

	int result = functional::reduce(vector, [](const int current, const int prev) -> int {
	    return current + next;
	}, 10);

	std::cout << result << std::endl; // 20


	// Example 3:

	std::vector<std::string> vector = {"0", "1", "2", "3", "4"};

	auto result = functional::reduce(vector, [](const std::string current, const std::string prev) ->
		std::string {
	        return current + next;
		}
	);

	std::cout << result << std::endl; // 0, 1, 2, 3, 4

	return 0;
}
```

## functional::every ( container<T>, function );

```c++
/*
 * Tests whether all elements in the container pass
 * the test implemented by the provided function.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { bool }
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	auto result = functional::every(vector, [](const int value) -> bool {
		return value == 1;
	});

	std::cout << result << std::endl; // false

	return 0;
}
```

## functional::some ( container<T>, function );

```c++
/*
 * Tests whether some element in the container passes
 * the test implemented by the provided function.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { bool }
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	auto result = functional::every(vector, [](const int value) -> bool {
		return value == 1;
	});

	std::cout << result << std::endl; // true

	return 0;
}
```

## functional::none ( container<T>, function );

```c++
/*
 * Tests whether none element in the container passes
 * the test implemented by the provided function.
 *
 * { container } - STL-container
 * { callback }  - Function to execute on each value in the sequence container, taking one argument:
 *   value - The current element being processed in the sequence container.
 *
 * @returns { bool }
 */


#include <vector>
#include <iostream>
#include "functional++.hpp"

int mail () {
	std::vector<int> vector = {0, 1, 2, 3, 4};

	auto result = functional::none(vector, [](const int value) -> bool {
		return value == 5;
	});

	std::cout << result << std::endl; // true

	return 0;
}
```