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

//  diagonal superior direita  {-1,1}
//  direita                    {0, 1} baixo   {1,0}
//  diagonal inferior esquerda {1,-1}
//  baixo                      {1, 0} direita {0,1}

class Solution {
public:
  pair<int, int> getNextPos(pair<int, int> at, pair<int, int> mov) {
    return make_pair(at.first + mov.first, at.second + mov.second);
  }

  bool isInside(int x, int y, pair<int, int> pos) {
    int xx = pos.first;
    int yy = pos.second;
    return (xx >= 0 && xx <= x && yy >= 0 && yy <= y);
  }

  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    vector<int> order;
    vector<pair<int, int>> movWhileTrue = {{-1, 1}, {1, -1}};
    vector<pair<int, int>> movOneTime = {{0, 1}, {1, 0}};

    int visited = 0;
    int n = mat.size();
    int m = mat[0].size();
    int needToVisit = n * m;
    pair<int, int> posAt = make_pair(0, 0);
    int posMovWhile = 0;

    while (true) {
      visited++;
      order.push_back(mat[posAt.first][posAt.second]);
      if (visited == needToVisit) {
        break;
      }
      int attempt = 0;
      pair<int, int> nextPos = getNextPos(posAt, movWhileTrue[posMovWhile]);
      while (!isInside(n - 1, m - 1, nextPos)) {
        nextPos = getNextPos(posAt, movOneTime[(posMovWhile + attempt) % 2]);
        attempt++;
      }

      posAt = nextPos;
      if (attempt > 0) {
        posMovWhile = (posMovWhile + 1) % 2;
      }
    }

    return order;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  vector<int> ans = solution->findDiagonalOrder(mat);
  for (int x : ans) {
    cout << x << endl;
  }
  return 0;
}
