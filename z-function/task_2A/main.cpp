#include <iostream>
#include <string>


int main() {
    std::string str;
    std::getline(std::cin, str);

    int * z = new int[str.size()];
    for (int i = 0; i < str.size(); ++i)
        z[i] = 0;

    for (int i = 1; i < str.size(); ++i)
        while (z[i] + i < str.size() && str[z[i]] == str[z[i] + i])
            z[i] += 1;

    for (int i = 0; i < str.size(); ++i)
        std::cout << z[i] << " ";
    std::cout << std::endl;

    return 0;
}
