#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
public:

	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;

	//const int id;


	Prajitura() {//constructor
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

	Prajitura(const char*denumire,float pret) {//constructor; il declaram constant pentru a "promite" ca nu se modifica acea zona de memorie
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


	void afisare() {//facem o metoda prin care afisam prajitura
		cout << "Denumire:" << this->denumire<<endl;
		cout << "Pret:" << this->pret<<endl;
		cout << "Cantitate:" << this->cantitate << endl;
		cout << "De Post:" << (this->dePost ? "DA":"NU") << endl;//cu ajutorul operatorului ternar
		cout << "Nr ingrediente:" << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for(int i=0;i<this->nrIngrediente;i++)
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

float calculeazaCantitateaTotala(Prajitura* prajituri, int nr_prajituri) {//este functie, nu metoda
	float greutate = 0;
	for(int p=0;p<nr_prajituri;p++)
	{
		greutate += prajituri[p].cantitate;

	}
    return greutate;
}

int main() {
	Prajitura p2("Amandina",40);//deschidem paranteza ca si cum am apela o metoda si ii dam variabilele
	p2.afisare();
	Prajitura p;
	p.afisare();//cand afisam o metoda dam mai intai obiectul;
	cout<<p.costMediuGram();
	Prajitura* prajituri;
	prajituri = new Prajitura[3];//se va apela constructorul implicit de 3 ori
	prajituri[2].afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;

	prajituri[0].modificaDenumire("tort");
	prajituri[1].modificaDenumire("ecler");
	for(int i=0;i<3;i++)
	{
		cout << prajituri[i].costMediuGram()<<endl;
	}

	for (int i = 0;i < 3;i++)
	{
		cout << prajituri[i].denumire<<' '<<prajituri[i].costMediuGram() << endl;
	}
	float greutate_totala = calculeazaCantitateaTotala(prajituri, 3);
	cout << "Total" << greutate_totala<<endl;

}
  
