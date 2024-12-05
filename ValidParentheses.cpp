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
        this->find_not_nested(s);

        //this->find_nested(s);

        auto itr = this->pair_idx.begin();
        while(itr != this->pair_idx.end())
        {
            std::cout << itr->first << std::endl;
            std::cout << itr->second << std::endl;

            itr++;
        }

        return true;
    }

    private:
    int find_from(std::string s, std::string ch, int from)
    {
        return s.find(ch, from);
    }

    int find_to(std::string s, std::string ch, int to)
    {
        int idx = s.find(ch);
        if(idx > to) return -1;
        return idx;
    }

    bool find_nested(std::string s)
    {
        auto itr = this->pair_idx.begin();
        while(itr != this->pair_idx.end())
        {
            auto open_idx = itr->first;
            auto close_idx = itr->second;
            find_each_nested(s, open_idx, close_idx);

            itr++;
        }

        return true;
    }

    bool find_each_nested(std::string s, int not_nested_open, int not_nested_close)
    {
        int prev_open = not_nested_open;
        int prev_close = not_nested_close;

        while(1)
        {
            if(prev_open == 0 || prev_close == s.size() - 1) return true;
            int open_idx = prev_open - 1;
            std::string open = std::string({s[open_idx]});
            if(open == ")" || open == "]" || open == "}") return true;
            std::string close = this->brackets[open];
            auto close_idx = this->find_from(s, close, prev_close + 1);
            if(close_idx == -1) return false;

            prev_open = open_idx;
            prev_close = close_idx;
        }

    }

    bool find_not_nested(std::string s)
    {
        if(!this->find_each_not_nested(s, "()") 
            && !this->find_each_not_nested(s, "{}")
            && !this->find_each_not_nested(s, "[]"))
        {
            return false;
        }

        return true;
    }

    bool find_each_not_nested(std::string s, std::string pair)
    {
        auto idx = s.find(pair);
        if(idx == -1) return false;
        this->pair_idx[idx] = idx + 1;
        return true;
    }
};