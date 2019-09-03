#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int t = 1e5 + 3;
int row[t];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int left = 0;
    int right = 0;
    cin >> row[0];
    int mini = row[0];
    int maxi = row[0];
    int best = 1;
    int indice = 0;
    for(int i = 1; i < n; i++) {
        right = i;
        cin >> row[i]; 
        maxi = max(maxi, row[i]);
        mini = min(mini, row[i]);
        if(maxi - mini > 1) {
            left = indice;
            mini = min(row[indice], row[i]);
            maxi = max(row[indice], row[i]);
            
        }
        if(row[i-1] != row[i]) indice = i;
        best = max(best, right - left + 1);
    }
    cout << best << endl;

    return 0;
}

