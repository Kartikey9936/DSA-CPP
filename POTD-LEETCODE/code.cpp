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

https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int sum = 0;
        int cnt = 0;
        for(int right = 0;right<arr.size();right++){
            sum = sum +arr[right];
            if(right - left +1 >k){
                sum = sum -arr[left];
                left++;
            }
            if(right-left +1 ==k && sum >= threshold*k){
                cnt++;
            }

        }
        return cnt;
    }
};

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mpp;
        int left = 0;
        int length =0;
        for(int right = 0;right<s.size();right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>2){
                mpp[s[left]]--;
                left++;
            }
            length = max(length,right-left+1);

        }
        return length;
          
    }
};