class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        int len = str.size();
        int start_second = len / 2;
        int half_len = len % 2 == 0 ? len / 2 : len / 2 + 1;
        std::string first_half = str.substr(0, half_len);
        std::string second_half = str.substr(start_second, half_len);

        std::cout << first_half << std::endl;
        std::cout << second_half << std::endl;

        auto itr = first_half.begin();
        auto ritr = second_half.rbegin();

        bool is_palindrome = true;
        for(int i = 0; i < half_len; i++)
        {
            if(first_half[i] != second_half[half_len - 1 - i])
            {
                is_palindrome = false;
                break;
            }
        }

        return is_palindrome;
    }
};