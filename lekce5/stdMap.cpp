#include <iostream>
#include <map>
#include <string>

int main()
{

   char znak = '!';
   char specialniZnak = '@';

   std::cout << "Specialni znaky: " << znak
      << ", " << specialniZnak << std::endl;

   std::string textovyRetezec = "kus-textu,...";

   std::cout << "Textovy retezec: " << textovyRetezec
      << std::endl;

   std::map< std::string, int > indetifikatory;
   indetifikatory.insert( {"Uklizecka", 374642 } );
   indetifikatory.insert( {"Školník", 874642 } );

   for( auto dvojcie : indetifikatory ){
      std::cout << "Klic: " << dvojcie.first
         << ", ulozena hodnota: " << dvojcie.second
         << std::endl;
   }


   return 0;
}
