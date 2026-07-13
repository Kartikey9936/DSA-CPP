
// all elements in arrays is unique 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target) return mid ;
            //left half sorted
            if(nums[low]<= nums[mid] ){
                if(nums[low]<= target && nums[mid]> target){
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }

            }

            // right half sorted
            else{
                if(nums[mid]< target && nums[high]>= target){
                    // mid == target already checked
                    low = mid +1;


                }
                else 
                high = mid -1;
        
            }


            
        }
        return -1;

        
    }
};





// all elements in arrays is unique 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target) return mid ;

            // condition check 
            if (nums[low] == nums[mid]&& nums[mid]== nums[high]){
                left = left +1;
                high = high +1;
                continue;
            }

            //left half sorted
            if(nums[low]<= nums[mid] ){
                if(nums[low]<= target && nums[mid]> target){
                    high = mid -1;
                }
                else{
                    low = mid +1;
                }

            }

            // right half sorted
            else{
                if(nums[mid]< target && nums[high]>= target){
                    // mid == target already checked
                    low = mid +1;


                }
                else 
                high = mid -1;
        
            }


            
        }
        return -1;

        
    }
};


#split array into k subarray such that the maximum sum of subarray is minimum

class Solution {
public:

    int count(vector<int>& nums, int total){
        int subarray = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= total){
                sum = sum + nums[i];
            }
            else{
                subarray++;
                sum = nums[i];
            }
        }
        return subarray;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low <= high){
            long long mid = low + (high - low) / 2;

            int countofsub = count(nums, mid);

            if(countofsub > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};