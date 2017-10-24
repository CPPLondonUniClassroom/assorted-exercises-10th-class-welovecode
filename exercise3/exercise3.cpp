
#include "exercise3.hpp"

// Requirements:
//   -- Given a string containing elements separated by commas, return a
//      vector of strings containing each element
// For example
//    split("a,b,c") -> vector<string>("a", "b", "c");
std::vector<std::string> split(const std::string& str)
{
    return {};
}

// An element which is enclosed in double quotes should be treated as a single element,
// even if it contains a comma. For example,
//
//  ""a, b",c,d" contains three elements
//
// Requirements:
//   -- Split the given string into its component elements, treating quoted
//      elements as a single unit
std::vector<std::string> quoted_split(const std::string& str)
{
    return {};
}

// A CSV file consists of multiple lines, each of which should be split
// according to the above rules. Given an input stream istream, return
// a `csv_file` containing each line of the input, split correctly
csv_file parse_csv(std::istream& istream)
{
    return {};
}