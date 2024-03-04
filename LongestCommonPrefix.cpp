class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string first = strs[0];
        std::string prefix = "";

        if(strs.size() == 1) return first;

        for(int i = 1; i <= first.size(); i++)
        {
            std::string tmp = first.substr(0, i);
            std::cout << tmp;

            for(int j = 1; j < strs.size(); j++)
            {
                //std::cout << strs[j].substr(0, i);
                if(strs[j].substr(0, i) != tmp)
                {
                    return prefix;
                }
            }
            prefix = tmp;
        }
        
        return prefix;
    }
};