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
        bool tmp = this->get_indexes(s);
        std::cout << tmp << std::endl;
        if(!tmp) return false;

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
                std::cout << i;
                std::cout << "文字目" << std::endl;
                std::string close = this->brackets[ch];
                //std::cout << close << std::endl;

                int nest = this->find_nest(s, ch, close, i);
                std::cout << nest << std::endl;
                if(nest == -1) return false;

                int close_idx = this->find_parentheses(s, close, i);
                for(int i = 0; i < nest; i++)
                {
                    close_idx = this->find_parentheses(s, close, close_idx + 1);
                }

                //std::cout << close_idx << std::endl;
                this->pair_idx[i] = close_idx;

                auto itr = this->pair_idx.begin();
                while(itr != this->pair_idx.end())
                {
                    //std::cout << itr->first << std::endl;
                    //std::cout << itr->second << std::endl;

                    itr++;
                }
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

    int find_parentheses(std::string s, std::string ch, int i)
    {
        return s.find(ch, i);
    }

    int find_nest(std::string s, std::string open, std::string close, int open_idx)
    {
        int nest = 0;
        auto next_close = this->find_parentheses(s, close, open_idx);
        if(next_close == -1) return -1;
        auto same_open = this->find_parentheses(s, open, open_idx + 1);

        if(same_open < next_close && same_open != -1)
        {
            auto next_next_close = this->find_parentheses(s, close, next_close + 1);
            if(next_next_close == -1) return -1;
            nest++;
            this->find_nest(s, open, close, same_open);
        }

        return nest;
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


//1. (があり、かつ次の)までの間に一つ以上(がある->ネストしているとみなす。
//2. ネストしていない同種の括弧をすべて探す。
//3. その外側の括弧を順番に探す。

