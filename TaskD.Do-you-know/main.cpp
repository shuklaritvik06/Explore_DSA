//
// Created by rituparn on 09.04.24.
//


#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

std::string convertVectorToString(const std::vector<int>& output) {
    std::string result(output.begin(), output.end());
    return result;
}

std::vector<int> z_to_prefix(const std::vector<int>& z_values) {
    int n = z_values.size();
    std::vector<int> prefix_values(n, 0);
    for (int i = 1; i < n; ++i) {
        if (z_values[i] > 0) {
            for (int j = z_values[i] - 1; j >= 0; --j) {
                if (prefix_values[i + j] == 0) {
                    prefix_values[i + j] = j + 1;
                } else {
                    break;
                }
            }
        }
    }
    return prefix_values;
}

std::vector<int> PrefixToString(const std::vector<int>& prefix) {
    std::vector<int> result(prefix.size(), 97);

    for (size_t i = 1; i < result.size(); ++i) {
        if (prefix[i] == 0) {
            result[i] = result[prefix[i - 1]] + 1;
        } else {
            result[i] = result[prefix[i] - 1];
        }
    }

    return result;
}
int main() {
    std::string input_string;
    std::getline(std::cin, input_string);
    std::istringstream is(input_string);
    std::vector<int> z_function((std::istream_iterator<int>(is)),
                                std::istream_iterator<int>());
    std::vector<int> prefix = z_to_prefix(z_function);
    std::vector<int> string = PrefixToString(prefix);
    std::cout << convertVectorToString(string);
    return 0;
}
