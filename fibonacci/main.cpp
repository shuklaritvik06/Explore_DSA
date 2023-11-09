#include <iostream>
#include <cstdint>  // Include for uint64_t

class Fibonacci {
public:
    uint64_t CalculateFibonacci(uint64_t n) {
        uint64_t F[2][2] = {{1, 1}, {1, 0}};
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        Power(F, n - 1);
        return F[0][0];
    }

    void Power(uint64_t F[2][2], uint64_t n) {
        if (n == 0 || n == 1) {
            return;
        }
        uint64_t M[2][2] = {{1, 1}, {1, 0}};
        Power(F, n / 2);
        Multiply(F, F);
        if (n % 2 != 0) {
            Multiply(F, M);
        }
    }

    void Multiply(uint64_t F[2][2], uint64_t M[2][2]) {
        uint64_t x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % 1000003;
        uint64_t y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % 1000003;
        uint64_t z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % 1000003;
        uint64_t w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % 1000003;
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
};

int main() {
    uint64_t n;
    std::cin >> n;
    Fibonacci fib;
    std::cout << fib.CalculateFibonacci(n - 1) << std::endl;
    return 0;
}
