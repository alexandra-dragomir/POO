#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

///---------------------------------------------------- Building ----------------------------------------------------------

class Building

{

private:

    int nrRooms;
    bool extSpace;
    char state;                  //de inchiriat, vanzare, ocupata ---> i, v, o
    char *ownerName;
    char *adress;
    char type[3];               //ap, gs, cs
    float totalSurface;
    float *roomSurface;
    double price;
    int yearOfConst;
    static int currentYear;
    const int idBuilding;
    static int currentId;

public:
/// ....................................................................CONSTRUCTORI................................................
///................................................FARA PARAMETRU...................................................................
    Building() : idBuilding(currentId ++ )
    {
        cout << "CST BUILDING\n";
        this -> nrRooms = 0;
        this -> state = 0;
        this -> ownerName = new char[strlen("Unknown") + 1];
            strcpy(this -> ownerName, "Unknown");
        this -> totalSurface = 0;
        this -> roomSurface = new float[nrRooms];
        for(int i = 0; i < this -> nrRooms; i++)
            this -> roomSurface[i] = 0;
        this -> price = 0;
    }

///................................................CU PARAMETRII...................................................................
    Building(int nrRooms, bool extSpace, char state, char *ownerName, char *adress, char type[3], float *roomSurface, double price) : idBuilding(currentId ++ )
    {
        this -> nrRooms = nrRooms;
        this -> extSpace = extSpace;
        this -> state = state;
        this -> ownerName = new char[strlen(ownerName) + 1];
        strcpy(this -> ownerName, ownerName);

        this -> adress = new char[strlen(adress) + 1];
        strcpy(this -> adress, adress);
                                                                                //type!!
        strcpy(this -> type, type);

        this -> roomSurface = new float[nrRooms];
        for(int i = 0; i < this -> nrRooms; i++)
            this -> roomSurface[i] = roomSurface[i];

        float sup = 0;
        for(int i = 0; i < this -> nrRooms; i++)
            sup = sup + this -> roomSurface[i];
        this -> totalSurface = sup;

        this -> price = price;
    }

///................................................CU PARAMETRII...................................................................
    Building(int nrRooms, char state, char *ownerName, float *roomSurface) : idBuilding(currentId ++ )                      //nu prea are o functionalitate
    {
        cout<<"CST building"<<endl;
        this -> nrRooms = nrRooms;
        this -> state = state;
        this -> ownerName = new char[strlen(ownerName) + 1];
        strcpy(this -> ownerName, ownerName);


        this -> roomSurface = new float[nrRooms];
        for(int i = 0; i < this -> nrRooms; i++)
            this -> roomSurface[i] = roomSurface[i];

        float sup = 0;
        for(int i = 0; i < this -> nrRooms; i++)
            sup = sup + this -> roomSurface[i];
        this -> totalSurface = sup;
//        this -> anConstructie = anConstructie;
    }

    Building(int nrRooms, float *roomSurface, double price) : idBuilding(currentId ++ )
    {
        this -> nrRooms = nrRooms;
        this -> price = price;
        this -> roomSurface = new float[this -> nrRooms + 1];
        float total = 0;
        for(int i = 0; i < this -> nrRooms; i++)
        {
            this -> roomSurface[i] = roomSurface[i];
            total = total + roomSurface[i];
        }
        this -> totalSurface = total;

    }

///................................................DE COPIERE...................................................................

    Building(const Building &b) : idBuilding(currentId ++ )                                                                  //copy constructor
    {
        this -> nrRooms = b.nrRooms;
        this -> extSpace = b.extSpace;
        this -> state = b.state;
        this -> ownerName = new char[strlen(b.ownerName) + 1];
        strcpy(this -> ownerName, b.ownerName);

        this -> adress = new char[strlen(b.adress) + 1];
        strcpy(this -> adress, b.adress);

        strcpy(this -> type, type);

        this -> totalSurface = b.totalSurface;
        this -> roomSurface = new float[b.nrRooms];
        for(int i = 0; i < this -> nrRooms; i++)
            this -> roomSurface[i] = b.roomSurface[i];

        this -> price = b.price;

    }
///................................................SUPRAINCARCAREA =...................................................................

