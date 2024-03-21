class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> count;
        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }

        int largest = 0;
        int largest_count = 0;
        auto itr = count.begin();
        while(itr != count.end())
        {
            largest_count = largest_count > itr->second ? largest_count : itr->second;
            largest = largest_count > itr->second ? largest : itr->first;
            itr++;
        }

        return largest;
    }
};