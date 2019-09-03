#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;

int inhand(char last, char atual) {
    if(abs(atual-last) <= 2) return 4;
    return 2;
}
 
int main()
{
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        double sum = 0;
        map<string,double>ind;
        while(n--) {
            string s; cin >> s;
            if(ind.count(s)) {
                sum += ind[s] / 2;
                ind[s] /= 2;
            } else {
                double tmp = 2;
                for(int i = 1; i < s.size(); i++) 
                    tmp += inhand(s[i-1], s[i]);
                sum += tmp; 
                ind[s] = tmp;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

