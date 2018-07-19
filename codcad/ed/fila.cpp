#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(false);

    int M;
    int aux;
    cin >> M;

    vector<int> V;

    for(int i = 0; i < M; i++)
    {
        V.pb(aux);
    }

    int N;

    for(int i = 0; i < N; i++)
    {
        cin >> aux;
        for(int j = 0; j < M; j++)
        {
            if(V[j] == aux) 
            {
                V.erase (V.begin()+j);
                break;
            }
        }
    }    

    for(int i = 0; i < (int)V.size(); i++)
    {
        cout << V[i] << " ";
    }

    cout << endl;
    return 0;
}

