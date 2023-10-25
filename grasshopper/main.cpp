#include <iostream>
class Grasshopper {
public:
    unsigned long long matrix[5][5] = {{1, 1, 1, 1, 1},
                                       {1, 0, 0, 0, 0},
                                       {0, 1, 0, 0, 0},
                                       {0, 0, 1, 0, 0},
                                       {0, 0, 0, 1, 0}};


    void Multiplication(unsigned long long M[5][5], const unsigned long long F[5][5]) {
        unsigned long long result[5][5] = {0};

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                unsigned long long sum = 0;
                for (int k = 0; k < 5; k++) {
                    sum = (sum + M[i][k] % 1000003 * F[k][j] % 1000003) % 1000003;
                }
                result[i][j] = sum;
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                M[i][j] = result[i][j];
            }
        }
    }

    void Power(unsigned long long matrix[5][5], unsigned long long n) {
        if (n == 0 || n == 1) {
            return;
        }

        unsigned long long temp[5][5] = {{1, 1, 1, 1, 1},
                                         {1, 0, 0, 0, 0},
                                         {0, 1, 0, 0, 0},
                                         {0, 0, 1, 0, 0},
                                         {0, 0, 0, 1, 0}};

        Power(matrix, n / 2);
        Multiplication(matrix, matrix);

        if (n % 2 != 0) {
            Multiplication(matrix, temp);
        }
    }

    unsigned long long steps(unsigned long long n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n == 4) {
            return 4;
        } else if (n == 5) {
            return 8;
        }
        Power(matrix, n - 5);
        unsigned long long tran[5] = {8, 4, 2, 1, 1};
        unsigned long long result[5] = {0};

        for (int i = 0; i < 5; i++) {
            unsigned long long sum = 0;
            for (int j = 0; j < 5; j++) {
                sum = (sum + matrix[i][j] % 1000003 * tran[j] % 1000003) % 1000003;
            }
            result[i] = sum;
        }
        return result[0];
    }
};

int main() {
    unsigned long long n;
    std::cin >> n;
    Grasshopper grasshopper;
    std::cout << grasshopper.steps(n) << std::endl;
    return 0;
}
