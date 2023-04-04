#include <iostream>
#include <string>
#include <set>


int count_substrings(std::string & string, std::string & substr);


int main(void) {
    int n;
    std::cin >> n;

    std::string line;
    std::set<std::string> ixes;
    std::getline(std::cin, line);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        int len = line.size();

        for (int suffix_len = 1; suffix_len < len; ++suffix_len) 
            ixes.insert(line.substr(0, suffix_len));
        
        for (int suffix_len = len - 1; suffix_len > 0; --suffix_len) {
            std::string postfix = line.substr(suffix_len);
            auto it = ixes.find(postfix);
            if (it != ixes.end())
                ixes.erase(it);
            else
                ixes.insert(postfix);
        }

        int counter = 0;
        for (auto str : ixes) 
            counter += count_substrings(line, str);
        ixes.clear();

        std::cout << counter << std::endl;
    }

    return 0;
}


int count_substrings(std::string & string, std::string & substr) {
    int counter = 0;
    for (int i = 0; i < string.size() - substr.size() + 1; ++i) {
        int length = 0;
        for (int p = 0; p < substr.size(); ++p) {
            if (string[i + p] == substr[p])
                ++length;
            else
                break;
        }

        if (length == substr.size())
            ++counter;
    }

    return counter;
}