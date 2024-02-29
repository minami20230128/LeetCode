class Solution {
public:
    int romanToInt(std::string s) {
        std::map<std::string, int> romans = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000}
        };

        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += romans[std::string({s[i]})];
        }

        return sum;
    }

    
};