    Building& operator = (const Building &b)                                                    //supraincarcarea =
    {
        if(this != &b)
        {
            this -> nrRooms = b.nrRooms;
            this -> extSpace = b.extSpace;
            this -> state = b.state;

            if(this -> ownerName != NULL)
                delete [] this -> ownerName;
            this -> ownerName = new char[strlen(b.ownerName) + 1];
            strcpy(this -> ownerName, b.ownerName);

            strcpy(this -> type, type);

            if(this -> adress != NULL)
                delete [] this -> adress;
            this -> adress = new char[strlen(b.adress) + 1];
            strcpy(this -> adress, b.adress);


            this -> totalSurface = b.totalSurface;

            if(this -> roomSurface != NULL)
                delete [] this -> roomSurface;
            this -> roomSurface = new float[b.nrRooms];
            for(int i = 0; i < this -> nrRooms; i++)
                this -> roomSurface[i] = b.roomSurface[i];

            this -> price = b.price;

        }
        return *this;
    }


/// ....................................................................SETTERS................................................

    void setTotalSurface()          //???
    {
        float sup = 0;
        for(int i = 0; i < this -> nrRooms; i++)
            sup = sup + this -> roomSurface[i];
        this -> totalSurface = sup;

    }

    void setPrice(double x)
    {
        this -> price = x;
    }

    void setRooms(int nrRoomsAux, float *roomSurfaceAux)
    {
        if(this -> roomSurface != NULL)
            delete [] this -> roomSurface;

        this -> nrRooms = nrRoomsAux;
        this -> roomSurface = new float[nrRoomsAux + 1];

        for(int i = 0; i < nrRoomsAux; i++)
            this -> roomSurface[i] = roomSurfaceAux[i];
    }

    void setState(char s)
    {
        this -> state = s;
    }
/// ....................................................................GETTERS................................................

    int getNrRooms(){ return this -> nrRooms; }
    double getPrice() { return this -> price; }
    char getState() { return this -> state; }
    float getTotalSurface()
    {
        float sup = 0;
        for(int i = 0; i < this -> nrRooms; i++)
            sup = sup + this -> roomSurface[i];
        this -> totalSurface = sup;
        return sup;
    }
    float getPriceMp()
    {
        float r;
        r = this -> price / this -> totalSurface;
        return r;
    }

 ///..................................................................supraincarcari...................................................................


    bool operator == (const Building &b)
    {
        if(this -> price == b.price)
            if(this -> totalSurface == b.totalSurface)
                return true;
        return false;

    }

    bool operator < (const Building &b)
    {
        float r1, r2;
        r1 = getPriceMp();
        r2 = b.price / b.totalSurface;;
        if(r1 < r2)
            return true;
        return false;
    }

    bool operator > (const Building &b)
    {
        float r1, r2;
        r1 = this -> price / this -> totalSurface;
        r2 = b.price / b.totalSurface;
        if(r1 > r2)
            return true;
        return false;
    }

    int operator + (int x)
    {
        return this -> price + x;
    }

    int operator [] (int i)
    {
        if(i == 1)
            return this -> nrRooms;
        if(i == 2)
            return this -> price;
    }




 ///..................................................................FUNCTIONALITATI...................................................................


    void write()
    {
        cout << this -> ownerName << " are o proprietate de " << getTotalSurface() << " mp construita in anul " << this -> yearOfConst << endl;
        cout << "Suprafete pe camere sunt: \n";
        for(int i =0 ; i < this -> nrRooms; i++)
            cout << "Camera " << i+1 << " are " << this -> roomSurface[i] << " mp \n";
        cout << "Imobilul se afla in zona: " << this -> adress << endl;
        if(this -> state == 'v')
            cout << this -> type << " este de vanzare " << endl;
        if(this -> state == 'i')
            cout << this -> type << " este de inchiriat " << endl;
        if(this -> state == 'o')
            cout << this -> type << " este ocupat " << endl;
        if(this -> extSpace)
            cout << "Are spatiu exterior " << endl;
        else
            cout << "Nu are spatiu exterior " << endl;

    }


/// .................................................................... supraincarcarile << si >> ................................................                                                                                            //supraincarcarea >>
    friend istream& operator >> (istream& in, Building& b)
    {
        cout << "Introduceti detaliile constructiei: \n";

        cout << "Numele proprietarului: \n";
        char aux[10];
        in >> aux;
        if(b.ownerName != NULL)
            delete [] b.ownerName;
        b.ownerName =  new char[strlen(aux) + 1];
        strcpy(b.ownerName, aux);
        in.get();

        cout << "Adresa cladirii (zona): \n";
        char aux2[10];
        in.get(aux2, 100);
   /*     if(b.adress != NULL)          //nu continua citirea
            delete [] b.adress;*/
        b.adress =  new char[strlen(aux2) + 1];
        strcpy(b.adress, aux2);
        in.get();

        cout << "Tipul locuintei: (ap-apartament, gs-garsoniera, cs-casa)\n";
        char htype[3];
        in.get(htype, 4);
        strcpy(b.type, htype);

        cout << "Starea locuintei: (v-vanzare, i-inchiriere, o-ocupata) \n";
        in >> b.state;

        cout << "\nNr de camere: \n";
        in >> b.nrRooms;

        cout << "\nSuprafetele camerelor: \n";
        for(int i = 0; i < b.nrRooms; i++)
        {
            cout << "Suprafata camera " << i + 1 <<": ";
            in >> b.roomSurface[i];
        }

        cout << "Are spatiu exterior? (0 sau 1)\n";
        int i;
        in >> i;
        b.extSpace = bool(i);

        cout << "Introduceti pretul: ";
        in >> b.price;
        cin.get();
        return in;


    }


