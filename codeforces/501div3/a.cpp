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
    int n, m; cin >> n >> m;
    int row[110];
    memset(row, 0, sizeof row);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        while(a <= b) row[a++] = 1;
    }
    vector<int> resp;
    for(int i = 1; i <= m; i++)  
        if(row[i] == 0) resp.pb(i);
    cout << resp.size() << endl;
    for(int x = 0; x < resp.size(); x++) cout << resp[x] << " ";
    cout << endl;

    return 0;
}

