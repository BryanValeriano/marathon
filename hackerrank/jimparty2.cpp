#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int N, M, Q;

vector< set<int> > coloca(int tmp1, int tmp2, vector< set<int> > tmp)
{
    int sinal = 0;

    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i].count(tmp1) == 1)
        {
            tmp[i].insert(tmp2);
            sinal = 1;
            return tmp;
        }
        else if(tmp[i].count(tmp2) == 1) 
        {
            tmp[i].insert(tmp1);
            sinal = 1;
            return tmp;
        }
        else if(i + 1 >= tmp.size() && sinal == 0)
        {
            set<int> aux;
            tmp.pb(aux);
            tmp[i + 1].insert(tmp1);
            tmp[i + 1].insert(tmp2); 
            return tmp;
        }
    }
    set<int> aux;
    tmp.pb(aux);
    tmp[0].insert(tmp1);
    tmp[0].insert(tmp2); 
    return tmp;
}

bool compara(set<int> jogos, set<int>tmp)
{
    if(jogos.size() == 0) return false;
    int cont = 0;

    for(set<int>::iterator i = jogos.begin(); i != jogos.end(); i++)
        for(set<int>::iterator j = tmp.begin(); j != tmp.end(); j++)
            if(*i == *j) cont++;

    if(cont == jogos.size()) return true;
    else return false;
}

bool check(set<int> jogos[], vector< set<int> >tmp, int output[], int aux)
{
    for(int i = 0; i < M; i++)
        for(int j = 0; j < tmp.size(); j++)
            if(compara(jogos[i], tmp[j]))
            {
                jogos[i].clear();
                output[i] = aux;
                return true;
            }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    //ofstream fout(getenv("OUTPUT_PATH"));
    ll tmp1, tmp2;

    cin >> N >> M >> Q;
    set<int> jogos[M];
    int output[M];
    memset(output, -1, sizeof output);
    vector< set<int> >tmp;
    
    for(int i = 0; i < N; i++)
    {
        cin >> tmp1;
        jogos[tmp1 - 1].insert(i + 1);
    }
	for(int i = 0; i < M; i++)
    {
        if(jogos[i].size() == 1)
		{
			output[i] = 0;
			jogos[i].clear();
    }
    
    for(int i = 0; i < Q; i++)
    {
        cin >> tmp1 >> tmp2;
        tmp = coloca(tmp1, tmp2, tmp);
        check(jogos, tmp, output, i+1);        
    }

	for(int i = 0; i < M; i++)
    {
        if(jogos[i].size() == 1) output[i] = 0;
    }
    
	for(int i = 0; i < M; i++) cout << output[i] << endl;
	//fout.close();
		
    return 0;
}

