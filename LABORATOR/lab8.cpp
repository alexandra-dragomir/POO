#include <iostream>

using namespace std;

class Produs{
protected:
    string nume;
    float pretBrut;
public:
    Produs()
    {
        this -> nume = "none";
        this -> pretBrut = 0;
    }
    void afisare()
    {
        cout << "Acest produs apartine ale.srl";
    }
    virtual float calculeazaPret()
    {
        return pretBrut;
    }

    Produs& operator = (const Produs& p)
    {
        if(this != &p)
        {
            this -> nume = p.nume;
            this -> pretBrut = p.pretBrut;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out,const Produs& p){

    out<<p.nume << " " << p.pretBrut;
    return out;


   }
    friend istream& operator >>(istream& in, Produs&p){

        cout<<"Numele este: ";
        in>>p.nume;
        cout<<"Pretul brut este: ";
        in>>p.pretBrut;
        return in;

    }

};

class ProdusPerisabil:public Produs{

string dataExpirare;

public:
    virtual float calculeazaPret(){
        return pretBrut + (40*pretBrut)/100;
    }

    ProdusPerisabil& operator =(const ProdusPerisabil& pp)
    {
        if(this != &pp)
        {
            Produs::operator = (pp);
            this -> dataExpirare = pp.dataExpirare;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out,const ProdusPerisabil& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.dataExpirare;
      return out;

    }
    friend istream& operator >>(istream& in, ProdusPerisabil&p){

    in>>(Produs&)p;
    cout<<"Dati data: ";
    in>>p.dataExpirare;
    return in;}


};

class ProdusNeperisabil:public Produs{

int garantie;

public:
    virtual float calculeazaPret(){
        return pretBrut + (10*pretBrut)/100;
    }

    ProdusNeperisabil& operator =(const ProdusNeperisabil& pn)
    {
        if(this != &pn)
        {
            Produs::operator = (pn);
            this -> garantie = pn.garantie;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out,const ProdusNeperisabil& p)
    {
        out<<(Produs&)p;
        out<<" "<<p.garantie;
      return out;

    }
    friend istream& operator >>(istream& in, ProdusNeperisabil&p){

    in>>(Produs&)p;
    cout<<"ani garantie: ";
    in>>p.garantie;
    return in;}


};

class ListaProduse:public Produs
{
private:
    int nrProduse;
    Produs* produse;

public:

    ListaProduse& operator = (const ListaProduse &l)
    {
        if(this != &l)
        {
            this -> nrProduse = l.nrProduse;
            if(this -> produse != NULL)
                delete [] this -> produse;
            this -> produse = new Produs[l.nrProduse];
            for(int i = 0; i < l.nrProduse; i++)
            {
                this -> produse[i] = l.produse[i];
            }
        }
    }

    ListaProduse():Produs()
    {
        this -> nrProduse = 0;
        this -> produse = new Produs[0];
    }

    void addPP(const ProdusPerisabil &pp)
    {
        ListaProduse l2;
        l2.nrProduse = this -> nrProduse + 1;
        l2.produse = new Produs[l2.nrProduse];
        for(int i = 0; i < this -> nrProduse; i++)
        {
            l2.produse[i] = this -> produse[i];
        }
        delete [] this -> produse;

        this -> nrProduse = this -> nrProduse + 1;
        this -> produse = new Produs[this -> nrProduse];

        for(int i = 0; i < this -> nrProduse - 1; i++)
        {
            this -> produse[i] = l2.produse[i];
        }

        this -> produse[this -> nrProduse - 1] = pp;

    }

    void addPN(const ProdusNeperisabil &pn)
    {
        ListaProduse l3;
        l3.nrProduse = this -> nrProduse + 1;
        l3.produse = new Produs[l3.nrProduse];
        for(int i = 0; i < this -> nrProduse; i++)
        {
            l3.produse[i] = this -> produse[i];
        }
        delete [] this -> produse;

        this -> nrProduse = this -> nrProduse + 1;
        this -> produse = new Produs[this -> nrProduse];

        for(int i = 0; i < this -> nrProduse - 1; i++)
        {
            this -> produse[i] = l3.produse[i];
        }

        this -> produse[this -> nrProduse - 1] = pn;

    }

    void remove(int index)
    {
        ListaProduse l4;
        l4.nrProduse = this -> nrProduse - 1;
        l4.produse = new Produs[l4.nrProduse];
        int j = 0;
        for(int i = 0; i < this -> nrProduse; i++)
        {
            if(i == index)
                j--;
            else
                l4.produse[j] = this -> produse[i];
            j++;
        }
        delete [] this -> produse;

        this -> nrProduse = this -> nrProduse - 1;
        this -> produse = new Produs[this -> nrProduse];

        for(int i = 0; i < this -> nrProduse; i++)
        {
            this -> produse[i] = l4.produse[i];
        }

    }

   friend ostream& operator<<(ostream& out,const ListaProduse& lp)
    {
        cout << "======= PRODUSELE DIN LISTA ===========\n";
        for(int i = 0; i< lp.nrProduse; i++)
        {
            out << (Produs&)lp.produse[i];
            out << endl;
        }

        return out;

    }

};



int main()
{
    Produs *p[2];
    ListaProduse lista;
    ProdusNeperisabil pn;
    ProdusPerisabil pp1, pp2;
/*
    p[0] = new ProdusPerisabil();
    p[0] = &pp;

    p[1] = new ProdusNeperisabil();
    p[1] = &pn;
*/
    cin >> pp1;
    cin >> pp2;
    cin >> pn;
   // cout << p[0] -> calculeazaPret() << " " << p[1] -> calculeazaPret() << endl;

    lista.addPP(pp1);
    lista.addPP(pp2);
    lista.addPN(pn);
    cout << lista;
    lista.remove(2);
    cout << "lista actualizata: \n";
    cout << lista;

    return 0;
}
