// # remove outermost parenthesis from the string
// #reverse words in a string
// #largesr odd number in a string
// #largest common prefix in a string
// #string isomorphic hashmap(mapping)




// is string is anagam(no of frequency of each character should be same)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        map<char,int> mpp1;
        map<char,int> mpp2;
        for(int i =0;i<s.size();i++){
           mpp1[s[i]]++;
           mpp2[t[i]]++;
        }
        if(mpp1 == mpp2){
            return true;
        }
        else{
            return false;
        }
        
    }
};

