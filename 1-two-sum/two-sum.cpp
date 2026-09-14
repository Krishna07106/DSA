#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Boosts C++ input/output speed
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        // The "memory box": Maps the number value to its index
        std::unordered_map<int, int> seen_numbers; 
        
        // Loop through the vector step-by-step
        for (int i = 0; i < nums.size(); ++i) {
            int current_num = nums[i];
            int complement = target - current_num;
            
            // Check if the complement exists in our map
            if (seen_numbers.find(complement) != seen_numbers.end()) {
                // Found it! Return a vector containing both indices
                return {seen_numbers[complement], i};
            }
            
            // If not found, save the current number and its index for later
            seen_numbers[current_num] = i;
        }
        
        // LeetCode requires a return path for all scenarios, 
        // even though the problem guarantees exactly one solution.
        return {}; 
    }
};
