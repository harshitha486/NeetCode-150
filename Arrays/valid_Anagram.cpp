#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int x : freq) {
        if (x != 0)
            return false;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << (isAnagram(s, t) ? "True" : "False") << endl;

    return 0;
}