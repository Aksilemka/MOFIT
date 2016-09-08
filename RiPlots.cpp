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
const double basic_delta_ro = 0.008;

const int number_of_steps = 5000;

std::string ReplaceString(std::string subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

void plotGraph(const string data_file_name, string plot_file_name){
    ostringstream gnuplot_command;
    plot_file_name = ReplaceString(plot_file_name, ".", "_");
    plot_file_name = plot_file_name.append(".png");
    gnuplot_command << "gnuplot -p -e \"set term png; set output '" << plot_file_name << "';  plot '"
    << data_file_name << "'\"";


    cout << gnuplot_command.str().c_str() << endl;
    system(gnuplot_command.str().c_str());
}

double countR(double ro, double delta_ro, int l, double lambda, double d){
    double Ri=delta_ro*delta_ro;
    double Ri_plus_one;
    double Ri_minus_one=0;
    double R[5000];
    string file="data.txt";
    std::ofstream ofs;
    ofs.open(file, std::ofstream::out | std::ofstream::trunc);
    R[0]=0;
    R[1]=Ri;
    for (int i = 2; i < number_of_steps; ++i) {
        Ri_plus_one = 1./((double)i+1.) * (-((double) i+1.)*Ri_minus_one + ((double)i*(2.+0.25*delta_ro*delta_ro) + (double)l*((double)l+1.)/(double)i - lambda*delta_ro*exp(-ro/d))*Ri);;
        Ri_minus_one = Ri;
        Ri=Ri_plus_one;
        R[i]=Ri;
        ofs << Ri << endl;
    }
    ofs.close();
    ostringstream parameters;
    parameters << "ro0_" << ro << "_delta_ro_" << delta_ro << "_l_" << l << "_lamda_" << lambda << "_d_" << d;

    plotGraph(file, parameters.str());
    return Ri_plus_one;
}


int main() {
    int l[]={1,3,4};
    double d[]={0.3, 2, 10, 1000};
    double ro0[]={1,5,10,15};
    double lambda[] = {1,2,3,4};

    for(int j = 0; j<3; j++){
        for (int k = 0; k<4; k++){
            for (int m =0; m<4; m++){
                for (int n = 0; n<4; n++){
                    double delta_ro;
                    if(d[k]<1){
                        delta_ro = basic_delta_ro*d[k];
                    } else {
                        delta_ro = basic_delta_ro;
                    }
                    countR(ro0[m], delta_ro, l[j], lambda[n], d[k]);
                }
            }
        }
    }
}