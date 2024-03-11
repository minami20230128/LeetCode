class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int last_length = 0;

        for(int i = 0; i < s.size(); i++)
        {
            auto ch = std::string({s[i]});
            if(ch == " ")
            {
                if(length != 0) last_length = length;
                length = 0;
                continue;
            }

            length++;
            
            if(i == s.size() - 1)
            {
                last_length = length;
                break;
            }
        }

        return last_length;
    }
};