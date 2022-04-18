#include <iostream>
#include <typeinfo>

using namespace std;

class Locuinta {
protected:
    string numeClient;
    int suprafataUtila;
    float discount;
public:
    //Constructori
    Locuinta(string numeClient, int suprafataUtila, float discount) {
        this->numeClient = numeClient;
        this->suprafataUtila = suprafataUtila;
        this->discount = discount;
    }
    Locuinta() {
        this->numeClient = "Necunoscut";
        this->suprafataUtila = 0;
        this->discount = 0.0;
    }
    //Constructor de copiere
    Locuinta(Locuinta& l) {
        this->numeClient = l.numeClient;
        this->suprafataUtila = l.suprafataUtila;
        this->discount = l.discount;
    }
    //Destructor
    ~Locuinta() {
        delete &numeClient;
        delete &suprafataUtila;
        delete &discount;
    }

    //Getters
    string getNumeClient() {
        return this->numeClient;
    }
    int getSuprafataUtila() {
        return this->suprafataUtila;
    }
    float getDiscount() {
        return this->discount;
    }
    //Setters
    void setNumeClient() {
        this->numeClient = numeClient;
    }
    void setSuprafataUtila() {
        this->suprafataUtila = suprafataUtila;
    }
    void setDiscount() {
        this->discount = discount;
    }

    //Supraincarcare operatori
    Locuinta& operator=(Locuinta& l) {
        if (this != &l) {
            numeClient = l.numeClient;
            suprafataUtila = l.suprafataUtila;
            discount = l.discount;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, Locuinta& l) {
        cout<<"numeClient: "<<l.numeClient<<endl<<"suprafataUtila: "<<l.suprafataUtila<<endl<<"discount: "<<l.discount<<endl;
    }
    friend istream& operator>>(istream&, Locuinta& l) {
        string numeClient;
        int suprafataUtila;
        float discount;
        cin>>numeClient>>suprafataUtila>>discount;
        l.numeClient = numeClient;
        l.suprafataUtila = suprafataUtila;
        l.discount = discount;
    }

    //CalculChirie

    virtual float CalculChirie(int X, bool Y) {
        return 0;
    }
};

class Apartament : public Locuinta {
protected:
    int etaj;
public:
    //Constructori
    Apartament(string numeClient, int suprafataUtila, float discount, int etaj) {
        this->numeClient = numeClient;
        this->suprafataUtila = suprafataUtila;
        this->discount = discount;
        this->etaj = etaj;
    }
    Apartament() {
        this->numeClient = "Necunoscut";
        this->suprafataUtila = 0;
        this->discount = 0.0;
        this->etaj = 0;
    }
    //Constructor de copiere
    Apartament(Apartament& l) {
        this->numeClient = l.numeClient;
        this->suprafataUtila = l.suprafataUtila;
        this->discount = l.discount;
        this->etaj = l.etaj;
    }
    //Destructor
    ~Apartament() {
        delete &numeClient;
        delete &suprafataUtila;
        delete &discount;
        delete &etaj;
    }

    //Getters
    int getEtaj() {
        return this->etaj;
    }
    //Setters
    void setEtaj() {
        this->etaj = etaj;
    }

