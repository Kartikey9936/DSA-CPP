#include<bits/stdc++.h>
using namespace std;

int secLargest(vector<int> &a, int n){
    int sLargest = a[0];
    int sSmallest = -1;

}
vector<int> getsecondorder(int n , vector<int> a){
    int sLargest = secLargest(a,n);
    int sSmallest = secSmallest(a ,n);
    return {sLargest,sSmallest};
}


// finding duplicate in sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        for(int j=0;j<n;j++){
         if(nums[j]!=nums[i]){
            nums[i+1] = nums[j];
            i++;

         }
           
        }
        return i+1;

        
    }
};


int i =0;
int j=0;
while(i<n1 && j<n2){
    if(a[i]<=b[j]){
        if(unionArr.size()==0 || unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    else{
        if(unionArr.size()==0 || unionArr.back()!=b[j]){
            unionArr.push_back(b[j]);
        }
        j++;

    }

while(i<n1){
    if(unionArr.size()==0 || unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;

}
while(j<n2){
    if(unionArr.size()==0 || unionArr.back()!=b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    
}




vector<int> intersection(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size()) {

        if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    return ans;
}
