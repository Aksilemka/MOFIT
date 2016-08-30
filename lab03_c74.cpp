/* Projekt C.7.4 (Bednarek) - Rozwiazywanie metoda roznicowa rownania Schrodingera z potencjałem Yukawy */


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;


const double ro_zero = 3000;
const double d = 2;
const double delta_lambda = 1;
const double delta_ro = 0.008;

const int number_of_steps = 5000;

double countR(double ro, double delta_ro, int l, double lambda, double d){
	double Ri=delta_ro*delta_ro;
	double Ri_plus_one;
	double Ri_minus_one=0;

	for (int i = 2; i < number_of_steps; ++i) {
		Ri_plus_one = 1./((double)i+1.) * (-((double) i+1.)*Ri_minus_one + ((double)i*(2.+0.25*delta_ro*delta_ro) + (double)l*((double)l+1.)/(double)i - lambda*delta_ro*exp(-ro/d))*Ri);
		Ri_minus_one = Ri;
		Ri=Ri_plus_one;
	}

	return Ri_plus_one;
}

double countEagenValue(double l){
	double lambda_zero = l+1;
	double R1, R2;
	double eagenvalue;
	int i=0;

	do{
		R1=countR(ro_zero, delta_ro, l, lambda_zero+delta_lambda*i, d);
		R2=countR(ro_zero, delta_ro, l, lambda_zero+delta_lambda*(i+1), d);
		i++;

	} while(R1*R2>0 && R1!=0 && R2!=0);
	return eagenvalue;
}

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
