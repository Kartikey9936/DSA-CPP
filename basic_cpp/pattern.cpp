#include<iostream>
using namespace std;

// void print(int n){
//     for(int i =0; i <=n ; i++){
//         for (int j = 1; j<=i ; j++){
//             cout<<i;
//         }
//         cout<< endl;
//     }
// }

// void print1(int n){
//     for(int i =0; i <=n ; i++){
//         for (int j = 1; j<=i; j++){
//             cout<<i;
//         }
//         cout<< endl;
//     }
// }

// void print2(int n){
//     for(int i =1; i <=n ; i++){
//         for (int j = 1; j<=i; j++){
//             cout<<j;
//         }
//         cout<< endl;
//     }
// }

// for inverted replace i-- n-i+1

// void print3(int n){
//     for(int i =1; i <=n ; i++){
//         for (int j = 1; j<=n-i+1; j++){
//             cout<<j;
//         }
//         cout<< endl;
//     }
// }

// void print4(int n){

//     for(int i =0; i<n; i++){
//         for (int j =1; j<=i; j++){
//             cout<<j ;

//         }

//         for (int j =1; j<=i; j++){
            
//         }

//         for (int j =i; j>=1; j--){
//             cout << j;
            
//         }





//     }

// }


// int main() {
//     int n;
//     cin>> n;
//     print4(n);

//     return 0;
// }

// int num =1;
// void print5(int n){

//     for(int i =0; i<n; i++){
//         for (int j =0; j<=i; j++){
//             cout<<num ;
//             num = num +1;
//             cout<<" ";

//         }
  
//     cout << endl;

//     }

// }

// int main() {
//     int n;
//     cin>> n;
//     print5(n);

//     return 0;
// }





void print6(int n){

    for(int i =0; i<n; i++){
        for (char ch ='A'; ch <= 'A'+i;ch++){
            cout<<ch;
           

        }
  
    cout << endl;

    }

}

int main() {
    int n;
    cin>> n;
    print6(n);

    return 0;
}