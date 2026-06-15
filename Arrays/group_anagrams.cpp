#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Brute Force Solution
vector<vector<string>> groupAnagramsBrute(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        vector<string> group;
        string s1 = strs[i];
        sort(s1.begin(), s1.end());

        group.push_back(strs[i]);
        visited[i] = true;

        for (int j = i + 1; j < n; j++) {
            if (visited[j]) continue;

            string s2 = strs[j];
            sort(s2.begin(), s2.end());

            if (s1 == s2) {
                group.push_back(strs[j]);
                visited[j] = true;
            }
        }

        ans.push_back(group);
    }

    return ans;
}

// Optimal Solution
vector<vector<string>> groupAnagramsOptimal(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());

        mp[key].push_back(str);
    }

    vector<vector<string>> ans;

    for (auto &it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}

// Helper function to print result
void printGroups(vector<vector<string>>& groups) {
    for (auto &group : groups) {
        cout << "[ ";
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << "Brute Force Solution:\n";
    vector<vector<string>> bruteAns = groupAnagramsBrute(strs);
    printGroups(bruteAns);

    cout << "\nOptimal Solution:\n";
    vector<vector<string>> optimalAns = groupAnagramsOptimal(strs);
    printGroups(optimalAns);

    return 0;
}