#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Student{
//provate, protected, public

private:
    const int ID_Matricol;
    int varsta;
    char* nume;
    int nrNote;
    int* note;              //declarare

public:
    static int anCurent;                 //acceseaza aceasi zona de memorie; daca vrem ca toate variabilele de acolo sa aiba aceasi valoare
    static void mesaj(){
        cout<<"Bine ati venit studenti de anul  "<<anCurent;

    }

    Student() : ID_Matricol(00000){

        this->varsta = 0;               //mergea si fara this
        this->nume = new char[strlen("Anonim") + 1];
        strcpy(this->nume, "Anonim");

    }

    Student(int id, int varsta, char* nume, int nrNote, int* note) : ID_Matricol(id){

        this->varsta = varsta;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);

        this->nrNote = nrNote;

        this->note = new int[nrNote];           //ii dam memorie

        for(int i=0; i<nrNote; i++)
            this->note[i] = note[i];

    }

    Student(int varsta):ID_Matricol(00){
        this->varsta = varsta;
    }
    /*
    Student(float vartsa):ID_Matricol(00){      //daca sunt tipuri diferite de date, le diferentiaza, altfel conteaza nr de paramatrii
        this->varsta = varsta;
    }
    */

    void afisare(){

        cout << "Studentul " << this->nume << " are urmatoarele note: ";
        for(int i=0; i<this->nrNote; i++)
            cout<<this->note[i]<<" ";
    }
    int getNrNote(){
        return this->nrNote;
    }
    char* getNume(){
        return this->nume;
    }
    int* getNote(){
        return this->note;          //forma "frumoasa"cu this
    }
    int getVarsta(){
        return varsta;
    }

    //setter
    void setVarsta(int a){

        this->varsta = a;

    }

    void setNume(char* a){

        if(this->nume != NULL)           //nullptr nu merge la versiunea asta
            delete[] this->nume;

        this->nume = new char[strlen(a)+1];
        strcpy(this->nume, a);

    }

    void setNote(int* a, int b){

        if(this->note != NULL)
            delete[] this->note;

        this->nrNote = b;
        this->note = new int[b];

        for(int i=0; i<b; i++)
            this->note[i] = a[i];
    }

    float medieStudent(){

        float medie_note;
        for(int i=0; i<this->nrNote; i++)
            medie_note = medie_note + note[i];
        medie_note = medie_note/(this->note);               //eroare invalid operands of types 'float' and 'int' to binary 'operator/'

        return medie_note;

    }




    ~Student() {                //destructor la final doar

        if(this->note != NULL)
            delete[] this->note;
        if(this->nume != NULL)
            delete[] this->nume;

    }





};

int Student::anCurent = 2;

int main()
{
    /*
    cout << Student :: anCurent;
    Student::mesaj();
    */

    Student s;

    char nume[] = {"POO"};
    char nume2[] = {"POO2"};

    int alabala[] = {5, 5, 5, 5};
    int alabala2[] = {5, 6, 7, 8, 10};

    Student s2(101, 3, nume, 4, alabala);
    s2.afisare();

    cout<<s2.getNume();
    cout<<endl;

    s2.setNume(nume2);
    cout<<s2.getNume()<<endl;

    int* note = s2.getNote();
    for(int i=0; i<s2.getNrNote(); i++)
        cout<<*(note+i)<<" ";

    cout<<endl<<endl;
    cout<<s2.getVarsta();
    cout<<endl;
    s2.setVarsta(24);
    cout<<s2.getVarsta();

    cout<<"---------\n";
    int* note2 = s2.getNote();
    for(int i=0; i<s2.getNrNote(); i++)
        cout<<*(note2+i)<<"\n";

    cout<<s2.medieStudent();

    return 0;
}
