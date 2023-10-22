#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> bagOfLetters(32, 0);
    for (char c : s) {
      bagOfLetters[c - 'a']++;
    }
    for (char c : t) {
      bagOfLetters[c - 'a']--;
    }
    for (int quantity : bagOfLetters) {
      if (quantity != 0)
        return false;
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  Solution *solution = new Solution();
  cin >> s >> t;
  cout << solution->isAnagram(s, t) << endl;
  return 0;
}
