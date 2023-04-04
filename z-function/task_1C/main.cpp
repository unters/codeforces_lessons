#include <iostream>
#include <string>
#include <vector>


std::vector<int> find_substrings(std::string const &, std::string const &);


int main() {
    int n;
    std::cin >> n;

    std::string str, substr;
    std::getline(std::cin, str);
    for (int i = 0 ; i < n; ++i) {
        std::getline(std::cin, str);
        std::getline(std::cin, substr);

        if (substr.size() > str.size()) {
            std::cout << "0\n\n";
            continue;
        }

        auto result = find_substrings(str, substr);
        std::cout << result[result.size() - 1] << std::endl;
        for (int j = 0; j < result.size() - 1; ++j)
            std::cout << result[j] << " ";
        std::cout << std::endl;
    }

    return 0;
}


std::vector<int> find_substrings(std::string const & str,
        std::string const & substr) {
    int counter = 0;
    std::vector<int> result;
    for (int i = 0; i < str.size() - substr.size() + 1; ++i) {
        int length = 0;
        for (int p = 0; p < substr.size(); ++p) 
            if (str[i + p] == substr[p])
                ++length;
            else if (substr[p] == '?')
                ++length;
            else
                break;

        if (length == substr.size()) {
            result.push_back(i);
            ++counter;
        }
    }

    result.push_back(counter);
    return result;
}
