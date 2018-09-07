#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int tam, turn;
    cin >> tam >> turn;
    int resp = 0;
    int row[tam+1];
    memset(row, 0, sizeof row);
    int espatula = turn + 1 + turn;
    vector<int>track;
    bool flag = false;
    for(int i = 1; i <= tam; i++) {
        if(row[i] == 0) {
            resp++;
            if(i+turn > tam) flag = true;
            track.pb(min(tam,  i + turn));
            i += espatula - 1;
        }
    }
    if(flag) {
        memset(row, 0, sizeof row);
        track.clear();
        track.pb(1);
        resp = 1;
        for(int i = 2 + turn; i <= tam; i++) {
            resp++;
            track.pb(min(tam,  i + turn));
            i += espatula - 1;
        }
    }
    cout << resp << endl;    
    for(int i = 0; i < track.size(); i++) 
        cout << track[i] << " ";
    cout << endl;
    return 0;
}

