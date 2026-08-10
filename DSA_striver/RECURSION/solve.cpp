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
