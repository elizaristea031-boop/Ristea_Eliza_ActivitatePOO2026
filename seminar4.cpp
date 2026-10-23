#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
private://incapsulare

	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;

	const int id;//atribut constant
	static int contor;//atribut static, adica apartine clasei=>atribut distinct pt fiecare obiect al clasei
public:
	Prajitura() :id(contor++) {//constructor
		this->denumire = new char[strlen("Tiramisu") + 1];//"->" face dereferentiere si accesare 
		strcpy(denumire, "Tiramisu");
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	Prajitura(const char* denumire, float pret) :id(contor++) {//constructor; il declaram constant pentru a "promite" ca nu se modifica acea zona de memorie
		this->denumire = new char[strlen(denumire) + 1];//"->" face dereferentiere si accesare 
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	Prajitura(const Prajitura& p) :id(contor++)
	{
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);

		this->pret = p.pret;
		this->cantitate = p.cantitate;
		this->dePost = p.dePost;
		this->nrIngrediente = p.nrIngrediente;

		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0;i < this->nrIngrediente;i++)
			this->ingrediente[i] = p.ingrediente[i];
	}
	~Prajitura();//destructor

	int getCantitate() {//getter
		return this->cantitate;
	}

	int getNrIngrediente() {
		return this->nrIngrediente;

	}

	int getPret() {
		return this->pret;
	}

	static int getContor() {
		return contor;
	}
	void afisare() {//facem o metoda prin care afisam prajitura
		cout << "Denumire:" << this->denumire << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "Cantitate:" << this->cantitate << endl;
		cout << "De Post:" << (this->dePost ? "DA" : "NU") << endl;//cu ajutorul operatorului ternar
		cout << "Nr ingrediente:" << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;

	}
	float costMediuGram() {//o metoda care calc. pretul mediu per gram
		if (cantitate == 0)
			return 0;
		else {
			return this->pret / this->cantitate;
		}
	}
	void modificaDenumire(const char* denumire) {
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
};
//nu se scrie nimic intre initializarea staticului si clasa
int Prajitura::contor = 100;

Prajitura::~Prajitura() {//destructor declarat in clasa si implementat in afara clasei
	delete[] this->denumire;//se curata ce e pe hip
	delete[] this->ingrediente;

}

float calculeazaCantitateaTotala(Prajitura* prajituri, int nr_prajituri) {//este functie, nu metoda
	float greutate = 0;
	for (int p = 0;p < nr_prajituri;p++)
	{
		greutate += prajituri[p].getCantitate();//se apeleaza getterul(metoda si functie) pentru a obtine cantitate
	}
	return greutate;
}
float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();
	return 0;
}

int main() {
	Prajitura p;
	p.afisare();
	//Prajitura* pp;//apelam prin intermediul unui obiect
	//(*pp).afisare();//apelam prin intermediul unui pointer dereferetiat
	//pp->afisare();
	Prajitura::getContor();
	
	cout << calculeazaPretPerIngredient(p);
	return 0;
}