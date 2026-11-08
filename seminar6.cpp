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
	friend class Student;
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

	Prajitura& operator=(const Prajitura& P1) //operatorul egal(supraincarcarea unui operator) "=" este doar simbol;operator binar,are doar 2 operanzi
	{
		if (this != &P1)
		{
			this->cantitate = P1.cantitate;
			if (this->denumire != NULL)
			{
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(P1.denumire) + 1];
			strcpy(this->denumire, P1.denumire);
			this->dePost = P1.dePost;
			this->pret = P1.pret;
			this->nrIngrediente = P1.nrIngrediente;
			if (this->ingrediente != NULL)
			{
				delete[]this->ingrediente;
			}
			this->ingrediente = new string[this->nrIngrediente];
			for (int i = 0;i < P1.nrIngrediente;i++)
				this->ingrediente[i] = P1.ingrediente[i];
			return *this;
		}
	}
#pragma region getteri si setteri
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
#pragma endregion 

#pragma region operatori
	Prajitura operator+(const Prajitura& p) {
		Prajitura result = *this;
		result.pret = this->pret + p.pret;
		result.cantitate = this->cantitate + p.cantitate;
		return result;
	}

	string& operator[](int pozitie)//pentru ca am pus &se face modificarea corecta a lui p[1]cu frisca
	{
		if (pozitie >= 0 && pozitie < this->nrIngrediente)//corect si doar cu nrIngrediente
			return this->ingrediente[pozitie];
	}

	operator float()
	{
		return this->pret;
	}

	explicit operator int()//operator unar, primeste this si nu mai are neoie de parametri
	{
		return this->cantitate;
	}

	float operator()()
	{
		return this->costMediuGram();
	}

	float operator()(float TVA)// la operatorii functie se asigura polimorfismul prin nr de parametri SAU prin tipul parametrilor
	{
		return (this->pret + (this->pret * TVA)) / this->cantitate;
	}

	float operator()(int discount)
	{
		return (this->pret - (pret * (discount / 100.0))) / this->cantitate;
	}

	bool operator==(Prajitura prajitura)//operator binar
	{
		if (strcmp(this->denumire, prajitura.denumire) != 0);
		return false;
		if (this->cantitate != prajitura.cantitate)
			return false;
		if (this->dePost != prajitura.dePost)
			return false;
		if (this->nrIngrediente != prajitura.nrIngrediente)
			return false;
		return true;
	}

	Prajitura& operator-=(const Prajitura p)
	{
		if (this->pret > p.pret)
			this->pret = this->pret - p.pret;
		else
			this->pret = 0;
		return *this;
	}

	Prajitura operator+=(string ingredient)
	{
		string* aux = new string[this->nrIngrediente + 1];
		for (int i = 0;i < this->nrIngrediente;i++) {
			aux[i] = this->ingrediente[i];
		}
		aux[this->nrIngrediente] = ingredient;
		delete[] this->ingrediente;
		this->ingrediente = aux;
		this->nrIngrediente++;
		return *this;

	}
#pragma endregion

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
		return greutate;

	}
}
float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();
	return 0;
}

class Student {
private:
	string nume;
	Prajitura prajitura;
public:
	Student() {
		this->nume = "Eliza";

	}
	Student(string nume, Prajitura p)
	{
		this->nume = nume;
		this->prajitura = p;
	}
	string getNume() {
		return this->nume;
	}
	Prajitura getPrajitura() {
		return this->prajitura;

	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setPrajitura(Prajitura p) {
		this->prajitura = p;
	}
	float calculeazaNrTotalCalorii(float caloriiPerGram) {
		float nrTotal = caloriiPerGram * this->prajitura.getCantitate();
		return nrTotal;
	}
	void afiseazaMasa() {
		cout << this->nume << " mananca prajitura " << this->prajitura.denumire << endl;
	}
};



void main() {

	Prajitura p;
	p.afisare();
	//Prajitura* pp;//apelam prin intermediul unui obiect
	//(*pp).afisare();//apelam prin intermediul unui pointer dereferetiat
	//pp->afisare();
	Prajitura::getContor();
	Prajitura P1("ecler", 20.6);
	Student s1("Maria", P1);

	cout << p[1] << endl;
	p[1] = "Frisca";
	cout << p[1] << endl;
	float pret;
	pret = (float)P1;
	cout << "pret: " << pret << endl;
	int cantitate;
	cantitate = (int)P1;
	cout << "cantitate: " << cantitate << endl;
	cout << "pret per gram: " << P1() << endl;//prin intermediul obiectului am apelat acea functie
	cout << "Pret cu TVA per gram: " << P1(0.21f) << endl;//il vede double si am pus un float in coadapt a-l apela pe cel de float
	cout << "Pet cu discount per gram: " << P1(10) << endl;
	if (p == P1)
		cout << "Prajituri egale" << endl;
	else
		cout << "Prajituri diferite" << endl;
	p -= P1;
	cout << p.getPret() << endl;
	p += "faina";
	cout << p[3];
}