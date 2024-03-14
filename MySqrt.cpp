class Solution {
private:
    int get_digit(int num)
    {
        int digit = 0;
        while(num >= 10)
        {
            num /= 10;
            digit++;
        }

        return digit;
    }

    int get_start_num(int num)
    {
        int digit = this->get_digit(num);
        int power = digit / 2;
        return std::pow(10, power);
    }

public:
    int mySqrt(int x) {
        int start = get_start_num(x);
        std::cout << start;
        for(int i = start; i <= x; i++)
        {
            long sqrt = (long) i * i;
            //std::cout << sqrt;
            if(sqrt == x) return i;
            if(sqrt > x) return i - 1;
        }

        return 0;
    }
};
