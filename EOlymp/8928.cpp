#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << n / 2 << std::endl;
    } else {
        bool found = false;
        for (long long i = 3; i <= std::sqrt(n); i += 2) {
            if (n % i == 0) {
                std::cout << n / i << std::endl;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << 1 << std::endl;
        }
    }

    return 0;
}
