#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

typedef struct cr
{
    int a;
    int b;
}
cr;



int isright(cr cords[3], int position, int val, int casa)
{
    int dist[3];
    int maxdist;

   
    if(casa == 1) cords[position].a += val;
    else if(casa == 2) cords[position].b += val;

    if(cords[0].a == cords[1].a && cords[0].b == cords[1].b)
    {
        cords[position].a -= val;
        return 0;
    }

    else if(cords[0].a == cords[2].a && cords[0].b == cords[2].b)
    {
        cords[position].a -= val;
        return 0;
    }   
    else if(cords[1].a == cords[2].a && cords[1].b == cords[2].b) 
    {
        cords[position].a -= val;
        return 0;
    }   
  
    
    dist[0] = pow((cords[0].a - cords[1].a), 2) + pow((cords[0].b - cords[1].b), 2);
    dist[1] = pow((cords[0].a - cords[2].a), 2) + pow((cords[0].b - cords[2].b), 2);
    dist[2] = pow((cords[1].a - cords[2].a), 2) + pow((cords[1].b - cords[2].b), 2);

    maxdist = *max_element(dist, dist+3);

    if(maxdist == dist[0] + dist[1] + dist[2] - maxdist) return 1;
    else if(casa == 1)
    {
        cords[position].a -= val;
        return 0;
    }
    else if(casa == 2)
    {
        cords[position].b -= val;
        return 0;
    }
    else return 0;
}

void almost(cr cords[3])
{
    for(int i = 0; i < 3; i++)
    {
        if(isright(cords, i, 1, 1) || isright(cords, i, -1, 1))
        {
            cout << "ALMOST" << endl;
            return;
        }
        else if(isright(cords, i, 1, 2) || isright(cords, i, -1, 2))
        {
            cout << "ALMOST" << endl;
            return;
        }
    }

    cout << "NEITHER" << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);

    cr cords[3];

    for(int i = 0; i < 3; i++)
    {
        cin >> cords[i].a;
        cin >> cords[i].b;
    }
    
    if(isright(cords, 1, 1, 0)) cout << "RIGHT" << endl;
    else almost(cords);

    return 0;
}

