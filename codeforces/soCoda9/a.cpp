#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;

const int T = 1e3 + 3;
int v[T][T];
ii id[T][T];
vti aux[T][T];
int n,m,q;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> v[i][j];

    while(q--) {
        int a,b,c,d,h,w;
        cin >> a >> b >> c >> d >> h >> w;
        for(int i = 0; i < h; i++) {
            aux[a+i][b].eb(c+i,d,b,q+1);
            aux[a+i][b+w].eb(c+i,d,b,-(q+1));
            aux[c+i][d].eb(a+i,b,d,q+1);
            aux[c+i][d+w].eb(a+i,b,d,-(q+1));
        }
    }

    set<ti> bag;
    for(int i = 1; i <= n; i++) {
        int ni,nj,start,q;
        for(int j = 1; j <= m; j++) {
            while(!aux[i][j].empty()) {
                tie(ni,nj,start,q) = aux[i][j].back();
                if(q<0) bag.erase(make_tuple(-q,ni,nj,start));
                else bag.emplace(q,ni,nj,start);
                aux[i][j].pop_back();
            }
            if(bag.empty()) id[i][j] = mk(i,j);
            else {
                tie(q,ni,nj,start) = *bag.begin();
                id[i][j] = mk(ni,nj+(j-start));
            }
        }
        while(!aux[i][m+1].empty()) {
            tie(ni,nj,start,q) = aux[i][m+1].back();
            if(q<0) bag.erase(make_tuple(-q,ni,nj,start));
            else bag.emplace(q,ni,nj,start);
            aux[i][m+1].pop_back();
        }
    }


    return 0;
}

