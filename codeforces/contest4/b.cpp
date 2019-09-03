#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define  MAX 10000

typedef long long ll;

ll hash_func(string str);

int main(){
    ios_base::sync_with_stdio(false);

    ll n, k, m;

    ll min = pow(10, 9);

    cin >> n >> k >> m;
    
    ll aux = 0;
    pair<string, int> palavras[MAX];
    ll custos[n];
    string tmp;

    for(ll i = 0; i < n; i++)
    {
	cin >> tmp;

	palavras[i] = mk(tmp, min);
    }
    for(ll i = 0; i < n; i++)
    {
	cin >> custos[i];
	palavras[i].second = custos[i];
    }

    for(ll i = 0; i < k; i++)
    {
	cin >> aux;
	ll grupo[aux];
	for(ll j = 0; j < aux; j++)
	{
	    cin >> grupo[j];
	}
	for(ll j = 0; j < aux; j++)
	{
	    if(palavras[grupo[j] - 1].second < min) min = palavras[grupo[j] - 1].second ;
	}
	for(ll j = 0; j < aux; j++)
	{
	    palavras[grupo[j] - 1].second = min;
	}
	min = pow(10, 9);
    }
  

    ll index;
    vector< pair<string, int> > dict[MAX];
    pair<string, int> anubis;
    for(ll i = 0; i < n; i++)
    {
        index = hash_func(palavras[i].first);
        anubis.first = palavras[i].first;
        anubis.second = palavras[i].second;
        dict[index].pb(anubis);
    }
    /*   
    for(ll i = 0; i < n; i++)
    {
	cout << palavras[i].first << "-  " << palavras[i].second << endl;
    }
    */

    ll cont = 0;
    ll T = 0;

    for(ll i = 0; i < m; i++)
    {
	cin >> tmp;
        index = hash_func(tmp);
        
        while(tmp != dict[index][T].first) T++; 
        cont += dict[index][T].second;
	T = 0;
    }

    cout << cont << endl;


    return 0;
}

ll hash_func(string str)
{
    ll hash = 5381;
    ll tamanho = str.size();

    for(ll i = 0; i < tamanho; i++)
        hash += str[i]*7;

    return hash % MAX;
}
