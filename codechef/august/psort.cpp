#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool cmp(pair<int,int>&a, pair<int,int>&b) {
    return a.fi < b.fi;
}

bool cmp2(pair<int,int>&a, pair<int,int>&b) {
    if(a.fi < b.fi) return true;
    else if(a.fi > b.fi) return false;
    else return a.sec > b.sec;
}

int main() {
    ios::sync_with_stdio(false);
    int P; cin >> P;
    int S; cin >> S;
    vector< pair<int,int> >row[P];
    pair<int,int>tmp[S];
    for(int i = 0; i < P; i++) { 
        for(int j = 0; j < 2; j++) { 
            for(int k = 0; k < S; k++) {
                if(j == 0) cin >> tmp[k].fi;
                else { cin >> tmp[k].sec; row[i].pb(tmp[k]);            }
            }
        }
        sort(row[i].begin(), row[i].end(), cmp);
    }
    
    /*
    for(int i = 0; i < P; i++) { 
        for(int k = 0; k < S; k++) { 
            cout << row[i][k].fi << "," << row[i][k].sec << " ";
        }
        cout << endl;
    }
    */
    
    vector< pair<int,int> >rep;
    for(int i = 0; i < P; i++) {
        pair<int,int> NI;
        NI.fi = 0;
        NI.sec = i + 1;
        for(int k = 0; k < S - 1; k++)
            if(row[i][k].sec > row[i][k+1].sec) NI.fi++;
        rep.pb(NI);
    }

    sort(rep.begin(), rep.end(), cmp2);
    for(int i = 0; i < P; i++)
        cout /*<< rep[i].fi << ","*/ <<rep[i].sec << endl;
            
    return 0;
}

