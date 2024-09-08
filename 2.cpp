#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int wordBreak(string s, vector<string>& dictionary) {
    unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;  
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()] ? 1 : 0;
}
int main() {
    string s = "applepenapple";
    vector<string> dictionary = {"apple", "pen"};
    cout << wordBreak(s, dictionary) << endl; 
    return 0;
}
