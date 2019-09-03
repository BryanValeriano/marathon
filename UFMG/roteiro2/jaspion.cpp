#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int N, palavras, linhas;
    cin >> N;
    string japa, port;
    map<string, string>dict;
    map<string, string>:: iterator it;
    string trad;
    string tmp;

    for(int i = 0; i < N; i++)
    {
        cin >> palavras >> linhas;
        getline(cin, tmp);
        for(int j = 0; j < palavras; j++)
        {
            getline(cin, japa);
            getline(cin, port);
            dict.insert(mk(japa, port));
        }
        cout << endl;

        for(int j = 0; j < linhas; j++)
        {
            while(cin >> trad)
            {
                it = dict.find(trad);
                if(it != dict.end()) cout << dict[trad] << " ";
                else cout << trad;
            }
            cout << endl;
        }
    }
            
    return 0;
}

