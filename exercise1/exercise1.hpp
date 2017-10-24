
#ifndef CPP_LONDON_UNI_EXERCISE1_HPP
#define CPP_LONDON_UNI_EXERCISE1_HPP

#include <vector>

// Requirements:
//   -- if i is even, returns true
//   -- if i is odd, returns false
bool is_even(int i);

// Requirements:
//   -- returns the number of odd numbers in the given vector
int count_odd(const std::vector<int>& vec);

// Requirements:
//   -- returns the sum of the even numbers in the vector
int even_sum(const std::vector<int>& vec);

// Requirements:
//   -- returns a new vector containing only the elements of vec which are
//      divisible by p
std::vector<int> copy_if_divisible_by(const std::vector<int>& vec, int p);

// Requirements:
//   -- returns the largest number in the vector which is divisible by 3
int largest_div_by_three(const std::vector<int>& vec);

// Requirements:
//   -- returns true if the elements in vec are sorted, and false otherwise
bool is_sorted(const std::vector<int>& vec);

#endif
