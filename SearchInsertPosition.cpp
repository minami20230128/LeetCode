class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto itr = std::find(nums.begin(), nums.end(), target);
        if(itr != nums.end()) return std::distance(nums.begin(), itr);

        nums.push_back(target);
        std::sort(nums.begin(), nums.end());

        itr = std::find(nums.begin(), nums.end(), target);
        return std::distance(nums.begin(), itr);
    }
};