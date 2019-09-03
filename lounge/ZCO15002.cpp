#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int n, k;
int sequencia[65005];
ll cont = 0;
map<int,int> memo;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    cin >> sequencia[0];
    for(int i = 1 ; i < n; i++)
    {
        cin >> sequencia[i];
    }
    
    sort(sequencia, sequencia + n);
    
    for(int i = 0, j = i + 1; i < n - 1;)
        if(abs(sequencia[i] - sequencia[i-1]) >= k)
        {
            cont += n - j;
            i++;
        }else{j++;}

    cout << cont << endl;
    
    return 0;
}

