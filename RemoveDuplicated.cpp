class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -101;
        int tmp = 0;
        auto itr = nums.begin();
        while(itr != nums.end()){
            std::cout << "prev: ";
            std::cout << prev << std::endl;
            std::cout << "now: ";
            std::cout << *itr << std::endl;
            tmp = *itr;
            if(*itr == prev){
                itr = nums.erase(itr);
            }
            else{
                itr++;
            }
            prev = tmp;
        }

        return nums.size();
    }
};
