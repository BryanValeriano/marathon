#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2000 + 3;
map<int,int> freq;
int v[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int reps = 0;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        freq[v[i]]++;
        if(freq[v[i]] == 2) reps++;
    }

    int r = 0;

    for(int l = 0; l <= n; l++) {
        freq[v[l]]++;
        while(freq[v[l]] == 2)


    }




    return 0;
}

