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

        std::map<std::string, std::vector<std::string>> special = {
            {"I", {"V", "X"}},
            {"X", {"L", "C"}},
            {"C", {"D", "M"}}
        };

        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            std::string current = std::string({s[i]});
            bool is_last = i == s.size() - 1;
            std::cout << current;
            if(!is_last)
            {
                std::string next = std::string({s[i + 1]});
                //std::cout << next;
                std::vector<std::string> tmp = special[current];

                //for(int i = 0; i < tmp.size(); i++)
                //{
                //    std::cout << tmp[i];
                //}
                //std::cout << tmp.size();
                if(std::find(tmp.begin(), tmp.end(), next) != tmp.end())
                {
                    //std::cout << romans[next] - romans[current];
                    sum += romans[next] - romans[current];
                    i += 1;
                    continue;
                }
            }
            sum += romans[current];
        }

        return sum;
    }

    
};