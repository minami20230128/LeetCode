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
            //std::cout << itr->first << std::endl;
            //std::cout << itr->second << std::endl;

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
                auto idx = s.find(this->brackets[ch], i);
                if(idx == -1) return false;
                this->pair_idx[i] = idx;
            }
        }
        return true;
    }

    bool check_order()
    {
        auto itr = this->pair_idx.begin();
        while(itr != this->pair_idx.end()--)
        {
            auto next_itr = std::next(itr);
            std::cout << itr->first << std::endl;
            std::cout << itr->second << std::endl;
            std::cout << next_itr->first << std::endl;
            std::cout << next_itr->second << std::endl;
            if(!(itr->second < next_itr->first) && !(itr->first < next_itr->first && itr->second > next_itr->second))
            {
                return false;
            }
            itr++;
        }

        return true;
    }
};