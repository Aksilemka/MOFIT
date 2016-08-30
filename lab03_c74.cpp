/* Projekt C.7.4 (Bednarek) - Rozwiazywanie metoda roznicowa rownania Schrodingera z potencjałem Yukawy */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

const double ro_zero = 0.5;
const double delta_ro = 0.008;
const double d = 0.005;
const double delta_lambda = 0.001;

double liczeR(double ro, double delta_ro, double d, int l, double lambda){
    double R1 = delta_ro*delta_ro;
    double R0 = 0, R2;
    
    ofstream plik1("lab03.out");	// nazwa: lab03_l-d-dL.out
    if(plik1.is_open()){
    
    for (int i = 2; i < 20000; i++) {
        R2 = 1./(1+i)*( -R0*(i-1) + i*(2+0.25*delta_ro*delta_ro)*R1 + l*(l+1)/(double)i*R1 - lambda*delta_ro*exp(-ro/d)*R1);
        R0 = R1;
        R1 = R2;
        
        plik1 << i << "\t" << R2 << endl;
        
    }
    
        plik1.close();
    }
    
    return R2;
}


double countEagenValue(int l){
    double eagenvalue;
    double lambda_zero = l+1;
    double R1;
    double R2;
    int i = 1;
    do{
        R1 = liczeR(ro_zero,delta_ro, d, l, lambda_zero + (i-1)*delta_lambda);
        R2 = liczeR(ro_zero,delta_ro, d, l, lambda_zero + i*delta_lambda);
        cout << R1 << " " << R2 << " " << endl;
        i++;
    } while(R1*R2<0 && R1!=0 && R2!=0);
    
    cout << R1 << " " << R2 << " " << endl;
    return eagenvalue;
}



int main(){
//dane przypadku <------------------------------------------- tu zmieniamy!
//	int l = 1;				// orbitalna liczba kwantowa
//	float d = 2.0;			// dlugosc ekranowania 
//	int dL = 1;				// delta lambda
//	int N = 10000;			// ilosc wezlow
//	double dro = 0.008;		// dlugosc kroku iteracyjnego
//	
////zmienne symulacji	
//	double R0, R1, R2;		// funkcja falowa w R_{i-1}, R_{i}, R{i+1}
//	double Ln, Lnp1;		// wartosc wlasna: lambda_{n}, lambda_{n+1}
//	double ro; 				// numer iteracji
//
////przeliczenie zmiennych
//	int L0 = l+1;


//zaczynamy
	cout<<"--------------------> ZACZYNAMY!"<<endl;
	
	ofstream plik1("lab03.out");	// nazwa: lab03_l-d-dL.out
	if(plik1.is_open()){
		cout<<"-> plik1 otwarty!"<<endl;
///////////////////////////////////////////////////////// OBSZAR DZIALANIA
        countEagenValue(1);
        //plik1 <<  <<
        
        
		
		
///////////////////////////////////////////////////////// OBSZAR DZIALANIA		
        cout<<"-> plik1 zamkniety!"<<endl;
        plik1.close();
	} else{
		cerr << "Blad otwarcia pliku1";
	}



	return 0;
}
