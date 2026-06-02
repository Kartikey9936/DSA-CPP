// #include<iostream>
// using namespace std;
// int main() {
//     char grade;
//     cout<<"enter your makrs:"<<endl;
//     cin>>grade;
//     if(grade == A){
//         cout<<"you are 50" <<endl;
//     }
//     else if(grade == B){
//         cout<<"you are 60"<<endl;
//     }
//     else{
//         cout<<"you are 50"<<endl;
//     }




//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main() {
//     char grade;
//     cout<<"enter your grade:"<<endl;
//     cin>>grade;
//     if(grade == 'A'){
//         cout<<"you are 50" <<endl;
//     }
//     else if(grade == 'B'){
//         cout<<"you are 60"<<endl;
//     }
//     else{
//         cout<<"you are 100"<<endl;
//     }




//     return 0;
// }

#include<iostream>
using namespace std;
int main() {
    char grade;
    cout<<"enter your grade:"<<endl;
    cin>>grade;
    switch(grade){
        case 'A': cout<< "your marks is 100" <<endl;
        break;
        case 'B': cout<< "your amrks is 80"  <<endl;
        break;
        default : cout<< "you are failed" <<endl;


    }
    




    return 0;
}
