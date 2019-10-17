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
typedef vector<ii> vii;
typedef tuple<int,int,int,int> ti;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 5e4 + 4;

vector<ti> v;
set<ti> bag;
set<ti> rest;
bool vis[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        v.eb(x,y,z,i);
    }

    sort(v.begin(), v.end());

    for(int i = 1; i < n; i++) {
        if(vis[get<3>(v[i])]) continue;

        if(get<0>(v[i-1]) == get<0>(v[i])) bag.emplace(v[i]), bag.emplace(v[i-1]);
        else {
            while(bag.size() > 1) {
                int a = get<3>(*bag.begin());
                bag.erase(bag.begin());
                int b = get<3>(*bag.begin());
                bag.erase(bag.begin());
                vis[a] = vis[b] = 1;
                cout << a << " " << b << endl;
            }
            while(bag.size()) bag.erase(bag.begin());
        }
    }

    for(int i = 0; i < n; i++)
        if(!vis[get<3>(v[i])]) rest.emplace(v[i]);

    while(rest.size() > 1) {
        int a = get<3>(*rest.begin());
        rest.erase(rest.begin());
        int b = get<3>(*rest.begin());
        rest.erase(rest.begin());
        vis[a] = vis[b] = 1;
        cout << a << " " << b << endl;
    }


    return 0;
}

