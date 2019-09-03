/*
ID: bryan_31
TASK: gift1 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct pessoa
{
    char nome[16];
    int din;
}
pessoa;


int compara(pessoa grupo, char *nome);

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
 
    //numero de pessoas no grupo
    int PG;

    fin >> PG;    

    //nome que vai doar
    char giver[16];

    //dinheiro recebido inicialmente
    int bank;

    //qtd que vai receber
    int qtd;

    //nome que vai receber
    char rcver[16];

    //vetor struct de pessoas do grupo
    pessoa grupo[PG];

    //tmps para achar nome doador e rcbdor
    int j = 0;
    int k = 0;

    //resto para divisao nao igual
    int rest = 0;

    for(int i = 0; i < PG; i++)
    {
        fin >> grupo[i].nome;
        grupo[i].din = 0;
    }
    
    for(int i = 0; i < PG; i++)
    {
        fin >> giver;
        fin >> bank;
        fin >> qtd;
       
        if(qtd == 0) rest = 0;
        else if(bank % qtd == 0) rest = 0;
        else rest = (bank % qtd);
        
        while(compara(grupo[j], giver) == 0) j++;

        grupo[j].din += rest;
        grupo[j].din -= bank;
    
        for(int p = 0; p < qtd; p++)
        {
            fin >> rcver;        
            while(compara(grupo[k], rcver) == 0) k++;
            grupo[k].din += (bank / qtd);
            k = 0;
        }

        j = 0;
        k = 0;
    }        

    
    for(int i = 0; i < PG; i++)
    {
        fout << grupo[i].nome << " ";
        fout << grupo[i].din << endl;
    }

    return 0;
}

int compara(pessoa ptr, char *nome)
{
    int valid = 0;
    int cont = 0;
    int i = 0;

    for(i = 0; ptr.nome[i] != '\0' && nome[i] != '\0'; i++)
    {
        if(ptr.nome[i] == nome[i])
        {
            valid++;
        }
        cont++;
    }

    if(cont == valid && ptr.nome[i] == '\0' && nome[i] == '\0') return 1;
    else return 0;
}

