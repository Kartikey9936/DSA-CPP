length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int right = 0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp[nums[right]] > k){
                mpp[nums[left]]--;
                left++;
                

            }
            ans = max(ans,right-left+1);

        }
        return ans;
        
    }
};

