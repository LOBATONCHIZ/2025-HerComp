#include <print>
#include <vector>
#include <map>

typedef std::valarray<double> vala;
typedef std::map<std::string,double> params;



params["G"]= 9.81;

void derivada(double t,const vala&s, vala&dsdt){
	dsdt[0]= s[1];
	dsdt[1]= -params["K"]*s[];
	writer
}

template<class deriv_t, class writer_t> 
void integrate_euler(double t0,double tf, double dt, vala&s, deriv_t derivada, writer_t writer){
	derivada(t,s,dsdt);
	for (t=t0;t<=tf;t=t+dt)
		s=s+dt*dsdt;
	writer(t,s);
}

void inicond(vala & s, double t0);

int main(){
	std::valarray()
	

}
