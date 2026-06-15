#include <bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int> nums,int k){
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1 ; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == k) {
                return true;
                // return i , j;
            }
            

        }
        
    }
    return false;
}

bool better(vector<int> nums, int k){
    map<int,int> hashMap;
    int rem = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        rem = k - nums[i];
        if(hashMap.find(rem) != hashMap.end()) return true; /* return hashMap[rem], i;*/
        if(hashMap.find(nums[i]) == hashMap.end()) hashMap[nums[i]] = i;
    }
    return false;
}

bool optimal(vector<int> nums, int k ){
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right){
        if(nums[left]+nums[right] == k) return true;
        else if(nums[left]+nums[right] > k){
            right--;
        }
            
        else 
            left++ ;
    }
    return false;
}


int main(){
    vector<int> nums {2,3,6,8,11};
    int k;
    cin >> k;
    cout << bruteForce(nums,k);
    cout << better(nums,k);
    cout << optimal(nums,k);

}


// 2sum contains two types of approaches
// 1. return true or false
// 2. return indexes

// return true or false brute-> better-> optimal
// return indexes brute-> better here the better is optimal 