class Solution {
public:
    int mySqrt(int x) {
        for(int i = 0; i <= x; i++)
        {
            long sqrt = i * i;
            std::cout << sqrt;
            if(sqrt == x) return i;
            if(sqrt > x) return i - 1;
        }

        return 0;
    }
};