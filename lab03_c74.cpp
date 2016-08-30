/* Projekt C.7.4 (Bednarek) - Rozwiazywanie metoda roznicowa rownania Schrodingera z potencjałem Yukawy */


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>



using namespace std;

int main(){
//dane przypadku <------------------------------------------- tu zmieniamy!
	//nadajemy wartość l i d 
	int l = 1;				// orbitalna liczba kwantowa
	float d = 2.0;				// dlugosc ekranowania 
	//double ro0=?				// to jest miejsce w którym nasza funkcja ma się zerować, go też strzelamy na początku
	// potem przypisujemy lambda0=l+1, liczmy funkcje od R(ro0), dodajemy do lambda dlambda i czekamy aż zmieni znak
	
	int dL = 1;				// delta lambda
	int N = 10000;			// ilosc wezlow
	double dro = 0.008;		// dlugosc kroku iteracyjnego
	
//zmienne symulacji	
	double R0, R1, R2;		// funkcja falowa w R_{i-1}, R_{i}, R{i+1}
	double Ln, Lnp1;		// wartosc wlasna: lambda_{n}, lambda_{n+1}
	double ro; 				// numer iteracji

//przeliczenie zmiennych
	int L0 = l+1;


//zaczynamy
	cout<<"--------------------> ZACZYNAMY!"<<endl;
	
	ofstream plik1("lab03.out");	// nazwa: lab03_l-d-dL.out
	if(plik1.is_open()){
		cout<<"-> plik1 otwarty!"<<endl;
///////////////////////////////////////////////////////// OBSZAR DZIALANIA

		
		for(int i = 0; i < N; ++i){
            // rownanie roznicowe, sprawdzone, poprawne, po przejściu tej pętli mamy dostać rozwiązanie równania dla obranych danych
            //R2 = 1./(1+i)*( -R0*(i-1) + i*(2+0.25*dro*dro)*R1 + l*(l+1)/(double)i*R1 - lambda*dro*exp(-ro/d)*R1);
		
		
		
		
		}
		
		
///////////////////////////////////////////////////////// OBSZAR DZIALANIA		
        cout<<"-> plik1 zamkniety!"<<endl;
        plik1.close();
	} else{
		cerr << "Blad otwarcia pliku1";
	}



	return 0;
}
