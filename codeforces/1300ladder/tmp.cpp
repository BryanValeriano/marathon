#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    int n, k; cin >> n >> k;
    list<int>row;

    for(int i = 1; i <= n; i++) 
        row.pb(i);
    int fim = n-1;
    for(int i = 0; i < k; i++) { 
        auto tmp = row.crbegin();
        auto tmp2 = row.begin();
        for(int j = 0; j < i; j++)
            tmp2++;
        row.insert(tmp2, *tmp);
        row.pop_back();
    }

    for(auto id : row) 
        printf("%d ", id); 
    cout << endl;

    return 0;
}
