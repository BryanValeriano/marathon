#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);

    int N, i, sum=0, min=0, aux;

    cin>>N;

    for(i=0; i<N; i++){
        cin>>aux;
        sum+=aux;
        min = (min<sum?min:sum);
    }

    cout<<abs(min)<<"\n";

    return 0;
}

