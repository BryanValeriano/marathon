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
    int n; cin >> n;
    vector<int> row; 
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        row.pb(aux);
    }
    int m; cin >> m;
    vector<int>row2;
    for(int i = 0; i < m; i++) {
        cin >> aux;
        row2.pb(aux);
    }
    int go = min(n,m);
    for(int i = 0; i < go; i++) {
        if(row[i] != row2[i]) {
            while(row[i] < row2[i]) {
                if(i + 1 < row.size()) {
                    row[i] += row[i+1];
                    row.erase(row.begin() + i+1);
                    n--;
                    go = min(n, m);
                } else { cout << -1 << endl; return 0; }
            }
            while(row2[i] < row[i]) {
                if(i + 1 < row2.size()) {
                    row2[i] += row2[i+1];
                    row2.erase(row2.begin() + i+1);
                    m--;
                    go = min(n, m);
                } else { cout << -1 << endl; return 0; }
            }
        }
    }
    
//    for(int i = 0; i < n; i++) 
//        cout << row[i] << " ";
//    cout << endl;
//
//    for(int i = 0; i < m; i++) 
//        cout << row2[i] << " ";
//    cout << endl;
//
    if(row.size() != row2.size() || row.size() == 0 || row[n-1] != row[m-1]) {
        cout << -1 << endl; return 0;
    }
    cout << row.size() << endl;
    
    return 0;
}

