#include <iostream>

class Solution
{
    public:
    bool isPowerOfTwo(int n)
    {
        n = n < 0 ? 1 / n : n;
        bool isPower = true;
        while(isPower)
        {
            //std::cout << n << std::endl;
            isPower = (this->isMultipleOfTwo(n) || this->isOne(n)) && !this->isZero(n);
            //std::cout << isPower << std::endl;
            if(n == 1 || n == 0) break;
            n = n / 2;
        }

        return isPower;
    }

    private: 
    bool isMultipleOfTwo(int i)
    {
        return i % 2 == 0;
    }

    bool isOne(int i)
    {
        return i == 1;
    }

    bool isZero(int i)
    {
        return i == 0;
    }
};