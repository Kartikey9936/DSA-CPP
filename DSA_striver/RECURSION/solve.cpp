pow(x,n)
BRUTE FORCE APPROACH
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n >0){
            
        for(int i = 1;i<=n;i++){
            ans = ans*x;
        }
        }
        else if (n ==0) return 1;
        else{

        for(int i = -1;i>=n;i--){
            ans = ans*x;
            
        }
        return 1 / ans;
        }
        return ans;
        
        
    }
};

leetcode 50 optimal solution
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans = 1;
        for(int i = 0;i<n;i++){
            if(i % 2 == 0){
                ans = ans*5;
            }
            else{
                ans= ans*4;
            }
        }
        return ans;
        
    }
};

leetcode 50
class Solution {
public:
    void findcombination(int ind ,int target, vector<int>& candidates,vector<vector<int>> &ans,vector<int>&ds ){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i<candidates.size();i++){
            if(i>ind && candidates[i]== candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findcombination(ind+1,target-candidates[i],candidates,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0,target,candidates,ans,ds)
        return ans;

        
    }
};

leetcode 198
class Solution {
public:
      void subset(int ind,vector<int>& nums, vector<int>& ds ,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = ind;i<nums.size();i++){
            if(i != ind && nums[i]== nums[i-1]) continue; //continue i will not pick 
            ds.push_back(nums[i]);
            subset(i+1,nums,ds,ans);
            ds.pop_back();

        }
      }




    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subset(0,nums,ds,ans);
        return ans;



        
    }
};

leetcode 216 without duplicate
class Solution {
public: 
       void combination(int num,vector<int> &ds,int k , int target,vector<vector<int>>& ans){
        if(k==0 && target == 0){
            ans.push_back(ds);
            return;
        }
        if(k==0 && target<0){
            return;
        }
        for(int i = num ; i<=9;i++){
            ds.push_back(i);
            combination(i+1,ds,k-1,target-i,ans);
            ds.pop_back();
        }
       
        
       }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination(1,ds,k,n,ans);
        return ans;

        
    }
};


https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void solve(int index, string& digits, unordered_map<char, string>& mp,
               string& ds, vector<string>& ans){
                if(index == digits.size()){
                    ans.push_back(ds);
                    return;
                }

                string letter = mp[digits[index]];
                for(char ch : letter){
                    ds.push_back(ch);
                    solve(index+1,digits,mp,ds,ans);
                    ds.pop_back(); //backtracking me remove kiya
                }

               }


    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
            

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        string ds;
        solve(0,digits,mp,ds,ans);
        return ans;


    }
};

leetcode.com/problems/subsets/
class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& ds, int index,
                   vector<vector<int>>& ans) {
        
        if (index == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Don't take
        backtrack(nums, ds, index + 1, ans);

        // Take
        ds.push_back(nums[index]);
        backtrack(nums, ds, index + 1, ans);
        ds.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        backtrack(nums, ds, 0, ans);

        return ans;
    }
};