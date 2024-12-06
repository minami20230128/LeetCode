class Solution {
public:
    std::map<std::string, std::string> brackets
     =  {
            {")", "("},
            {"}", "{"},
            {"]", "["}
        };

    bool isValid(string s) {
        std::stack<std::string> st;
        for(int i = 0; i < s.size(); i++)
        {
            auto ch = std::string({s[i]});
            if(ch == "(" || ch == "{" || ch == "[")
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                
                auto open = this->brackets[ch];
                std::cout << st.top() << std::endl;
                if(st.top() != open)
                {
                    return false;
                }
                st.pop();
            }
        }

        if(!st.empty())
        {
            return false;
        }

        return true;
    }
};
    