#include <iostream>
#include <string>
#include <vector>


int main(void) {
    int n;
    std::cin >> n;

    std::string line;
    std::getline(std::cin, line);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        int len = line.size();

        /* polindrome_index stands for index of last letter 
         * in the polindrome.  */
        int polindrome_index = len - 1;
        int p = 0, q = len - 1;
        while (p <= q) {
            if (line[p] != line[q]) {
                p = 0;
                q = polindrome_index - 1; 
                --polindrome_index;
            }

            else
                ++p, --q;
        }

        std::cout << polindrome_index + 1 << std::endl;
    }

    return 0;
}