    //Supraincarcare operatori
    Apartament& operator=(Apartament& l) {
        if (this != &l) {
            numeClient = l.numeClient;
            suprafataUtila = l.suprafataUtila;
            discount = l.discount;
            etaj = l.etaj;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, Apartament& l) {
        cout<<"numeClient: "<<l.numeClient<<endl<<"suprafataUtila: "<<l.suprafataUtila<<endl<<"discount: "<<l.discount<<endl<<"etaj: "<<l.etaj<<endl;;
    }
    friend istream& operator>>(istream&, Apartament& l) {
        string numeClient;
        int suprafataUtila;
        float discount;
        int etaj;
        cin>>numeClient>>suprafataUtila>>discount>>etaj;
        l.numeClient = numeClient;
        l.suprafataUtila = suprafataUtila;
        l.discount = discount;
        l.etaj = etaj;
    }

    //CalculChirie

    float CalculChirie(int X, bool Y) {
        return X * suprafataUtila * (1 - Y * discount / 100.0);
    }
};

class Casa : public Locuinta {
protected:
    int suprafataCurte;
public:
    //Constructori
    Casa(string numeClient, int suprafataUtila, float discount, int suprafataCurte) {
        this->numeClient = numeClient;
        this->suprafataUtila = suprafataUtila;
        this->discount = discount;
        this->suprafataCurte = suprafataCurte;
    }
    Casa() {
        this->numeClient = "Necunoscut";
        this->suprafataUtila = 0;
        this->discount = 0.0;
        this->suprafataCurte = 0;
    }
    //Constructor de copiere
    Casa(Casa& l) {
        this->numeClient = l.numeClient;
        this->suprafataUtila = l.suprafataUtila;
        this->discount = l.discount;
        this->suprafataCurte = l.suprafataCurte;
    }
    //Destructor
    ~Casa() {
        delete &numeClient;
        delete &suprafataUtila;
        delete &discount;
        delete &suprafataCurte;
    }

    //Getters
    int getEtaj() {
        return this->suprafataCurte;
    }
    //Setters
    void setEtaj() {
        this->suprafataCurte = suprafataCurte;
    }

    //Supraincarcare operatori
    Casa& operator=(Casa& l) {
        if (this != &l) {
            numeClient = l.numeClient;
            suprafataUtila = l.suprafataUtila;
            discount = l.discount;
            suprafataCurte = l.suprafataCurte;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, Casa& l) {
        cout<<"numeClient: "<<l.numeClient<<endl<<"suprafataUtila: "<<l.suprafataUtila<<endl<<"discount: "<<l.discount<<endl<<"suprafataCurte: "<<l.suprafataCurte<<endl;;
    }
    friend istream& operator>>(istream&, Casa& l) {
        string numeClient;
        int suprafataUtila;
        float discount;
        int suprafataCurte;
        cin>>numeClient>>suprafataUtila>>discount>>suprafataCurte;
        l.numeClient = numeClient;
        l.suprafataUtila = suprafataUtila;
        l.discount = discount;
        l.suprafataCurte = suprafataCurte;
    }

    //CalculChirie

    float CalculChirie(int X, bool Y) {
        return X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount / 100.0);
    }
};

class AgentieImobiliara {
private:
    Apartament v1[100];
    Casa v2[100];
    int k1 = 0, k2 = 0;
public:
    //Constructor
    AgentieImobiliara() {
        this->k1 = 0;
        this->k2 = 0;
    }
    //Constructor de copiere
    AgentieImobiliara(AgentieImobiliara& a) {
        this->k1 = a.k1;
        this->k2 = a.k2;
        for (int i = 0; i < a.k1; i++) {
            this->v1[i] = a.v1[i];
        }
        for (int i = 0; i < a.k2; i++) {
            this->v2[i] = a.v2[i];
        }
    }
    //Destructor
    ~AgentieImobiliara() {
        delete &k1;
        delete &k2;
        delete &v1;
        delete &v2;
    }

    //Getters
    int getK1() {
        return this->k1;
    }
    int getK2() {
        return this->k2;
    }
    //Setters
    void setK1() {
        this->k1 = k1;
    }
    void setK2() {
        this->k2 = k2;
    }

