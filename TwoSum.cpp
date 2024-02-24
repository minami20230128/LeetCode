class Solution
{
    public:
    std::vector<int> twoSum(std::vector<int> nums, int target)
    {
        std::map<int, int> hash;
        for(int i = 0; i < nums.size(); i++)
        {
            int required = target - nums[i];
            if(hash.find(required) != hash.end())
            {
                return {i, hash[required]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
