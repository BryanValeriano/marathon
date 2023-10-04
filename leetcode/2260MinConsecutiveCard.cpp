#include <algorithm>
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
  int twoPointers(vector<int> &cards) {
    int l = 0;
    int r = 0;
    int n = cards.size();
    int minInterval = INF;
    vector<int> dict(1e6 + 5, 0);

    while (r < n) {
      if (!dict[cards[r]]) {
        dict[cards[r]]++;
        r++;
      } else {
        if (cards[l] == cards[r]) {
          minInterval = min(minInterval, r - l + 1);
        }
        dict[cards[l]]--;
        l++;
      }
    }

    return minInterval == INF ? -1 : minInterval;
  }

  int minimumCardPickup(vector<int> &cards) {
    int minInterval = twoPointers(cards);
    return minInterval;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> cards;
  Solution *solution = new Solution();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cards.pb(x);
  }
  cout << solution->minimumCardPickup(cards) << endl;
  return 0;
}
