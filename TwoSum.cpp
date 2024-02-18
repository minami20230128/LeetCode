#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;
    int target;
    std::vector<int> results;
    for(auto&& first : nums)
    {
        for(auto&& second : nums)
        {
            if(first + second == target)
            {
                results.push_back(first);
                results.push_back(second);
                break;
            }
        }
    }

    for(auto&& result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}