    friend ostream& operator << (ostream& out, Building& b)
    {

        cout << b.ownerName << " are o proprietate de " << b.getTotalSurface() << " mp construita in anul " << b.yearOfConst << endl;                                 //getTotalSurface() doesn't work here
        cout << "Suprafete pe camere sunt: \n";
        for(int i =0 ; i < b.nrRooms; i++)
            cout << "Camera " << i+1 << " are " << b.roomSurface[i] << " mp \n";
        cout << "Imobilul se afla in zona: " << b.adress << endl;
        if(b.state == 'v')
            cout << b.type << " este de vanzare " << endl;
        if(b.state == 'i')
            cout << b.type << " este de inchiriat " << endl;
        if(b.state == 'o')
            cout << b.type << " este ocupat " << endl;
        if(b.extSpace)
            cout << "Are spatiu exterior " << endl;
        else
            cout << "Nu are spatiu exterior " << endl;
        return out;

    }


/// ....................................................................DESTRUCTOR................................................                                                                                          //destructor
    ~Building()
    {
        cout << "DST building " << endl;
        if(this -> ownerName != NULL)
            delete [] this -> ownerName;
        if(this -> roomSurface != NULL)
            delete [] this -> roomSurface;
        if(this -> type != NULL)
            delete [] this -> type;
        if(this -> adress != NULL)
            delete [] this -> adress;
    }

};

///---------------------------------------------------- Buyer ----------------------------------------------------------

class Buyer

{
private:
    int age;
    int nrAccounts;
    bool isIntersted;
    char options;               //cumaparat, inchiriat
    char *name;
    char cnp[14];
    float anualSalary;
    float *otherIncomes;
    double totalIncome;
    const int idBuyer;
    static int currentId;

public:
/// ....................................................................CONSTRUCTORI................................................

///................................................FARA PARAMETRU...................................................................
    Buyer() : idBuyer(currentId ++ )                                                                                     //constructor fara parametrii
    {
        cout << "CST BUYER\n";
        this -> name = new char[strlen("Unknown") + 1];
            strcpy(this -> name, "Unknown");
        this -> anualSalary = 0;
        this -> totalIncome = 0;
        strcpy(this -> cnp, "unknown");
        this -> isIntersted = bool(0);
    }
///................................................CU PARAMETRU...................................................................
    Buyer(int age, bool isIntersted, char options, char *nume, char cnp[13], float anualSalary, int nrAccounts, float *otherIncomes) : idBuyer(currentId ++ )
    {
        this -> age = age;
        this -> options = options;

        this -> name = new char[strlen(this -> name) + 1];
        strcpy(this -> name, name);

        strcpy(this -> cnp, cnp);

        this -> anualSalary = anualSalary;
        this -> otherIncomes = new float[nrAccounts + 1];
        for(int i = 0; i < nrAccounts; i++)
            this -> otherIncomes[i] = otherIncomes[i];

        double income = 0;
        for(int i = 0; i < nrAccounts; i++)
            income = income + otherIncomes[i];
        income = income + this -> anualSalary;
        this -> totalIncome = income;
    }
///................................................CU PARAMETRU...................................................................
    Buyer(int age, bool isIntersted, char options, char *name, float anualSalary) : idBuyer(currentId ++ )                  //nu prea are o functionalitate
    {
        cout<<"CST persoana "<<endl;
        this -> age = age;
        this -> options = options;

        this -> name = new char[strlen(this -> name) + 1];
        strcpy(this -> name, name);
        this -> isIntersted = isIntersted;
        this -> anualSalary = anualSalary;
    }

