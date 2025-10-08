#include <print>
#include <valarray>
#include <string>
#include <map> 

typedef std::valarray<double> state_t; 
typedef std::map<std::string, double> params_t;

void initial_conditions(state_t & s, double t0);
void print(const state_t & s, double t);
void derivada(const state_t & s, state_t & dsdt, double t, params_t & p);
template <class deriv_t, class s_t, class print_t>
void rugenk(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer);

int main(void)
{
  int N = 3; 
  state_t S(N);
  params_t params;
  params["sigma"] = 10;
  params["rho"] = 28;
  params["beta"] = 8/3;

  initial_conditions(S, 0);
  rugenk(derivada, S, 0, 10, 0.01, params, print);
  
  return 0;
}


void derivada(const state_t & s, state_t & dsdt, double t, params_t & params)
{
  dsdt[0] = params["sigma"]*(s[1]-s[0]);
  dsdt[1] = s[0]*(params["rho"]-s[2]) - s[1];
  dsdt[2] = s[0]*s[1] - params["beta"]*s[2];
}

void initial_conditions(state_t & s, double t0)
{
  s[0] = 10;
  s[1] = 1;
  s[2] = 1;
}

void print(const state_t & s, double t)
{
  std::println("{:25.16e} {:25.16e} {:25.16e} {:25.16e}", t, s[0], s[1],s[2]);
}

template <class deriv_t, class s_t, class print_t>
void rugenk(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer)
{


  state_t k1(s.size()), k2(s.size()), k3(s.size()), k4(s.size());
  for(double t = tinit; t <= tend; t = t + dt) { 

    deriv(s, k1, t, params);
    deriv(s + (dt/2.0)*k1, k2, t + (dt/2.0), params);
    deriv(s + (dt/2.0)*k2, k3, t + (dt/2.0), params);
    deriv(s + dt*k3, k4, t + dt, params);

    s = s + (dt/6.0)*(k1+ 2.0*k2 + 2.0*k3 + k4);

    // write new state
    writer(s, t);
  }
}
