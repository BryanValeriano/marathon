#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pair<int,int> p1 = mk(x1, y1);
    pair<int,int> p2 = mk(x2, y2);
    int x = max(x1, x2) - min(x1, x2);
    int y = max(y1, y2) - min(y1, y2);
    int dist = max(x,y);
    set< pair<int,int> > s[6];

    for(int i = 1; i <= 4; i++) 
        s[i].insert(mk(x1, y1));
    
    s[1].insert(mk(x1+dist, y1));
    s[1].insert(mk(x1+dist, y1-dist));
    s[1].insert(mk(x1, y1-dist));

    s[2].insert(mk(x1-dist, y1));
    s[2].insert(mk(x1-dist, y1-dist));
    s[2].insert(mk(x1, y1-dist));

    s[3].insert(mk(x1, y1+dist));
    s[3].insert(mk(x1-dist, y1+dist));
    s[3].insert(mk(x1-dist, y1));

    s[4].insert(mk(x1+dist, y1));
    s[4].insert(mk(x1+dist, y1+dist));
    s[4].insert(mk(x1, y1+dist));

    int sinal = 1;
    for(int i = 1; i <= 4; i++) {
        if(s[i].count(p1) && s[i].count(p2) and sinal) { 
            for(auto id : s[i]) { 
                //cout << id.fi << " " << id.sec << ", ";
                if(id.fi != p1.fi or id.sec != p1.sec) 
                    if(id.fi != p2.fi or id.sec != p2.sec) { 
                        cout << id.fi << " " << id.sec << " ";
                        sinal = 0;
                    }
            }
            //cout << endl;
        }
    }
                
            
    if(sinal) cout << -1; 
    cout << endl;

    return 0;
}