    Buyer(char cnp[14], float anualSalary, int nrAccounts, float *otherIncomes) : idBuyer(currentId ++ )
    {
        this -> anualSalary = anualSalary;
        this -> nrAccounts = nrAccounts;
        this -> otherIncomes = new float[this -> nrAccounts + 1];
        for(int i = 0; i < this -> nrAccounts; i++)
            this -> otherIncomes[i] = otherIncomes[i];
        strcpy(this -> cnp, cnp);
        this -> totalIncome = getTotalIncome();
    }


///................................................DE COPIERE...................................................................                                                                                                    //copy constructor
    Buyer(const Buyer& b) : idBuyer(currentId ++ )
    {
        this -> age = b.age;
        this -> options = b.options;
        this -> anualSalary = b.anualSalary;
        this -> totalIncome = b.totalIncome;

        this -> name = new char[strlen(b.name) + 1];
        this -> otherIncomes = new float[nrAccounts + 1];

        strcpy(this -> name, b.name);
        strcpy(this -> cnp, b.cnp);
        for(int i = 0; i < nrAccounts; i++)
            this -> otherIncomes[i] = otherIncomes[i];
    }
///................................................SUPRAINCARCAREA =...................................................................                                                                                                    //supraincarcarea =
    Buyer& operator = (const Buyer &b)
    {
        if( this != &b)
        {
            this -> age = b.age;
            this -> options = b.options;

            if(this -> name != NULL)
                delete [] this -> name;
            this -> name = new char[strlen(this -> name) + 1];
            strcpy(this -> name, b.name);

            strcpy(this -> cnp, b.cnp);
            this -> anualSalary = b.anualSalary;

            if(this -> otherIncomes != NULL)
                delete [] this -> otherIncomes;
            this -> otherIncomes = new float[nrAccounts + 1];
            for(int i = 0; i < nrAccounts; i++)
                this -> otherIncomes[i] = otherIncomes[i];

            this -> totalIncome = b.totalIncome;
        }
    }
/// ....................................................................SETTERS................................................
    void setName(char *n)
    {
        if(this -> name != NULL)
            delete [] this -> name;
        this -> name = new char[strlen(n) + 1];
        strcpy(this -> name, n);
    }
    void setOptions(char o)
    {
        this -> options = o;
    }
    void setSalary(float s)
    {
        this -> anualSalary = s;
    }
    void setOtherIncomes(int nrAccountsAux, float *otherIncomesAux)
    {
        if(this -> otherIncomes != NULL)
            delete [] this -> otherIncomes;

        this -> nrAccounts = nrAccountsAux;
        this -> otherIncomes = new float[nrAccountsAux + 1];
        for(int i = 0; i < nrAccountsAux; i++)
            this -> otherIncomes[i] = otherIncomesAux[i];
    }


/// ....................................................................GETTERS................................................

    char getOptions() { return this -> options; }
    float getSalary() { return this -> anualSalary; }
    double getTotalIncome()
    {
        double total = 0;
        total = total + this -> anualSalary;
        if(this -> nrAccounts != 0)
            for(int i = 0; i < this -> nrAccounts; i++)
                total = total + this -> otherIncomes[i];
        return total;
    }
 ///..................................................................supraincarcari...................................................................

    const Buyer operator ++ ()
    {
        this -> age ++;
        return *this;
    }
    const Buyer operator ++ (int)
    {
        Buyer aux(*this);
        this -> age ++;
        return aux;
    }

    bool operator == (const Buyer &b)
    {
        if(strcmp(this -> cnp, b.cnp) == 0)
        {
            return true;
        }
        return false;
    }

    bool operator < (const Buyer &b)
    {
        double t1, t2;
        t1 = getTotalIncome();
        t2 = b.totalIncome;                    //b.getTotalIncome() => error: passing const Buyer as this argument discards qualifiers
        if(t1 < t2)
            return true;
        return false;
    }

    float operator + (float i)
    {
        return this -> anualSalary + i;
    }

    float operator * (float i)
    {
        return this -> anualSalary * i;
    }

    char* operator [] (int i)
    {
        if(i == 1)
            return this -> name;
    }


