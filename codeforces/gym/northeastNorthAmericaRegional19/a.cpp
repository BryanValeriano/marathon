#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+4;
ll v[2][T];
map<ll,int> bag;

ll inv(ll x) {
    string s = to_string(x);
    string t(s.rbegin(), s.rend());
    for(int i = 0; i < t.size(); i++) {
        if (t[i] == '6') t[i] = '9';
        else if (t[i] == '9') t[i] = '6';
        else if (t[i] == '3' or t[i] == '4' or t[i] == '7') return x;
    }

    return stoll(t);
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; ll s;
    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> v[0][i];
        v[1][i] = inv(v[0][i]);
        bag[v[0][i]]++;
        bag[v[1][i]]++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            bag[v[!j][i]]--;
            bag[v[j][i]]--;
            ll need = s - v[j][i];
            if(bag[need]>0) {
                cout << "YES" << endl;
                return 0;
            }
            bag[v[!j][i]]++;
            bag[v[j][i]]++;
        }
    }

    cout << "NO" << endl;



    return 0;
}

