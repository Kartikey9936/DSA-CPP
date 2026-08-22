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

only 800 cases https://leetcode.com/problems/find-the-largest-almost-missing-integer/?envType=daily-question&envId=2026-08-18
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int ans = -1;
        if (k == n) {
        

        unordered_map<int, int> cnt;

        for (int right = 0; right < n; right++) {

            if (right - left + 1 > k) {
                left++;
            }

            if (right - left + 1 == k) {

                unordered_map<int, int> mpp;

                // Count frequency in current window
                for (int i = left; i <= right; i++) {
                    mpp[nums[i]]++;
                }

                // Count how many windows contain the number exactly once
                for (auto it : mpp) {
                    if (it.second == 1) {
                        cnt[it.first]++;
                    }
                }
            }
        }

        // Find largest number appearing in exactly one window
        for (auto it : cnt) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};

optimizexd 
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> windowCount;

        // Check every window of size k
        for (int left = 0; left <= n - k; left++) {

            unordered_set<int> seen;

            for (int i = left; i < left + k; i++) {
                seen.insert(nums[i]);
            }

            // Count how many windows contain each number
            for (int x : seen) {
                windowCount[x]++;
            }
        }

        int ans = -1;

        // Number appearing in exactly one window
        for (auto it : windowCount) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};

20 aug 
vector<int> arr1;
vector<int> arr2;

arr1.push_back(nums[0]);
arr2.push_back(nums[1]);

for(int i = 2; i < nums.size(); i++){
    if(arr1.back() > arr2.back()){
        arr1.push_back(nums[i]);
    }
    else{
        arr2.push_back(nums[i]);
    }
    for()
    for()



}

https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int num = n;
        while(n>0){
            sum = sum +n%10;
            product= product*(n%10);
            n =n/10;
             
        }
        int total = sum + product;
        if(num%total == 0){
        return true;}
        return false;
       
        
    }
};

int num = n;  // preserve original

while(n > 0) {
    // modify n
}

// use num for the original number

also use product*(n%10) not product*n%10

kth smallest coin value https://leetcode.com/problems/find-the-kth-smallest-value-of-a-matrix-with-sorted-rows-and-columns/?envType=daily-question&envId=2026-08-23
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        set<long long> ans;
        for(int i=0;i<coins.size();i++){
            for(int j =1;j<k;j++){
                ans.insert(1LL*coins[i]*j);
            }
        }
        int final_coin;
        for(auto it:ans){
            k--;
            if(k==0){
                final_coin=it;
                break;
            }
        }
        return final_coin;
        
    }
};

