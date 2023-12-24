#include <iostream>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int n, m;
    iss >> n >> m;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            for (int j = 0; j < m - 1; ++j) {
                std::cout << "#";
            }
            std::cout << "#" << std::endl;
        } else if (i % 4 == 2) {
            for (int j = 0; j < m - 1; ++j) {
                std::cout << ".";
            }
            std::cout << "#" << std::endl;
        } else if (i % 4 == 0) {
            std::cout << "#";
            for (int j = 0; j < m - 2; ++j) {
                std::cout << ".";
            }
            std::cout << "." << std::endl;
        }
    }

    return 0;
}

