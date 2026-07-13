// #include<bits/stdc++.h>
// using namespace std;
// // #passing array in function
// void f(int i, int arr[], int n ){
//     if(i>=n/2) return;
// swap(arr[i],arr[n-1-i]);
// f(i+1,arr,n);

// }


// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i =0; i<n;i++) cin>>arr[i];
//     f(0,arr,n);
//     for(int i =0;i<n;i++) cout<<arr[i];

    
    
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
// #passing array in function
bool f(int i, string &s){
    if(i >=s.size()/2) return true;
    if (s[i]!= s[s.size()-1-i]) return false;
    return f(i+1,s);


}


int main() {

    string s = "madam";
    cout << f(0,s);

   

    
    
    return 0;
}