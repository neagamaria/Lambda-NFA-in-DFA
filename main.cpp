#include <iostream>
#include <fstream>
#include <string.h>
#define NMAX 10000

///automat DFA

using namespace std;

///fisiere in si out
ifstream in("input.in");
ofstream out("output.out");

int n, m; //nr de noduri, nr de muchii
int x, y, fin, start, viz[NMAX], stop[NMAX];
int nr; //nr de cuvinte de testat
char cuvant[NMAX], c, lg; //c= "costul" unei muchii, lg = lungime cuvant
char a[NMAX][NMAX]; //matricea muchiilor

///functie parcurgere
void DFS(int start, int l)
{
    if(l<=lg)
    {
        viz[l]=start;
        for(int i=0; i<n; i++)
        {
            if(a[start][i]==cuvant[l])
            {
                DFS(i, l+1);
            }
        }
    }
}

///calcul lungime drum
int lungime(int viz[])
{
    for(int i=0; i<NMAX; i++)
        if(viz[i]==-1)
        return i-1;
    return NMAX;
}

int acceptat()
{
    if(lungime(viz)!=lg)
        return 0;
    for(int i=0; i<fin; i++)
        if(viz[lg]==stop[i])
            return 1;
    return 0;

}

int main()
{
    in>>n>>m;

    for(int i=1; i<=m; i++)
    {
        in>>x>>y; //muchia
        in>>c; //"costul" muchiei
        a[x][y]=c;
    }

    in>>start; //starea initiala
    in>>fin; //nr stari finale
    for(int i=0; i<fin; i++)
        in>>stop[i]; //stari finale


    in>>nr;
    in.get();
    for(int i=0; i<nr; i++)
    {
        for(int j=0; j<NMAX; j++)
            viz[j]=-1; //marchez ca nevizitate toate pozitiile
        start=0;
        in.getline(cuvant, NMAX);
        lg=strlen(cuvant);
        DFS(start, 0);
        if(acceptat()==1)
        {
            out<<"DA"<<endl<<"Traseu: ";
            for(int i=0; i<=lg; i++)
            {
                out<<viz[i]<<" ";
            }
            out<<endl;
        }
        else
            out<<"NU"<<endl;
    }

    return 0;
}
