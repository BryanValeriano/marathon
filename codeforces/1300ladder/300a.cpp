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
    vector<int>neg;
    vector<int>pos;
    vector<int>ze;
    int n; cin >> n;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(aux > 0 && pos.size() < 1) pos.pb(aux);
        else if(aux < 0 && neg.size() < 1) neg.pb(aux);
        else ze.pb(aux);
    }
    if(pos.size() == 0) {
        int i = 0;
        while(pos.size() < 2 && i < ze.size()) {
            if(ze[i] < 0) {
                pos.pb(ze[i]);
                ze.erase(ze.begin() + i);
                i--;
            }
            i++;
        }
    }
    cout << neg.size() << " ";
    for(auto id : neg)
        cout << id << " ";
    cout << endl;
    cout << pos.size() << " ";
    for(auto id : pos)
        cout << id << " ";
    cout << endl;
        cout << ze.size() << " ";
    for(auto id : ze)
        cout << id << " ";
    cout << endl;

    return 0;
}

