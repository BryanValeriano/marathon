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

int n,k;

int main() {
    ios::sync_with_stdio(false);

    cin >> k >> n;

    while(k or n) {
        init();
        string tnc;
        getline(cin,tnc);
        for(int i = 1; i <= n; i++) {
            getline(cin,tnc);
            string s;
            for(int i = 0; i < tnc.size(); i++) {
                if(tnc[i] == ' ') add(i, stoi(s), 1), s = "";
                else s += tnc[i];
            }
            add(i,stoi(s),1);
        }


        cin >> k >> n;
    }

    return 0;
}

