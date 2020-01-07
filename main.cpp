#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <typeinfo>

#include "Casa.h"
#include "Apartament.h"
#include "Gestiune.h"


using namespace std;

int main() {

    set<pair<Locuinta*, TipLocuinta>> Locuinte;
    ifstream fin("data.in");

    int n;
    fin>>n;

    for (int i=0;i<n;i++)
    {
        try {
            TipLocuinta tip;
            fin >> tip;
            Locuinta* pLocuinta;
            if (tip == TipLocuinta::APARTAMENT) {
                Apartament *ap = new Apartament;
                fin>>*ap;
                pLocuinta = ap;
            } else {
                Casa *ca = new Casa;
                fin>>*ca;
                pLocuinta = ca;
            }
            Locuinte.insert({pLocuinta, tip});

        }
        catch (const char* eroare){
            cout<<eroare;
        }
        catch (...)
        {
            cout<<"Eroare!\n";
        }
    }

    Gestiune<Locuinta> gestiuneLocuinte;

    for (set<pair<Locuinta*, TipLocuinta>>::iterator it=Locuinte.begin(); it != Locuinte.end(); ++it) {
        it->first->Afisare(cout);

        gestiuneLocuinte += it->first;
    }

    cout<<gestiuneLocuinte;

    Gestiune<Casa> gestiuneCase(gestiuneLocuinte);

    cout<<gestiuneCase<<"\n";

    Casa c = gestiuneCase[0];

    cout<<c<<"\n";

    cout<<Locuinta::CalculeazaChirie(100, 0.1, 50);

    return 0;
}
