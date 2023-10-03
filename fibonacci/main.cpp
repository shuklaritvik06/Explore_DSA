#include <iostream>

class Fibonacci{
public:
    unsigned long long fibonacci(unsigned long long  n)
    {
        unsigned long long  F[2][2] = { { 1, 1 }, { 1, 0 } };
        if (n == 0)
            return 0;
        else if (n == 1 ||n==2){
            return 1;
        }
        power(F, n - 1);

        return F[0][0];
    }


    void power(unsigned long long F[2][2], unsigned long long n)
    {
        if (n == 0 || n == 1)
            return;
        unsigned long long  M[2][2] = { { 1, 1 }, { 1, 0 } };

        power(F, n / 2);
        multiply(F, F);

        if (n % 2 != 0)
            multiply(F, M);
    }

    void multiply(unsigned long long F[2][2], unsigned long long M[2][2])
    {
        unsigned long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0])% 1000003;
        unsigned long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1])% 1000003;
        unsigned long long z = (F[1][0] * M[0][0] + F[1][1] * M[1][0])% 1000003;
        unsigned long long w = (F[1][0] * M[0][1] + F[1][1] * M[1][1])% 1000003;

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
};




int main()
{
    unsigned long long n;
    std::cin >> n;
    Fibonacci Fib;
    std::cout<<Fib.fibonacci(n-1)<<std::endl;
    return 0;
}
