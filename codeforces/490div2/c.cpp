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
const int T = 4e5 + 10;
bool exclui[T];
int times[30];
int rem[30];

int main() {
    ios::sync_with_stdio(false);
    int n,k;
    string s, t;
    cin >> n >> k >> s;
    int cont = 0;

    for(int i = 0; i < n; i++) 
        times[s[i] - 'a']++;

    for(int i = 0; i < 30; i++) {
        while(times[i] and k) {
            times[i]--;
            rem[i]++;
            k--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(rem[s[i] - 'a']) {
            exclui[i] = true;
            rem[s[i] - 'a']--;
        }
    }

    for(int i = 0; i < n; i++)
        if(!exclui[i]) t += s[i];
    cout << t << endl;
    return 0;
}

