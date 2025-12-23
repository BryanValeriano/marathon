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

struct chapter {
  int index;
  chapter(int i) { index = i; }
};

int toposort(vector<vector<chapter>> &graph, vector<int> &degree) {
  int visited = 0;
  int ans = 1;
  queue<chapter> chapters;
  vector<int> timesNeedToRead(graph.size(), 1);

  for (int i = 0; i < degree.size(); i++) {
    if (degree[i] == 0) {
      chapters.emplace(i);
    }
  }

  while (!chapters.empty()) {
    chapter curentChapter = chapters.front();
    chapters.pop();
    visited++;
    ans = max(ans, timesNeedToRead[curentChapter.index]);

    for (chapter neighbour : graph[curentChapter.index]) {
      degree[neighbour.index]--;
      timesNeedToRead[neighbour.index] =
          max(timesNeedToRead[neighbour.index],
              timesNeedToRead[curentChapter.index] +
                  (int)(curentChapter.index > neighbour.index));
      if (degree[neighbour.index] == 0) {
        chapters.emplace(neighbour.index);
      }
    }
  }

  return (visited == graph.size() ? ans : -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int nChapters;
    cin >> nChapters;
    vector<vector<chapter>> graph(nChapters, vector<chapter>());
    vector<int> degree(nChapters, 0);
    for (int i = 0; i < nChapters; i++) {
      int kRequiredBefore;
      cin >> kRequiredBefore;
      degree[i] = kRequiredBefore;
      for (int j = 0; j < kRequiredBefore; j++) {
        int chap;
        cin >> chap;
        chap--;
        graph[chap].emplace_back(i);
      }
    }
    cout << toposort(graph, degree) << endl;
  }

  return 0;
}
