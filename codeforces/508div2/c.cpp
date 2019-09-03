#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
bool cmp(int a, int b) {
    return a < b;
}

int main()
{
    int n; cin >> n;
    vector<int> s1;
    vector<int> s2;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        s1.pb(aux);
    }

    for(int i = 0; i < n; i++) {
        cin >> aux;
        s2.pb(aux);
    }

    sort(s1.begin(), s1.end(), cmp);
    sort(s2.begin(), s2.end(), cmp);
    
    int turno = 0;
    ll score1 = 0;
    ll score2 = 0;
    while(s1.size() and s2.size()) {
        if(turno == 0) {
            if(s2.back() >= s1.back())
                s2.pop_back();
            else {
                score1 += s1.back();
                s1.pop_back();
            }
        }
        else if(turno == 1) {
            if(s1.back() >= s2.back())
                s1.pop_back();
            else {
                score2 += s2.back();
                s2.pop_back();
            }
        }
        turno = 1 - turno;
    }
    if(s1.size()) {
        if(turno == 0) {
            score1 += s1.back();
            s1.pop_back();
        }
        else if(turno == 1) s1.pop_back();
        turno = 1 - turno; 
    }
    else if(s2.size()) {
        if(turno == 0) s2.pop_back();
        else if(turno == 1) {
            score2 += s2.back();
            s2.pop_back();
        }
    }
    cout << score1 - score2 << endl;
    return 0;
}

