#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int n, m;
    cin >> n >> m;
    int seq[m];
    for(int i = 0; i < m; i++)
        cin >> seq[i];
    sort(seq, seq+m);
    int mindif = seq[m - 1] - seq[0];
    int dif;
    for(int i = 0; i <= m - n; i++)
    {
        dif = seq[i + n-1] - seq[i];
        //cout << "dif: " << dif << " maior: " << seq[i+n -1] << " menor: " << seq[i] << endl;
        mindif = min(dif, mindif);
    }
    cout << mindif << endl;
    
    
    return 0;
}

