class Solution {
public:
    int AddUpSquares(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int tmp = n % 10;
            //std::cout << tmp;
            n /= 10;

            sum += tmp * tmp;
        }

        return sum;
    }

    bool isHappy(int n) {

        int cnt = 0;
        int tmp = n;
        while(1)
        {
            tmp = this->AddUpSquares(tmp);
            std::cout << tmp << std::endl;
            //std::cout << prev << std::endl;
            if(tmp == 1) return true;
            if(tmp == n * n && cnt != 0) return false;
            cnt++;
        }
        
        return true;
    }
};