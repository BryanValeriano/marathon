#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5;
const int N = 1e5;

int main() {
    ios_base::sync_with_stdio(false);
    cout << N << " " << T << endl;

    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,N);
    uniform_int_distribution<int> distribution2(0,25);

    //for(int i = 1; i < N; i++) {
    //    int x = distribution2(generator);
    //    char ok = x+'a';
    //    cout << i << " " << i+1 << " " << ok << endl;
    //}

    int i,j;

    for(int k = 0; k < T; k++) {
        i = distribution(generator);
        j = distribution(generator);

        while(i == j) {
            i = distribution(generator);
            j = distribution(generator);
        }

        int x = distribution2(generator);
        char ok = x+'a';

        cout << i << " " << j << " " << ok << endl;
    }



    return 0;
}

