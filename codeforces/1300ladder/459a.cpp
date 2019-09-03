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
    vector< pair<int,int> > resp;

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int maxi = max(x1, max(y1, max(x2, y2)));
    int mini = min(x1, min(y1, min(x2, y2)));

    pair<int,int> aux1 = mk(x1,y1);
    pair<int,int> aux2 = mk(x2, y2);

    if((abs(x1 - x2) == abs(y1 - y2)) or (abs(x1) == abs(x2)) or (abs(y1) == abs(y2))) {
        if(mini != 0 and((aux1.fi == mini and aux1.sec == maxi) or
            (aux2.fi == mini and aux2.sec == maxi)) and ((aux1.fi != aux2.sec) and (aux1.sec != aux2.fi))) {
            resp.pb(mk(mini, 0));
            resp.pb(mk(0, maxi));
            resp.pb(mk(0, 0));
            resp.pb(mk(mini, maxi));
        }
        else if(mini != 0 and((aux1.fi == maxi and aux1.sec == mini) or
            (aux2.fi == maxi and aux2.sec == mini)) and ((aux1.fi != aux2.sec) and (aux1.sec != aux2.fi))) {
            resp.pb(mk(0, mini));
            resp.pb(mk(maxi, 0));
            resp.pb(mk(0, 0));
            resp.pb(mk(maxi, mini));
        } else {
            resp.pb(mk(mini, mini));
            resp.pb(mk(maxi, maxi));
            resp.pb(mk(maxi, mini));
            resp.pb(mk(mini, maxi));
        }
    } else {
        cout << -1 << endl;
        return 0;
    }
    int cont = 0;
    for(int i = 0; i < 4; i++) 
        if(resp[i].fi != aux1.fi or resp[i].sec != aux1.sec)
            if(resp[i].fi != aux2.fi or resp[i].sec != aux2.sec) {
                //cout << resp[i].fi << " " << resp[i].sec << " ";
                cont++;
            }
    if(cont != 2) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < 4; i++) 
        if(resp[i].fi != aux1.fi or resp[i].sec != aux1.sec)
            if(resp[i].fi != aux2.fi or resp[i].sec != aux2.sec)
                cout << resp[i].fi << " " << resp[i].sec << " ";
    cout << endl;

    return 0;
}

