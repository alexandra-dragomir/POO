#include <iostream>
#include <string.h>

using namespace std;

class Persoana{
private:
    string nume;
    char* prenume;
    int varsta;
public:
    Persoana()
    {
        this -> nume = "Anonim";
        this -> varsta = 0;
        this -> prenume = new char[strlen("Anonim") + 1];
        strcpy(this -> prenume, "Anonim");
    }

    Persoana(string nume, char* prenume, int varsta)
    {
        this -> nume = nume;
        this -> varsta = varsta;
        this -> prenume = new char[strlen(prenume) + 1];
        strcpy(this -> prenume, prenume);
    }

    Persoana(const Persoana& s)
    {
        this -> nume = s.nume;
        this -> varsta = s.varsta;
        this -> prenume = new char[strlen(s.prenume) + 1];
        strcpy(this -> prenume, s.prenume);
    }

    Persoana& operator =(const Persoana& p)
    {
        if(this != &p)
        {
            this -> nume = p.nume;
            this -> varsta = p.varsta;
            if(this -> prenume != NULL)
                delete [] this -> prenume;
            this -> prenume = new char[strlen(p.prenume) + 1];
            strcpy(this -> prenume, p.prenume);
        }
        return *this;
    }


    void afisare()
    {
        cout<<this->nume<<" "<<this->prenume<<" "<<this->varsta;

    }

    void calculeaza(int a, int b)
    {
        cout << a+b;
    }

    friend ostream& operator<<(ostream& out, const Persoana& p)
   {
          out<<p.nume<<" "<<p.prenume<<" "<<p.varsta;
          return out;

   }

   friend istream& operator>>(istream& in, Persoana& p)
   {

       cout<<"Numele este: ";
       in>>p.nume;
       cout<<"Prenumele este: ";
       char buffer[100];
       in>>buffer;

       if(p.prenume!=NULL)
        delete[] p.prenume;
       p.prenume=new char[strlen(buffer)+1];
       strcpy(p.prenume, buffer);

       cout<<"Varsta este ";
       in>>p.varsta;

       return in;
   }

    ~Persoana()
    {
        if(this -> prenume != NULL)
            delete [] this -> prenume;
    }


};
class Student:public Persoana{
private:
    string facultate;
public:
    Student():Persoana()
    {
        this -> facultate = "Anonim";
    }

    Student(string nume, char *prenume, int varsta, string facultate):Persoana(nume, prenume, varsta)
    {
        this -> facultate = facultate;
    }

    Student(Persoana p, string facultate):Persoana(p)
    {
        this -> facultate = facultate;
    }

    Student& operator =(const Student& s)
    {
        if(this != &s)
        {
            Persoana::operator = (s);
            this -> facultate = s.facultate;
        }
        return *this;
    }
    void calculeaza(int a, int b)
    {
        cout << a-b;
    }
    void calculeaza(string a)
    {
        cout << a;
    }

    friend ostream & operator << (ostream& out, const Student& s)
    {
        out << (Persoana&)s;
        out << " " << s.facultate;
        return out;
    }
    friend istream & operator >> (istream& in, Student& s)
    {
        in >> (Persoana&)s;
        cout << "Introduceti facultatea:\n";
        in >> s.facultate;
        return in;
    }

    void afisare()
    {
        Persoana::afisare();
        cout << "  " << this -> facultate << "\n";
    }
};

int main()
{
    char prenume[]={"Ale"};
    Persoana p1;
    Persoana p2(p1), p3;
    p3 = p1;
    Persoana p4("Dragomir", prenume, 19);

    p1.afisare();
    cout << endl;
    p2.afisare();
    cout << endl;
    p4.afisare();
    cout << endl;

    Student s1;
    s1.afisare();
    s1.calculeaza(5,3);
    cout << endl;
    cout << s1;
    cout << endl;
    Student s2;
    cin >> s2;
    cout << s2;
    return 0;
}
