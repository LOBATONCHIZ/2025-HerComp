#include <print>
#include <fstream>
#include <cmat>

double sumup(int n);
double sumdown(int n);

int main(){
    std::ofstream fout("data.txt");

    for(int nmax =1; nmax< 1000000; nmax = 2*nmax){
        double resup = sumup(nmax);
        double resdown = sumdown(nmax);
        double diff = std::fabs(1- resup/resdown);
        std::println(fout,"{:13}{:25.16e}{:25.16e}{:25.16e}",nmax,sumup,sumdown,res)

        fout.close();

        return 0;
    }

}

double sumup(int n)
{
    double suma =0.0;
    for(int ii = 1; ii <= n; ii++){
        suma = suma + 1.0/ii;
    }
    return suma;
}

double sumdown(int n)
{
    double suma =0.0;
    for(int ii = 1; ii >= n; ii--){
        suma = suma + 1.0/ii;
    }
    return suma;
}