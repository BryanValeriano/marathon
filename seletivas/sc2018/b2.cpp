#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int n;
string row;

 
int main()
{
    cin >> n;
    cin >> row;
    for(int i = 1; i < n; i++) {
        string tmp = row.substr(i, n-1);
        tmp += row.substr(0, i);
        if(tmp < row) { cout << "No" << endl; return 0; }
    }
        
    cout << "Yes" << endl;
    return 0;
}