    //Supraincarcare operatori
    AgentieImobiliara& operator=(AgentieImobiliara& a) {
        if (this != &a) {
            k1 = a.k1;
            k2 = a.k2;
            for (int i = 0; i < a.k1; i++) {
                v1[i] = a.v1[i];
            }
            for (int i = 0; i < a.k2; i++) {
                v2[i] = a.v2[i];
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, AgentieImobiliara& a) {
        for (int i = 0; i < a.k1; i++) {
            cout<<"Apartament "<<i<<endl;
            cout<<a.v1[i];
            cout<<endl;
        }
        for (int i = 0; i < a.k2; i++) {
            cout<<"Casa "<<i<<endl;
            cout<<a.v2[i];
            cout<<endl;
        }
    }
    void afisareApartamente() {
        for (int i = 0; i < k1; i++) {
            cout<<"Apartament "<<i<<endl;
            cout<<v1[i];
            cout<<endl;
        }
    }
    void afisareCase() {
        for (int i = 0; i < k2; i++) {
            cout<<"Casa "<<i<<endl;
            cout<<v2[i];
            cout<<endl;
        }
    }
    void afisareApartamenteChirie(int X, bool Y) {
        for (int i = 0; i < k1; i++) {
            cout<<"Apartament "<<i<<endl;
            cout<<v1[i];
            cout<<"chirie: "<<v1[i].CalculChirie(X, Y)<<" lei"<<endl;
            cout<<endl;
        }
    }
    void afisareCaseChirie(int X, bool Y) {
        for (int i = 0; i < k2; i++) {
            cout<<"Casa "<<i<<endl;
            cout<<v2[i];
            cout<<"chirie: "<<v2[i].CalculChirie(X, Y)<<" lei"<<endl;
            cout<<endl;
        }
    }

    friend istream& operator>>(istream&, AgentieImobiliara& a) {
        string tip;
        while (cin>>tip) {
            if (tip == "apartament") {
                Apartament loc;
                cin>>loc;
                a.v1[a.k1] = loc;
                a.k1++;
            } else if (tip == "casa") {
                Casa loc;
                cin>>loc;
                a.v2[a.k2] = loc;
                a.k2++;
            } else break;
        }
    }
};

int meniu() {
    cout<<"Agentia Imobiliara:"<<endl;
    cout<<"1 - Afisati locuintele."<<endl;
    cout<<"2 - Afisati apartamentele."<<endl;
    cout<<"3 - Afisati casele."<<endl;
    cout<<"4 - Adaugati locuinte."<<endl;
    cout<<"5 - Calculati chiria pentru fiecare locuinta."<<endl;
    cout<<"0 - Parasiti agentia."<<endl;
    char optiune;
    cin>>optiune;
    cin.get();
    return optiune;
}

int main()
{
    AgentieImobiliara a;
    char optiune;

    while (true) {
        optiune = meniu();
        if (optiune == '0') break;
        else if (optiune != '1' && optiune != '2' && optiune != '3' && optiune != '4' && optiune != '5') cout<<"Nu ati introdus o optiune valida. Incercati din nou."<<endl<<endl;
        else if (optiune == '1') {
            if (a.getK1() == 0 && a.getK2() == 0) cout<<"Momentan nu exista nicio locuinta."<<endl<<endl;
            else {
                cout<<a;
            }
        } else if (optiune == '2') {
            if (a.getK1() == 0) cout<<"Momentan nu exista niciun apartament."<<endl<<endl;
            else {
                a.afisareApartamente();
            }
        } else if (optiune == '3') {
            if (a.getK1() == 0) cout<<"Momentan nu exista nicio casa."<<endl<<endl;
            else {
                a.afisareCase();
            }
        } else if (optiune == '4') {
            cout<<"Introduceti locuintele dupa formatul: tip(apartament/casa) numeClient suprafataUtila discount etaj/suprafataCurte ... Introduceti cifra 0 la final pentru a incheia."<<endl<<endl;
            cin>>a;
        } else if (optiune == '5') {
            if (a.getK1() == 0 && a.getK2() == 0) {
                cout<<"Momentan nu exista nicio locuinta."<<endl<<endl;
                continue;
            }
            int X;
            bool Y;
            cout<<"Introduceti valoare standard chirie / mp (intreg): ";
            cin>>X;
            cout<<"Doriti ca discountul sa fie luat in calcul (0/1)? ";
            cin>>Y;
            a.afisareApartamenteChirie(X, Y);
            a.afisareCaseChirie(X, Y);
        }
    }
    return 0;
}
