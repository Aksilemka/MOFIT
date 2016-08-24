/* Projekt C.7.4 (Bednarek) - Rozwiazywanie metoda roznicowa rownania Schrodingera z potencjałem Yukawy */

/*program ma policzyć wartości własne jak damy mu d i l
	d (stała ekranowania) zmienia się o 0<d<inf i jest to stała ekranowania, po prostu będziemy ją sobie podawać i tu nie ma problemu, 
	od niej zależy jak zmieniamy dro0, narazie nie wiem po co, ach dro0 jest po prostu parametrem w równaniu, zaraz zobaczymy co dalej
	wiemy jak zmieniać 0<d<inf
	
	l (liczba orbitalna) zależy od obranego n, przy czym n=1,2,3..., a l=0,...,n-1
	wiemy jak zmieniać n=1,2,3...,
	wiemy jak zmieniać l=0,...,n-1, gdy mamy dane n
	
	ro to nasz promień, a jak wiemy funkcje radialne oplatają os r przecinając ją kilka razy w zależności od l (fizyka)
	
	gdy wybierzemy wszystkie parametry l, d, ro0, to mamy znaleźć (wartości własne) lambda, te są określone przez miejsce, w którym 
	zmieni znak funkcja R(ro0), czyli mamy wszystko ustalone poza lambda, bierzemy lambda 1 i przepuszczamy R(ro0) przez 5000
	tys iteracji aby je znaleźć i chyba w każdej kolejnej iteracji musimy zwiększać dro0 i to o tu tu chodziło z tym całym syfem, 
	zapisujemy wartość, zwiększamy lammbda i przepuszamy znowu, tak obserwujemy aż nasz wynik zmieni
	znak, teraz trzeba jakość wznaczyć lambda dla którego funkcja jest równa 0, pomiędzy tymi dwoma co się zmienił znak,
	on mówi o jakichś specjlanych metodach, ale nie wiem czy podźwigniemy to inaczej niż np. średnia
	
	wiemy jak zmieniać lambda, zwiększamy o dl=1, chociaż można by zwiększać o coś dużego znaleźć miejsce zmiany, potem wokół
	niego dopiero zmieniać lambda o małe wartości, coś w stylu przetwornika ac
	wiemy jaką wartość początkową nadać lambda0=l+1
*/

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
//zaczynając od począku bierzemy liczbę n=1, dla tej liczby możliwe jest tylko l=0, czyli stan s. w kolejnych podejściach 
	//będziemy mieli n=2, wtedy l=0 lub l=1, dalej n=3, a l=0, l=1, l=2. dla takich pakietów będziemy szukać lambda(n,l)
	//mamy 5000 razy przepchać Ri przez pętlę aby ustalić wartość Ri dla obranych danych, nie wiem na ten moment kiedy to,
	//jest przypadek z energią zbliżającą się do 0, a wtedy trzeba zwiększyć liczbę iteracji. wydaje mi się, że energia zbliża
	//się do zera dla dużych ro0, czyli rozwiązanie funkcji radialnej jest bliskie 0
	
//obieramy jakieś ro0 przy ustalonym n, l i d. aby sprawdzić czy jest dobre zwiększamy ro0 o 10% i powtarzamy obliczenia.
//aby sprawdzić czy krok jest dobry, zmniejszamy go o 10% i liczymy. jeżeli trzy najniższe wartości własne zgadzają się co do kilku
//miejsc po przecinku dobrze wybraliśmy parametry.

//dla każdego powyższego oblieczenia mamy wyznaczyć wartości własne. wartości własne wyznaczamy tak, że dla wszystkich danych parametrów
//n, l , d, ro0 szukamy takiego lambda, że R(ro0) zmieni w tym punkcie znak. 


//potrzebne: jak ustalić pierwsze R i jak ustalić ro0, co jest opisane ale tu jeszce nie opisałem

	
//teraz obeiramy jakieś ro0, dla ustalonego d, l i n. liczymy Ri i szukamy wartości własnej, czyli to kolejna pętla
//teraz dodajemy coś do ro0 i liczymy kolejny raz.
//w kolejnych obliczeniach zwiększamy to co dodajemy do ro0 i chyba jednocześnie powoli zwiększamy liczbę kroków
		
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
