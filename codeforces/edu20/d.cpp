#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

vector<int> v;
int linhas;

bool check(int x) {
    int l = 0;
    int at = 0;
    int i = 0;

    while(i < v.size()) {
        if(at > x) return false;
        if(at + v[i] <= x) at += v[i];
        else if(at == 0) return false;
        else l++, at = v[i];
        i++;
    }

    return (l < linhas);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> linhas;
    string s;
    getline(cin,s);
    s = "";
    getline(cin,s);

    int x = 0;
    for(int i = 0; i < s.size(); i++) {
        x++;
        if(s[i] == ' ' or s[i] == '-') {
            v.pb(x);
            x = 0;
        }
    }
    v.pb(x);

    int l = 1;
    int r = s.size();

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }

    cout << l << endl;
    
    return 0;
}

