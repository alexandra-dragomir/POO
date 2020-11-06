#include <iostream>
#include <string.h>

using namespace std;

class Decoratiune
{
private:
    char *nume;
    char *culoare;
    float pret;
    bool reciclabila;
public:
    Decoratiune()
    {
        this -> nume = new char[0];
        this -> culoare = new char[0];
        this -> pret = 0;
        this -> reciclabila = 0;
    }
    Decoratiune(char *nume, char *culoare, float pret, bool reciclabila)
    {
        this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        this -> culoare = new char[strlen(culoare) + 1];
            strcpy(this -> culoare, culoare);
        this -> pret = pret;
        this -> reciclabila = reciclabila;
    }

    Decoratiune& operator = (const Decoratiune& d)
    {
        if(this -> nume != NULL)
            delete [] this -> nume;
        this -> nume = new char[strlen(d.nume) + 1];
        strcpy(this -> nume, d.nume);

        if(this -> culoare != NULL)
            delete [] this -> culoare;
        this -> culoare = new char[strlen(d.culoare) + 1];
        strcpy(this -> culoare, d.culoare);

        this -> pret = d.pret;
        this -> reciclabila = d.reciclabila;
    }

    void setNume(char *a)
    {
        if(this -> nume != NULL)
            delete [] this -> nume;
        this -> nume = new char[strlen(a) + 1];
        strcpy(this -> nume, a);
    }

    void setPret(float x){ this -> pret = x; }

    void setReciclabil(bool r) { this -> reciclabila = r; }

    void setCuloare(char *c)
    {
        if(this -> culoare != NULL)
            delete [] this -> culoare;
        this -> culoare = new char[strlen(c) + 1];
        strcpy(this -> culoare, c);
    }

    char* getCuloare() { return this -> culoare; }

    float getPret(){ return this -> pret; }

    char* getNume(){ return this -> nume;}

    bool getReciclabil(){ return this->reciclabila; }

    void afisare()
    {
        cout << "Decoratiunea " << this -> nume << " are culoarea " << this -> culoare << " pretul " << this -> pret << " reciclabil: " << this -> reciclabila << endl;

    }

    friend ostream& operator << (ostream& out, Decoratiune& d)
    {
        out << "Decoratiunea " << d.nume << " are culoarea " << d.culoare << " pretul " << d.pret << " reciclabil: " << d.reciclabila << endl;
        return out;
    }

    ~Decoratiune()
    {
        if(this -> nume != NULL)
            delete [] this -> nume;
        if(this -> culoare != NULL)
            delete [] this -> culoare;
    }


};

class Lista
{
private:
    int nrProduse;
    Decoratiune *produse;
    float pretTotal;

public:
    Lista()
    {
        this -> produse = new Decoratiune[0];
        this -> pretTotal = 0;
    }
    Lista(int nrProduse, Decoratiune *produse)
    {
        this -> nrProduse = nrProduse;
        this -> produse = new Decoratiune[nrProduse + 1];
        for(int i = 0; i < nrProduse; i++)
        {
            this -> produse[i] = produse[i];
        }

    }

    Lista& operator = (const Lista &l)
    {
        if(this != &l)
        {
            this -> nrProduse = l.nrProduse;
            if(this -> produse != NULL)
                delete [] this -> produse;
            this -> produse = new Decoratiune[l.nrProduse];
            for(int i = 0; i < nrProduse; i++)
            {
                this -> produse[i] = l.produse[i];
            }
             this -> pretTotal = getPretTotal();
        }
    }

    float getPretTotal()
    {
        float total = 0;
        for(int i = 0; i < this -> nrProduse; i++)
        {
            total = total + (this -> produse[i]).getPret();
        }
    }

    Lista operator + (Decoratiune& d)
    {
        Lista l2;
        l2.nrProduse = this -> nrProduse + 1;
        if(l2.produse != NULL)
            delete [] l2.produse;
        l2.produse = new Decoratiune[l2.nrProduse + 1];
        for(int i = 0; i < l2.nrProduse - 1; i++)
        {
            l2.produse[i] = this -> produse[i];
        }
        l2.produse[l2.nrProduse-1] = d;

        return l2;

    }

    Decoratiune operator [] (int i)
    {
        return this -> produse[i];
    }

    void afisare()
    {
        cout << "In lista se afla urmatoarele produse: " << endl;
        for(int i = 0; i < this -> nrProduse; i++)
            cout << "Decoratiunea " << this -> produse[i].getNume() << " are culoarea " << this -> produse[i].getCuloare() << " pretul " << this -> produse[i].getPret() << " reciclabil: " << this -> produse[i].getReciclabil() << endl;

    }

    void remove(int index)
    {
        Lista aux = *this;
        this -> nrProduse = this -> nrProduse - 1;
        delete [] this -> produse;
        this -> produse = new Decoratiune[this -> nrProduse + 1];
        for(int i = 0; i < this -> nrProduse + 1; i++)
            if(i != index)
                this -> produse[i] = aux.produse[i];

    }

    friend ostream& operator << (ostream& out, Lista &l)
    {
        out << "In lista se afla urmatoarele produse: " << endl;
        for(int i = 0; i < l.nrProduse; i++)
            out << "Decoratiunea " << l.produse[i].getNume() << " are culoarea " << l.produse[i].getCuloare() << " pretul " << l.produse[i].getPret() << " reciclabil: " << l.produse[i].getReciclabil() << endl;

    }

    ~Lista()
    {
        if(this -> produse != NULL)
        {
            for(int i = 0; i < this -> nrProduse; i++)
                if((this -> produse[i]).getNume() != NULL)
                    delete [] (this -> produse[i]).getNume();
        }
    }
};




int main()
{
    char n1[] = "stea";
    char n2[] = "glob";
    char c1[] = "galben";
    char c2[] = "albastru";
    Decoratiune d1(n1, c1, 100, 1);
    Decoratiune d2(n2, c2, 10, 1);
  //  d1.afisare();

    Decoratiune dec1[] = {d1, d2};
    Decoratiune dec2[] = {d1};

    Lista l1(1, dec2);
    l1 = l1 + d2;
    l1[1].afisare();
   // cout << l1[1] << endl;
    cout << l1.getPretTotal() << endl;
    l1.remove(1);
    l1.afisare();
    return 0;
}
