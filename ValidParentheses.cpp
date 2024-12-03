class Solution {
public:
    std::map<std::string, std::string> brackets
     =  {
            {"(", ")"},
            {"{", "}"},
            {"[", "]"}
        };

    std::map<int, int> pair_idx;
    bool isValid(string s) {
        if(!this->get_indexes(s)) return false;

        auto itr = this->pair_idx.begin();
        while(itr != this->pair_idx.end())
        {
            std::cout << itr->first << std::endl;
            std::cout << itr->second << std::endl;

            itr++;
        }

        return this->check_order();
    }

    private:
    bool get_indexes(std::string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            std::string ch = std::string({s[i]});
            if(ch == "(" || ch == "{" || ch == "[")
            {
                auto idx = this->find_close(s, pair_idx, ch, i);
                if(idx == -1) return false;
                this->pair_idx[i] = idx;
            }

            if(ch == ")" || ch == "}" || ch == "]")
            {
                auto it = std::find_if(pair_idx.begin(), pair_idx.end(), [&i](const std::pair<int, int>& pair) {
                    return pair.second == i;
                });

                if(it == pair_idx.end())
                {
                    return false;
                }   
            }
        }
        return true;
    }

    int find_close(std::string s, std::map<int, int>pair_idx, std::string open, int i)
    {
        std::string close = this->brackets[open];
        while(1)
        {
            auto idx = s.find(close, i);

            //既知の閉じ括弧であれば他を探す
            auto it = std::find_if(pair_idx.begin(), pair_idx.end(), [&idx](const std::pair<int, int>& pair) {
                return pair.second == idx;
            });
            
            if(it == pair_idx.end())
            {
                return idx;
            }   

            i = idx + 1;
            if(i > s.size())
            {
                return -1;
            }
        }
    }

    bool check_order()
    {
        auto itr = this->pair_idx.begin();
        while(itr != this->pair_idx.end())
        {
            int open = itr->first;
            int close = itr->second;

            //[(])
            auto it = std::find_if(pair_idx.begin(), pair_idx.end(), [&open, &close](const std::pair<int, int>& pair) {
                return pair.first < open && pair.second < close && pair.second > open;
            });
            if(it != pair_idx.end()) return false;

            //([)]
            it = std::find_if(pair_idx.begin(), pair_idx.end(), [&open, &close](const std::pair<int, int>& pair) {
                return pair.first > open && pair.second > close && pair.second < close;
            });
            if(it != pair_idx.end()) return false;

            itr++;
        }
        
        return true;
    }
};