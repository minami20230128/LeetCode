class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::vector<std::string> output;

        int without_val = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                output.push_back(std::to_string(nums[i]));
                without_val++;
            }
        }

        return without_val;
    }
};