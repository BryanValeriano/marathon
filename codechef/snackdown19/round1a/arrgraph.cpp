#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 55;
int row[T];
int test[T];
 
int main() {
    int tc; cin >> tc;
    int ver = 0;
    while(tc--) {
        int n; cin >> n;
        ver++;
        int swp = 0;
        for(int i = 0; i < n; i++) 
            cin >> row[i];
        for(int i = 0; i < n; i++)  
            for(int j = i + 1; j < n; j++)  
                if(__gcd(row[i], row[j]) == 1) { test[i] = test[j] = ver;  } 
        bool bomb = true;
        for(int i = 0; i < n; i++)  
            if(test[i] != ver) bomb = false;
        if(bomb or n == 1){
            cout << 0 << endl;
            for(int i = 0; i < n; i++)  
                cout << row[i] << " ";
            cout << endl;
        } else {
            cout << 1 << endl;
            bool flag = true;
            for(int i = 0; i < n; i++) { 
                if(i + 1 < n and row[i+1] != 47 and flag == true) {
                    cout << 47 << " ";
                    flag = false;
                } 
                else if(i + 1 < n and row[i+1] != 43 and flag == true) {
                    cout << 43 << " ";
                    flag = false;
                } else cout << row[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

