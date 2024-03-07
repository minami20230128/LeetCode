class Solution {
public:
    int divide(int dividend, int divisor) {
        long tmp = 0;
        long cnt = 0;

        bool is_dividend_minus = dividend < 0;
        bool is_divisor_minus = divisor < 0;

        bool is_output_minus = false;

        if(is_dividend_minus ^ is_divisor_minus)
        {
            is_output_minus = true;
        }

        long limit = is_output_minus ? 2147483648 : 2147483647;

        while(tmp <= limit)
        {
            tmp += labs(divisor);
            //std::cout << tmp;
            
            if(tmp > labs(dividend) || tmp > limit)
            {
                break;
            }
            cnt++;
        }

        long output = is_output_minus ? -(cnt) : cnt; 

        return output;
    }
};