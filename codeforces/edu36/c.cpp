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

string aa,bb;
vector<int>a;
vector<int>ans(20);
vector<int>b;

bool used[20];
bool tmp[20];

bool can(int pos, int tent) {
    ans[pos] = a[tent];
    int ok = a.size() - 1;

    for(int i = 0; i < a.size(); i++) tmp[i] = used[i];
    tmp[tent] = 1;

    for(int i = pos+1; i < a.size(); i++) 
        for(int j = a.size()-1; j >= 0; j--)
            if(!tmp[j]) { ans[i] = a[j], tmp[j] = 1; break; }

    string x;
        
    for(int i = 0; i < a.size(); i++) x += to_string(ans[i]);

    return x <= bb;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> aa >> bb;
    for(int i = 0; i < aa.size(); i++) a.pb(aa[i]-'0');
    for(int i = 0; i < bb.size(); i++) b.pb(bb[i]-'0');

    sort(a.begin(), a.end(), greater<int>());

    if(bb.size() > aa.size()) { 
        for(int i = 0; i < a.size(); i++) cout << a[i]; 
        cout << endl; 
        return 0; 
    }

    for(int i = 0; i < aa.size(); i++) {
        for(int j = 0; j < aa.size(); j++) {
            if(used[j]) continue;
            else if(can(i,j)) { ans[i] = a[j], used[j] = 1; break; }
        }
    }

    for(int i = 0; i < a.size(); i++) cout << ans[i];
    cout << endl;

    return 0;
}

