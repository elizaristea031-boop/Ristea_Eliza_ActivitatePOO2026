#include<iostream>
using namespace std;
#include<cstring>

struct Cladire
{   
	char* culoare;
	float inaltime;
	int nrEtaje;
	bool deschis;

};
Cladire citireCladire()
{
	Cladire c;
	char x[100];
	cout << "Culoare:";
	cin >> x;
	c.culoare = new char[strlen(x) + 1];
	strcpy(c.culoare,x);
	cout << "\nInaltime:";
	cin >> c.inaltime;
	cout << "\nNr.etaje:";
	cin >> c.nrEtaje;
	cout << "\nDeschis(0/1):";
	cin >> c.deschis;
	return c;

}
void afisareCladire(Cladire c)
{

	cout << "Culoare:" << c.culoare;
	cout << "Inaltimea:" << c.inaltime;
	cout << " Etaje:" << c.nrEtaje;
	cout << "Deschis(0/1):" << c.deschis;

}
void modificaNrEtaje(int noulNrEtaje, Cladire *c)
{
	   
	(*c).nrEtaje = noulNrEtaje;



}
void modificaNrEtaje1(int noulNrEtaje, Cladire &c)
{

	c.nrEtaje = noulNrEtaje;



}
int main()
{

	Cladire c = citireCladire();
	afisareCladire(c);
	modificaNrEtaje(20,&c);
	afisareCladire(c);
	modificaNrEtaje1(21, c);
	afisareCladire(c);
	/*
	char* vectorC;
	vectorC = new char[strlen("POO") + 1];
	strcpy_s(vectorC, strlen("POO") + 1, "POO");


	Cladire c;
	int nrCladiri = 5;
	Cladire* cladiri;
	cladiri = new Cladire[nrCladiri];
    cladiri= (Cladire*)malloc(sizeof(Cladire)* nrCladiri); */
}