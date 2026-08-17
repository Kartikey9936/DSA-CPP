class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int cnt = 0;
        int maxcnt = 0;

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == 'a' || s[right] == 'e' ||
                s[right] == 'i' || s[right] == 'o' ||
                s[right] == 'u') {
                cnt++;
            }

            if (right - left + 1 > k) {

                if (s[left] == 'a' || s[left] == 'e' ||
                    s[left] == 'i' || s[left] == 'o' ||
                    s[left] == 'u') {
                    cnt--;
                }

                left++;
            }

            if (right - left + 1 == k) {
                maxcnt = max(maxcnt, cnt);
            }
        }

        return maxcnt;
    }
};

FINDING MAXIMUM AVG SUBARRYA
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int right = 0;right<nums.size();right++){
            sum = sum + nums[right];
            if(right - left +1 >k ){
                sum = sum -nums[left];
                left++;

            }
            if (right - left +1 ==k){
            ans = max(ans,sum);
            

            }


        }
        return (double)ans / k;
    }
};


2958. Length of Longest Subarray With at Most K Frequency

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

https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14
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
