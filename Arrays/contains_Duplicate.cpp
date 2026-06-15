#include <bits/stdc++.h>
using namespace std;

// 1. Brute Force (O(n^2))
bool bruteForce(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] == nums[j])
                return true;
        }
    }

    return false;
}

// 2. Hash Map (O(n))
bool usingMap(vector<int>& nums) {
    unordered_map<int, int> mp;

    for(int num : nums) {
        mp[num]++;
    }

    for(auto it : mp) {
        if(it.second > 1)
            return true;
    }

    return false;
}



// Driver code
int main() {
    vector<int> nums = {1, 2, 3, 1};

    cout << "Brute Force: " << (bruteForce(nums) ? "True" : "False") << endl;
    cout << "Hash Map: " << (usingMap(nums) ? "True" : "False") << endl;

    return 0;
}