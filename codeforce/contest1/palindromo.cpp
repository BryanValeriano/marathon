 #include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char txt[n];
    cin >> txt;

    int tamanho;
    char *pali = new char[1] ;

    pali[0] = ' ';
    tamanho = 0;
    int y = 0;
    int c = 0;
    int cont = 0;    
    int f = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(txt[i] == txt[j])
            {
                for(int k = i, l = j; k <= j && l >= i; k++, l--)
                {
                    if(txt[k] == txt[l])
                    {
                        cont++;
                    }
                }
                if(cont == (j+1) - i)
                {
                    if(cont > tamanho)
                    {
                        tamanho = (cont);
                        free(pali);
                        pali = new char[cont];
                        for(int c = i; c <= j; c++)
                        {
                            pali[f] = txt[c];       
                            f++;
                        }
                    } 
                }
                cont = 0;
                f = 0;
            }
        }
    }
    
    cout << tamanho << endl;
    cout << pali; 
        
    free(pali);
    return 0;   
}
