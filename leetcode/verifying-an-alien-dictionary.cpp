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

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

class Solution {
public:
  bool isWordAAlienGreaterThanB(string &a, string &b,
                                vector<int> &letterOrder) {
    for (int letter = 0; letter < min(a.size(), b.size()); letter++) {
      int posALetter = letterOrder[a[letter] - 'a'];
      int posBLetter = letterOrder[b[letter] - 'a'];
      if (posALetter > posBLetter) {
        return true;
      }
      if (posALetter < posBLetter) {
        return false;
      }
    }
    return a.size() > b.size();
  }

  bool isAlienSorted(vector<string> &words, string order) {
    vector<int> letterOrder(27, 0);
    for (int i = 0; i < order.size(); i++) {
      letterOrder[order[i] - 'a'] = i;
    }

    string last = words[0];

    for (string word : words) {
      if (isWordAAlienGreaterThanB(last, word, letterOrder)) {
        return false;
      }
      last = word;
    }

    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  vector<string> words = {"word", "world", "row"};
  string order = "worldabcefghijkmnpqstuvxyz";
  Solution *solution = new Solution();
  bool ans = solution->isAlienSorted(words, order);
  cout << (ans ? "true" : "false") << endl;
  words = {"hello", "leetcode"};
  order = "hlabcdefgijkmnopqrstuvwxyz";
  ans = solution->isAlienSorted(words, order);
  cout << (ans ? "true" : "false") << endl;
  return 0;
}
