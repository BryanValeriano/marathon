#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e6+3;
double battery;
double consumo;
double vida;
vector< pair<double, double> >devices;

//descobre se aguenta carregar esse tempo
bool magic(double tempo, int max, double bateria) {
    bateria = bateria*tempo;
    for(int i = 0; i < max; i++) {
        if((devices[i].fi * tempo) - devices[i].sec  <= bateria) 
        {
            if((devices[i].fi * tempo) - devices[i].sec > 0)
                bateria -= (devices[i].fi * tempo) - devices[i].sec;
        }
        else return false;
    }
    return true;
}

int main() {
    int max; cin >> max;
    devices.reserve(max);
    scanf("%lf", &battery);
    double consumototal = 0;
    
    //soh preciso do total deles
    for(int i = 0; i < max; i++)
    {
        scanf("%lf %lf", &consumo, &vida);
        devices.pb(mk(consumo,vida));
        consumototal += consumo; 
    }

    //teste INF
    if(battery >= consumototal) {
        cout << -1 << endl;
        return 0;
    }


    //busca bin upper bound intervalo continuo
    //precisao 2^200 eh o suficiente
    int repeticoes = 201;
    double ini = 0;
    //pior caso, chuta no inico dps prova
    double fim = 1e15;

    while(repeticoes--) {
        double meio = (ini + fim)/2;
        if(magic(meio,max, battery))
            ini = meio;
        else fim = meio;
    }

    printf("%.7lf\n", fim);
        
    return 0;
}


