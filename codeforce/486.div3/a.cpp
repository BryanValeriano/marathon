#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    map<int, int> resp;
    int aux;
    int cont = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> aux;
        if(resp.count(aux) == 0) resp.insert(mk(aux, i));
    }
    if(resp.size() >= k)
    {
        cout << "YES" << endl;
        int tmp = 0;
        for(map<int,int>::iterator it = resp.begin(); it != resp.end() && tmp < k; ++it)
        {
            cout << it->second << " ";
            tmp++;
        }
        cout << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}

