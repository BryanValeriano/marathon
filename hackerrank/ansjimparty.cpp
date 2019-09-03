#include <iostream>
#include <vector>
using namespace std;
#define SZ(x) ( (int) (x).size() )
const int MAX_N = 100000 + 1;
int N, M, Q;
int color[MAX_N];
vector<int> cpos[MAX_N];
vector<int> q[MAX_N];
int qu[MAX_N], qv[MAX_N];
int lo[MAX_N], hi[MAX_N];
// implementation of UFDS
int f[MAX_N];
int getf(int x){
  return f[x] == x ? x : f[x] = getf(f[x]);
}
void mergef(int x, int y){
  f[getf(x)] = getf(y);
}
void initf(){
  for(int i = 1; i <= N; i++){
    f[i] = i;
  }
}

void reloadQueries(){
  for(int i = 0; i <= Q; i++){
    q[i].clear();
  }
  for(int i = 1; i <= M; i++){
    q[(lo[i] + hi[i]) / 2].push_back(i);
  }
}

void answerQuery(int c){
  bool connected = true;
  for(int i = 1; i < (int) cpos[c].size(); i++){
    connected &= getf(cpos[c][i]) == getf(cpos[c][i - 1]);
  }
  int mid = (lo[c] + hi[c]) / 2;
  if(!connected){
    lo[c] = mid + 1;
  } else {
    hi[c] = mid;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M >> Q;
  for(int i = 1; i <= N; i++){
    cin >> color[i];
    cpos[color[i]].push_back(i);
  }
  for(int i = 1; i <= M; i++){
    lo[i] = 0, hi[i] = Q;
  }
  for(int i = 1; i <= Q; i++){
    cin >> qu[i] >> qv[i];
  }
  for(int times = 25; times >= 0; times --){
    initf();
    reloadQueries();
    for(int i = 0; i <= Q; i++){
	if(i > 0)
    mergef(qu[i], qv[i]);
      for(int j = 0; j < SZ(q[i]); j++){
    answerQuery(q[i][j]);
      }
    }
  }
  for(int i = 1; i <= M; i++){
    if(lo[i] > Q){
      cout << -1 << '\n';
    } else {
      cout << lo[i] << '\n';
    }
  }
  return 0;
}
