#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int n, cont = 0;
    cin >> n;
    string pal[n];
    string resp[n];
    for(int i = 0; i < n; i ++)
        cin >> pal[i];
    
    for(int i = 0; i < n; i ++)
    {
        string index = pal[i];
        //cout << "index: " << index << endl;
        for(int j = 0; j < n; j++)
        {
            size_t found = pal[j].find(index);
            if(found!=string::npos) cont++;
        }
        if(resp[n - cont] == pal[i])
        {
            int aux = 0;
            while(resp[n + aux - cont] == pal[i])
            {
                aux++;
            }
            resp[n + aux - cont] = pal[i];
        }
        else resp[n - cont] = pal[i];
        cont = 0;
    }

    //for(int i = 0; i < n; i ++)
        //cout << resp[i] << endl;

    int sinal = 0;
    for(int i = 1; i < n; i++)
    {
        size_t found = resp[i].find(resp[i-1]);
        if(found == string::npos)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
        if(resp[i] == "")
            sinal = 1;
        
    if(sinal == 0)
    {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cout << resp[i] << endl; 
    }
    else cout << "NO" << endl;
    return 0;
}

