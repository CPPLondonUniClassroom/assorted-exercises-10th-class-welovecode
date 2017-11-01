
#include "exercise3.hpp"

#include <sstream>

// Requirements:
//   -- Given a string containing elements separated by commas, return a
//      vector of strings containing each element
// For example
//    split("a,b,c") -> vector<string>("a", "b", "c");
std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> output;
    auto pos = str.begin();

    while (pos != str.end()) {
        const auto comma = std::find(pos, str.end(), ',');
        output.emplace_back(pos, comma);
        if (comma == str.end()) {
            break;
        }
        pos = std::next(comma);
    }

    return output;
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
    std::vector<std::string> output;
    auto pos = str.begin();

    while (pos != str.end()) {
        // We're at the start of an element. Is this a quote?
        if (*pos == '"') {
            // First, bump the position so we ignore the opening quote
            ++pos;
            // Now find the closing quote by searching forward from our current
            // position
            const auto end_quote = std::find(pos, str.end(), '"');
            // The interval [pos, end_quote) is a single element, so copy it
            // to the output
            output.emplace_back(pos, end_quote);

            // If our "end_quote" is actually the end of the string, then
            // we're done...
            if (end_quote == str.end()) {
                break;
            }
            // ... otherwise advance to the position after the closing quote
            pos = std::next(end_quote);
        } else {
            // In this branch we need to find the next comma
            const auto comma = std::find(pos, str.end(), ',');

            // The interval [pos, comma) contains a single element, so copy it
            // to the output
            output.emplace_back(pos, comma);

            // Position our cursor at the element end position
            pos = comma;
        }

        // We should either be at a comma, or the end of the string. If
        // we're at the end we break, otherwise we bump the iterator and
        // continue
        if (pos == str.end()) {
            break;
        }
        ++pos;
    }

    return output;
}

// A CSV file consists of multiple lines, each of which should be split
// according to the above rules. Given an input stream istream, return
// a `csv_file` containing each line of the input, split correctly
csv_file parse_csv(std::istream& istream)
{
    std::string line;
    csv_file file{};

    while (std::getline(istream, line)) {
        file.lines.push_back(quoted_split(line));
    }

    return file;
}