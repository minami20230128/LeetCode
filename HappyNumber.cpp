class Solution {
public:
    int AddUpSquares(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int tmp = n % 10;
            std::cout << tmp;
            n /= 10;

            sum += tmp * tmp;
        }

        return sum;
    }

    bool isHappy(int n) {

        int prev = 0;
        while(1)
        {
            n = this->AddUpSquares(n);
            if(n == 1) return true;
            if(prev == n) return false;

            prev = n;
        }
        
        return true;
    }
};