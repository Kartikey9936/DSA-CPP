#include<bits/stdc++.h>
using namespace std;
int p(vector<int> &arr, int low,int high){
    int p_indx = arr[low];
    i = low
    j = high

    while(i<j)


}
void qs(vector<int> &arr,int low, int high){
    if(low<high){
        int p_indx = p(arr,low,high);
        qs(arr,low,p_indx-1);
        qs(arr,p_indx+1,high);
    }

}
// #passing array in function
vecto<int> quicksort(vector<int> arr){
    qs(arr,0,arr.size-1);
}

int main() {

    
}


