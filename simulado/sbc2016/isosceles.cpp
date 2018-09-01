#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
bool cmp(pair<int,int>&a, pair<int,int>&b) {
    return a.sec > b.sec;
}
int main()
{
    int n; cin >> n;
    int row[n+1];
    pair<int,int> index[n+1];
    int aux;
    for(int i = 1; i <= n; i++) { 
        cin >> aux;
        index[i] = mk(i,aux);
        row[i] = aux;
    }
    sort(index + 1, index + n+1, cmp);

    bool flag = true;
    for(int i = 1; i <= n; i++) {
        int base;
        if(index[i].sec&1) int base = (index[i].sec << 1)+1;
        else int base = (index[i].sec << 1);
        if(index[i].fi > base && index[i].fi + base <= n) {
            flag = true;
            for(int j = index[i].fi - (base - 1); j < base; j++) {
                if(row[index[i].fi - j] < index[i].sec - j &&
                    row[index[i].fi + j] < index[i].sec - j) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) cout << index[i].sec << endl;
        }
    }
                    
    return 0;
}

