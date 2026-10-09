#include <iostream>
#include <cstring>
using namespace std;

struct Cladire {
    unsigned char numar;
    //char culoare[20]; // alocare statica
    char* culoare; // alocare dinamica; * ocupa 8 octeti pe arhitectura pe 64 biti
    float inaltime; // precizie simpla 4 octeti
    int nrEtaje; // camel case
    bool esteDeschisa;
};

void afisareCladire(Cladire a) {
    cout << a.inaltime << " | " << a.esteDeschisa << " | "
         << a.nrEtaje << " | " << a.numar << " | "
         << a.culoare << endl;
}

int main() {
    std::cout << "hello world!" << std::endl;
    // std:: "::" operator de rezolutie a domeniului;
    // se scrie asa CA SA NU IMPORTAM TOT NAMESPACE UL

    Cladire c;

    // bool a = true; octetul cea mai mica unitate pt memorie
    cout << sizeof(c) << endl;

    c.inaltime = 30.4;
    c.esteDeschisa = true;
    c.nrEtaje = 10;
    c.numar = 'A';

    c.culoare = new char[strlen("Maro") + 1];
    strcpy(c.culoare, "Maro");

    afisareCladire(c);

    delete[] c.culoare; // dezalocare vector memorie
    return 0;
}