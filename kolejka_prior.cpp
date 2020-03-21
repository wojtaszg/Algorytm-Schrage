#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class zad
{
 public:

    int r;
    int p;
    int q;

    zad()
    {
        r = 0;
        p = 0;
        q = 0;
    }

    zad(int a, int b, int c)
    {
        r = a;
        p = b;
        q = c;
    }

   bool operator <(const zad & z) const
	{
		return r > z.r;
	}

};

struct rosnacoPoR
{
    bool operator ()( const zad & z1, const zad & z2 )
    {
        if( z1.r > z2.r ) 
            return true;  
        else
            return false;
        
    }
};

struct malejacoPoQ
{
    bool operator ()( const zad & z1, const zad & z2 )
    {
        if( z1.q < z2.q ) 
            return true;
        else
            return false;
          
    }
};


int *obliczenia(vector <zad> tablica, int iloscZadan)
{
    int *S = new int[iloscZadan];

    for (int i=0; i < iloscZadan; ++i)
    {
        if (i == 0)
            S[i] = tablica[i].r;
        else
            S[i] = max(tablica[i].r, S[i - 1] + tablica[i - 1].p);   
    }

    int *C = new int[iloscZadan];

    for (int i = 0; i < iloscZadan; ++i)
    {
        C[i] = S[i] + tablica[i].p;
    }

    int *Cmax = new int[iloscZadan];

    for (int i = 0; i < iloscZadan; ++i)
    {
        Cmax[i] = C[i] + tablica[i].q;
        cout << Cmax[i] << '\t';
    }
    delete [] S;
    delete [] C;

    return Cmax;
}

// PERMUTACJA NATURALNA
void permutacja(int *Cmax, int iloscZadan)
{
    int max = -1, tmp, wynik;
    for (int i = 0; i < iloscZadan; ++i)
    {
        tmp = Cmax[i];
        if (tmp > max)
        {
            wynik = (i + 1);
            max = tmp;
        }
    }
    cout << endl << "----------------------------------------------------------------------" ;
    cout << endl << "Element nr " << wynik <<" jest wartoscia Cmax" << endl;
    cout << "Optymalny czas zakonczenia i dostarczenia wszystkich zadan to "<<Cmax[wynik - 1] << endl;
}


int main()
{
    string linia;
    fstream plik;
    string a;
    int iloscZadan;
    int kolumny;
    cout << "Podaj nazwe pliku: ";
    cin >> a;
    cout << endl;
    plik.open(a, ios::in);
    if (plik.good() == true)
    {
        plik >> iloscZadan;
        plik >> kolumny;

        vector <zad> P;
        priority_queue <zad, vector<zad>, rosnacoPoR> N;
        priority_queue <zad, vector <zad>, malejacoPoQ > G;

        int t;

        while (!plik.eof())
        {
            int x, y, z;
            for (int i = 0; i < iloscZadan; i++)
            {
                    plik >> x; plik >> y; plik >> z;
                    N.push(zad(x,y,z));
            }
        }
        plik.close();
       
        t = N.top().r;
        int k = 0;
        int rozmiarN = N.size(), rozmiarG = G.size();  
        int rj = rozmiarN - 1;
        int j = iloscZadan;
    
       while (N.empty() != 1|| G.empty() != 1)
        {  
            while(N.empty() != 1 && N.top().r <= t )
            {
                G.push(N.top());
                N.pop();  
            }  

            if(G.empty() != 1)
            {
                P.push_back(G.top());
                t += G.top().p;
                G.pop();
            }
            else
            {
                t = N.top().r;
            }
        }
        permutacja(obliczenia(P, iloscZadan), iloscZadan);
    }
    return 0;
}