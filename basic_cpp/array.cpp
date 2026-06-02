// An array is a collection of elements of the same data type stored in contiguous memory locations

// data_type array_name [size]
// int arr[4]
// Traversing means visiting each element one by one.
// The advantage of array is that it can be easily traversed by using a loop with loop variable that runs from 0 to size - 1


// #include<iostream>
// using namespace std;
// int main() {

//     int arr[5];
//     for(int i = 0;i<5; i =i+1){
//         cout <<"enter the value of arr["<<i<<"]";
//         cin>>arr[i];
//         cout<< endl;
//     }
//     for(int i = 0;i<5; i =i+1){
//         cout<<arr[i]<< " ";
//     }

    
    
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main() {
//     int arr[] = {10,20,30,40,50};
//     int sum =0;
//     for (int i = 0; i <=4 ;i = i+1){
//         sum = sum + arr[i];

//     }
//     cout << sum <<endl;
    
//     return 0;
// }


// passing an array in function , with size arr[size]
// void ( int arr[], int size)

// #include<iostream>
// using namespace std;

//     void printArray( int arr[], int size){
//         for (int index ; index <= size ;index = index +1){
//             cout << arr[index] <<" ";
//         }


//     }

// int main() {

//     int arr[] = {10,20,30,40,50};
//     int size = 5;

//     printArray(arr,size);

  
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main() {

//     // int arr[2][4];
//     int arr[2][4] = {{1,2,3,4},{5,6,7,8}};

//     cout << arr[0][1] <<endl;

    
    
//     return 0;
// }

#include<iostream>
using namespace std;
int main() {

    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int row = 3;
    int col = 4;
    for(int row_index = 0; row_index <= row -1 ;row_index++ ){
        for(int col_index = 0;col_index <= col -1; col_index++){
            cout << arr[row_index][col_index] << " " ;

        }

        cout << endl;
    }

    
    
    return 0;
}