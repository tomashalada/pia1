#include  <iostream>
#include <cmath>
#include <fstream>
/*

Vstup: resime y' = y, y(0) = 1, na (0,1)
-resime numericky -> eulerovo schema
- y_new( x+h ) = y_old(x) + (1+h)



 */

int main ()
{
float y_exact = exp(1.0); // presna hodnota y(1) = e^1

    int number_of_h = 100; // pocet hodnot h
    float log_h_start = -1; // logaritmus z h
    float log_h_end = -8; // logaritmus z h
    float log_h_step = (log_h_end - log_h_start) / (number_of_h - 1); // krok logaritmu z h

    // otevrit soubor pro zapis
    std::ofstream my_file("data_presnosti.txt");
    bool is_my_file_really_open = my_file.is_open();

    if (!is_my_file_really_open)
    {
        std::cerr << "data_presnosti.txt is not open" << std::endl;
        exit (1);
    }

    // cyklus pres hodnoty h
    for (int i=1; i < number_of_h; i++)
    {
        

        float log_h = log_h_start +i*log_h_step; // logaritmus z h
        float h=std::pow(10, log_h);

        // vyresit rovnici y'=y, y(0) = 1
        // interval [0,1) - rozsekat na N dilku
        int N = (1.0 / h); 

        float y_num = 1.0; // pocatecni podminka y(0) = 1

        for (int j=0; j < N; j++)
        {
            y_num = y_num*(1+h); 
        }

        float chyba = std::fabs(y_num - y_exact);
        //--ZAPIS DO SOUBORU
        my_file << h << " " << chyba << std::endl;
    }
    
    // zavrit soubor
    std::cout << "Zaviram soubor" << std::endl;
    my_file.close();
    
}