//
// Created by Marcin on 2016-09-07.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <sstream>


using namespace std;
const double basic_delta_ro = 0.008; //podstawowa wartosc sluzaca do obliczania delta_ro w zaleznosci od wielkosci ro

const int number_of_steps = 5000; //liczba iteracji

//funkcja pomocnicza do podmiany elementu stringa subject z search na replace
//uzywana do zamiany kropek w sringu nazwy wykresu
std::string ReplaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

//funkcja do plotowania wykresu Ri
//data_file_name - nazwa pliku z wartosciami
//plot_file_name - nazwa pliku z wykresem
void plotGraph(const string data_file_name, string plot_file_name){
    ostringstream gnuplot_command; //tworzymy stringa z komenda
    plot_file_name = ReplaceString(plot_file_name, ".", "_");//zamieniamy w nazwie kropki na podkreslniki
    plot_file_name = plot_file_name.append(".png"); //dodajemy rozszerzenie
    gnuplot_command << "gnuplot -p -e \"set term png; set output '" << plot_file_name << "';  plot '"
    << data_file_name << "'\""; //tworzymy komende


    cout << gnuplot_command.str().c_str() << endl;
    system(gnuplot_command.str().c_str());//rysujemy wykres w gnuplocie do pliku
}

//funkcja obliczajaca iteracyjnie Ri
double countR(double ro, double delta_ro, int l, double lambda, double d){
    double R[5000]; //tablica z wartosciami Ri
    string file="data.txt"; //plik do zapisu danych do wygenerowania wykresu
    std::ofstream ofs;
    ofs.open(file, std::ofstream::out | std::ofstream::trunc);
    R[0]=0;
    R[1]=delta_ro*delta_ro;
    for (int i = 2; i < number_of_steps; ++i) {//petla obliczajaca kolejne wartosci Ri
        R[i] = 1./((double)i+1.) * (-((double) i+1.)*R[i-2] + ((double)i*(2.+0.25*delta_ro*delta_ro) + (double)l*((double)l+1.)/(double)i - lambda*delta_ro*exp(-ro/d))*R[i-1]);;
        ofs << R[i] << endl; //zapisujemy wartosc do pliku
    }
    ofs.close();
    ostringstream parameters;
    //wypisanie parametrow na ekran
    parameters << "ro0_" << ro << "_delta_ro_" << delta_ro << "_l_" << l << "_lamda_" << lambda << "_d_" << d;

    plotGraph(file, parameters.str());
    return R[number_of_steps-1];
}


int main() {
    int l[]={1,3,4};
    double d[]={0.3, 2, 10, 1000};
    double ro0[]={1,5,10,15};
    double lambda[] = {1,2,3,4};

    //iterujemy kolejno po wartosciach (od petli najbardziej zewnetrznej): l, d, ro0, lambda
    for(int j = 0; j<3; j++){
        for (int k = 0; k<4; k++){
            for (int m =0; m<4; m++){
                for (int n = 0; n<4; n++){
                    double delta_ro;
                    if(d[k]<1){ //warunek z instrukcji dotyczacy delta_ro, nie
                        // zmienialem kroku na większy (0.024) tak jak pisal w instrukcji!!!
                        //Dalekozasiegowy „ogon” potencjalu kulombowskiego jest tlumiony eksponencjalnie dla
                        //duzych ρ, gdy zmodyfikowana dlugosc ekranowania jest mala. Z tego powodu przy
                        //rozwiazaniu numerycznym warto zastosowac zmienny krok: dla malych ρ krok powinien byc
                        //mniejszy niz dla duzych wartosci tej zmiennej.
                        //Byc moze ma to wplyw nie wiem!
                        delta_ro = basic_delta_ro*d[k]; //dla malych ro delta jest mnozona razy
                    } else {
                        delta_ro = basic_delta_ro;
                    }
                    countR(ro0[m], delta_ro, l[j], lambda[n], d[k]); //wyliczamy R
                }
            }
        }
    }
}