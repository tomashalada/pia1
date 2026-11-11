#include <exception>
#include <iostream>
#include <vector>

class Parameters
{
public:

   // KONSTRUKTOR - funkce, ktera se vola kdyz "vznika" instance tridy
   Parameters() = default;
   Parameters( float dx_input, float velocity_input, float CFL_input )
   {
      std::cout << "Třída parametry byla vytvořena S argumentů" << std::endl;
      dx = dx_input;
      setDt( velocity_input, CFL_input );
      //...
   }

   // DESTRUKTOR - funkce, ktera se vola, kdyz instance zdanika
   ~Parameters()
   {
      std::cout << "Objekt tridy parametry zanikl." << std::endl;
   }

   // METODY TRIDI
   void setDx( float dx_input );
   float getDx();
   void setDt( float velocity, float CFL );
   float getDt();

private:
  float dx;
  float dt;

  float velocity;
  float CFL;
};

void Parameters::setDx( float dx_input )
{
   dx = dx_input;
}

float Parameters::getDx()
{
   return dx;
}
void Parameters::setDt( float velocity, float CFL)
{
   dt = CFL * 0.5 * dx / velocity;
   this->velocity = velocity;
   this->CFL = CFL;
}

float Parameters::getDt()
{
   return dt;
}



int main(){

   int a;
   a = 3;

   //Parameters myParams;
   //Parameters mySecondParams( 0.1, 1, 0.25 );
   //std::cout << "Dx je: " << mySecondParams.getDx() << std::endl;

   //myParams.setDx( 0.1 );
   //std::cout << "Dx je: " << myParams.getDx() << std::endl;
   //myParams.setDt( 1,  0.25 );

   fce();
   std::cout << "Program pokracuje" << std::endl;

   return 0;
}
