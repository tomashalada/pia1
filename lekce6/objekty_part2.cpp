#include <complex>
#include <iostream>

class Params
{
 public:
   int size_public;
   float dx_public;

   void print()
   {
      std::cout << "public variable: " << std::endl;
      std::cout << "size: " << size_public
         << " dx: " << dx_public << std::endl;
      std::cout << "private variable: " << std::endl;
      std::cout << "size: " << size_private
         << " dx: " << dx_private << std::endl;
   }

   void setSize( int size )
   {
      size_private = size;
   }

   int getSize()
   {
      return size_private;
   }

 private:
   int size_private;
   double dx_private;
};

int main(){

   Params mojeParametry;
   mojeParametry.size_public = 10;
   mojeParametry.setSize( 20 );

   mojeParametry.print();

   std::cout << "Get private variable: " << mojeParametry.getSize() << std::endl;

   return 0;
}
