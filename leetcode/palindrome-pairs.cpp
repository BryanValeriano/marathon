#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

class Solution {
public:
  bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  vector<vector<int>> palindromePairs(vector<string> &words) {
    unordered_map<string, int> wordsIndex;
    vector<vector<int>> ans;
    for (int i = 0; i < words.size(); i++) {
      string s = words[i];
      wordsIndex[s] = i;
    }

    for (int i = 0; i < words.size(); i++) {
      string s = words[i];
      int n = words[i].size();
      for (int j = 0; j <= words[i].size(); j++) {
        // if prefix is palindrome
        if (isPalindrome(s, 0, j - 1)) {
          string suffix(s.begin() + j, s.end());
          string reverseSuffix(suffix.rbegin(), suffix.rend());
          if (wordsIndex.count(reverseSuffix) &&
              wordsIndex[reverseSuffix] != i) {
            ans.push_back({wordsIndex[reverseSuffix], i});
          }
        }
        // if suffix is palindrome
        if (j != n && isPalindrome(s, j, n - 1)) {
          string prefix(s.begin(), s.begin() + j);
          string reversePrefix(prefix.rbegin(), prefix.rend());
          if (wordsIndex.count(reversePrefix) &&
              wordsIndex[reversePrefix] != i) {
            ans.push_back({i, wordsIndex[reversePrefix]});
          }
        }
      }
    }
    return ans;
  }
};

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution;
  vector<string> input = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> ans = solution->palindromePairs(input);
  for (auto a : ans) {
    cout << a[0] << ", " << a[1] << endl;
  }

  return 0;
}