 ///..................................................................FUNCTIONALITATI...................................................................

    void write()
    {
        cout << "Persoana " << this -> name;
        if(this -> isIntersted)
            cout << " este interesata sa cumpere ";
        else
            cout << " nu este interesata sa cumpere ";
        cout << endl;
        cout << "Are un venit anual de " << this -> anualSalary << endl;
        cout << "venit total: " << this -> totalIncome << endl;
        cout << "ALso, are cnp ul asta: " << this -> cnp << endl;
    }



/// .................................................................... supraincarcarile << si >> ................................................                                                                                            //supraincarcarea >>

                                                                                                    // supraincarcareaa >>
    friend istream& operator >> (istream& in, Buyer& b)
    {
        cout << "Introduceti datele despre cumparator: \n";

        cout << "Introduceti numele lui: \n";
        char aux[100];
        in.get(aux, 100);
        if(b.name != NULL)
            delete [] b.name;
        b.name = new char[strlen(aux) + 1];
        strcpy(b.name, aux);
        in.get();


        cout << "CNP ul: \n";
        char c[100];
        in >> c;
        strcpy(b.cnp, c);
        in.get();

        cout << "Este interesat sa cumpere/inchirieze? (0-nu, 1-da)\n";
        char opt;
        in >> opt;
        b.isIntersted = opt;

        cout << "Ce doreste sa faca? (c-cumparat, i-inchiriat)\n";
        in >> b.options;
        in.get();

        cout << "Care este salariul anual? \n";
        cout << b.anualSalary << "*" << endl;
        in >>  b.anualSalary;


        cout << "Are si alte surse de venit? (0-nu, nr lor-da) \n";
        in >> b.nrAccounts;
        if(b.nrAccounts != 0)
        {
            b.otherIncomes = new float[b.nrAccounts + 1];
            for(int i = 0; i < b.nrAccounts; i++)
            {
                cout << "Suma din contul " << i + 1 << ": ";
                in >> b.otherIncomes[i];
            }
        }
        cin.get();
        return in;
    }

    friend ostream& operator << (ostream& out, Buyer& b)
    {
        cout << "Persoana " << b.name;
        if(b.isIntersted)
            cout << " este interesata sa cumpere ";
        else
            cout << " nu este interesata sa cumpere ";
        cout << endl;
        cout << "Are un salariu anual de " << b.anualSalary << endl;
        cout << "Venitul total este de: " << b.getTotalIncome() << endl;
        cout << "ALso, are cnp ul asta: " << b.cnp << " si Id ul asta: " << b.idBuyer << endl;

        return out;
    }



/// ....................................................................DESTRUCTOR................................................                                                                                          //destructor

    ~Buyer()
    {
        cout<<"DST buyer"<<endl;
        if(this -> name != NULL)
            delete [] this -> name;
        if(this -> otherIncomes != NULL)
            delete [] this -> otherIncomes;
    }

};

///------------------------------------------------------------------- Employee ----------------------------------------------------------

class Employee          //or broker

{

private:
    int years;
    char *name;
    float salary;
    int nrHouses;
    int *commissions;
    const int idEmployee;
    static int currentId;

public:

    Employee() : idEmployee(currentId ++ )
    {
        this -> name = new char[strlen("Unknown") + 1];
        strcpy(this -> name, "Unknown");
        this -> salary = 0;
        this -> nrHouses = 0;
        this -> years = 0;
        this -> commissions = new int[0];
    }

    Employee(int years, char *name, float salary, int nrHouses, int *commissions) : idEmployee(currentId ++ )
    {
        this -> years = years;
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);

        this -> salary = salary;
        this -> nrHouses = nrHouses;
        this -> commissions = new int[nrHouses];
        for(int i = 0; i < nrHouses; i++)
            this -> commissions[i] = commissions[i];

    }

    Employee(const Employee& e) : idEmployee(currentId ++ )
    {
        this -> years = e.years;
        this -> salary = e.salary;
        this -> nrHouses = e.nrHouses;

        if(this -> name != NULL)
            delete [] this -> name;
        if(this -> commissions != NULL)
            delete [] this -> commissions;

        this -> name = new char[strlen(e.name) + 1];
        this -> commissions = new int[e.nrHouses + 1];

        strcpy(this -> name, e.name);
        for(int i = 0; i < this -> nrHouses; i++)
            this -> commissions[i] = e.commissions[i];

    }

    ~Employee()
    {
        if(this -> name != NULL)
            delete [] this -> name;
        if(this -> commissions != NULL)
            delete [] this -> commissions;
    }

};

