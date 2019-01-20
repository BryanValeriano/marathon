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
string luk;

bool mask(int x) {
    string tmp = to_string(x);
    string k;
    for(int i = 0; i < tmp.size(); i++) 
        if(tmp[i] == '4' or tmp[i] == '7') k += tmp[i];
    return k == luk;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    luk = to_string(b);
    for(int i = a+1; i <= 1e7; i++)
        if(mask(i)) { cout << i << endl; return 0; }
    



    return 0;
}

