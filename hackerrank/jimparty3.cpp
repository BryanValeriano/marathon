#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 3;
int visit[T];
int dist[T];
int maxjogos[T];
int amigojogo[T];
int qtdjogo[T];
vector<pii>graph[T];
set<int>track;
vector<int>trackjogo[T];

void dfs(int atual, int p) {
    if(visit[atual]) return;
    visit[atual] = 1;
    track.insert(amigojogo[atual]);
    for(int i = 0; i < graph[atual].size(); i++) {
        int filho = graph[atual][i].fi;
        int dis = max(graph[atual][i].se, p);
        if(dist[atual] > dis) dist[atual] = dis;
        if(dist[filho] > dis) dist[filho] = dis;
        dfs(filho, p+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int amigos, jogos, fios;
    cin >> amigos >> jogos >> fios;
    for(int i = 1; i <= amigos; i++) {
        cin >> amigojogo[i];
        qtdjogo[amigojogo[i]]++;
        trackjogo[amigojogo[i]].pb(i);
    }
    memset(dist, INF, sizeof dist); 
    for(int i = 1; i <= jogos; i++) 
        if(qtdjogo[i] == 1) { maxjogos[i] = 0; dist[i] = 0; }

    for(int i = 1; i <= fios; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(mp(b,i));
        graph[b].pb(mp(a,i));
    }
        

    for(int i = 1; i <= amigos; i++) {
        if(!visit[i] && qtdjogo[i] != 1) { 
            int p = 1;
            if(graph[i].size() != 0) p = graph[i][0].se;
            dfs(i,p);
            for(auto jogo : track) {
                for(int k = 0; k < trackjogo[jogo].size(); k++) { 
                    int a = trackjogo[jogo][k];
                    if(dist[a] == INF) { maxjogos[jogo] = INF; break; }
                    maxjogos[jogo] = max(maxjogos[jogo], dist[a]);
                }
            }
            track.clear();
        }
    }
        
    for(int i = 1; i <= jogos; i++)
        cout << (maxjogos[i] == INF? -1 : maxjogos[i]) << endl;
    return 0;
}