///-------------------------------------------------------------------- Agency ----------------------------------------------------------

class Agency
{

private:

    int totalIncome;
    int nrEmployees;
    int nrHousesSold;
    int nrHousesOnMarket;
    int *houseOption;                   //1 = vanzare, 2 = inchireiere
    float *housePrice;

public:

    static char agencyName[3];
    static char agencyAdress[3];

    Agency()
    {
        this -> totalIncome = 0;
        this -> nrEmployees = 0;
        this -> nrHousesSold = 0;
        this -> nrHousesOnMarket = 0;
        this -> houseOption = new int[0];
        this -> housePrice = new float[0];
    }

    Agency(int nrEmployees, int nrHousesSold, int nrHousesOnMarket, int *houseOption, float *housePrice)
    {
        this -> nrEmployees = nrEmployees;
        this -> nrHousesSold = nrHousesSold;
        this -> nrHousesOnMarket = nrHousesOnMarket;

        this -> houseOption = new int[nrHousesOnMarket + 1];
        this -> housePrice = new float[nrHousesOnMarket + 1];

        for(int i = 0; i < nrHousesOnMarket; i++)
            this -> houseOption[i] = houseOption[i];
        for(int i = 0; i < nrHousesOnMarket; i++)
            this -> housePrice[i] = housePrice[i];

    }

    Agency(const Agency& a)
    {
        this -> totalIncome = a.totalIncome;
        this -> nrEmployees = a.nrEmployees;
        this -> nrHousesSold = a.nrHousesSold;
        this -> nrHousesOnMarket = a.nrHousesOnMarket;

        if(this -> houseOption != NULL)
            delete [] this -> houseOption;
        if(this -> housePrice != NULL)
            delete [] this -> housePrice;

        this -> houseOption = new int[this -> nrHousesOnMarket + 1];
        this -> housePrice = new float[this -> nrHousesOnMarket + 1];

        for(int i = 0; i < nrHousesOnMarket; i++)
            this -> houseOption[i] = a.houseOption[i];
        for(int i = 0; i < nrHousesOnMarket; i++)
            this -> housePrice[i] = a.housePrice[i];

    }

    ~Agency()
    {
        if(this -> houseOption != NULL)
            delete [] this -> houseOption;
        if(this -> housePrice != NULL)
            delete [] this -> housePrice;
    }


};
/*
char Agency::agencyName = "aa";
char Agency::adress = "aa";
*/
int Building :: currentYear = 2020;
int Buyer :: currentId = 0;
int Building :: currentId = 0;

int main()
{

//    Building(int nrCamere, char stareVanzare, char *numeProprietar, float supTotala, float *supCamere, int yearOfConst)
//    Buyer(int varsta, bool interesat, char sex, char *nume, char cnp[13], float venitSalariu, int nrConturi, float *otherIncomes)
/*
    float sup[] = {30, 20, 20};
    char nume[] = "alex";*/

  //  Building p(3, 'v', nume, 70, sup);
   // p.write();

  //  Buyer prs(19, 0, 'f', nume, 20000);
 //   prs.write();

/*
    Building b1;
    cin >> b1;
    cout << b1;
*/
/*
    float sup[] = {30, 40};
    Building b1(2, sup, 70000);         //1000
    Building b2(2, sup, 7000);          //100

    cout << (b1 > b2) << endl;
    cout << (b1 == b2) << endl;
*/
/*
    cout << "-------------" << endl;

    char cnp1[] = "6010215450035";
    char cnp2[] = "6010215550035";
    float acc1[] = {2000, 3000, 5000};
    float acc2[] = {2000, 4000, 5000};
    Buyer b3(cnp1, 12000, 3, acc1);
    Buyer b4(cnp2, 12000, 3, acc2);
    cout << (b3 == b4) << endl;
    cout << (b3 < b4) << endl;
    b3.setName("ale");
    cout << b3[1] << endl;
*/
    Building b1;
    cin >> b1;
    cout << b1;
    cout << "-------" << endl;
    Buyer b2, b4;
    cin >> b2;
    cout << b2;
    cout << "-------" << endl;
    cin >> b4;
    cout << "-------" << endl;
    cout << b4;

    return 0;
}
