#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm> // Incluir la biblioteca para std::remove_if()
#include <cctype> // Incluir la biblioteca para std::isdigit()
#include <pthread.h>
#include <time.h>
using namespace std;

int main() {
    clock_t start = clock();
    std::ifstream inputfile = std::ifstream("supermercado.csv");
    int montint = 1;

    std::string line;
    long long int summontomes1=0;
    long long int summontomes2=0.00;
    long long int summontomes3=0.00;
    long long int summontomes4=0.00;
    long long int summontomes5=0.00;
    long long int summontomes6=0.00;
    long long int summontomes7=0.00;
    long long int summontomes8=0.00;
    long long int summontomes9=0.00;
    long long int summontomes10=0.00;
    long long int summontomes11=0.00;
    long long int summontomes12=0.00;
    long long int sumadescmes1=0;
    long long int sumadescmes2=0.00;
    long long int sumadescmes3=0.00;
    long long int sumadescmes4=0.00;
    long long int sumadescmes5=0.00;
    long long int sumadescmes6=0.00;
    long long int sumadescmes7=0.00;
    long long int sumadescmes8=0.00;
    long long int sumadescmes9=0.00;
    long long int sumadescmes10=0.00;
    long long int sumadescmes11=0.00;
    long long int sumadescmes12=0.00;
    int i = 0;
    int contm1=0;
    int contm2=0;
    int contm3=0;
    int contm4=0;
    int contm5=0;
    int contm6=0;
    int contm7=0;
    int contm8=0;
    int contm9=0;
    int contm10=0;
    int contm11=0;
    int contm12=0;
    long long int s=0;


    std::getline(inputfile, line); // Omitir la primera línea (encabezado)
    while(!inputfile.eof())

    {
        std::string line;
        std::getline(inputfile, line);//descarta pruimera linea que es el encabezado

        std::stringstream stream(line);

        std::string word, sku, nombre, monto, descuento, fecha,estado;


        std::getline(stream, sku, ';');//; es el delimitador get line lee el archivo hasta el delimitador coma
        std::getline(stream, nombre, ';');
        std::getline(stream, monto, ';');
        std::getline(stream, descuento, ';');
        std::getline(stream, fecha, ';');
        std::getline(stream, estado, ';');
        //nombre.erase(std::remove(nombre.begin(), nombre.end(), ';'), nombre.end());



        monto.erase(std::remove_if(monto.begin(), monto.end(), [](unsigned char c) { return !std::isdigit(c); }), monto.end());
        int montoInt = std::atoi(monto.c_str());
        descuento.erase(std::remove_if(descuento.begin(), descuento.end(), [](unsigned char c) { return !std::isdigit(c); }), descuento.end());
        int descInt = std::atoi(descuento.c_str());
        //cout << "sumamonto:"<< montoInt << endl;
        //cout << "fecha:" << fecha[7]<<endl;

        if(estado== "\"FINALIZED\""|| estado== "\"AUTHORIZED\"" ){
            //cout << "sumamonto:"<< summonto << endl;
            //cout << "sumamonto:"<< montoInt << endl;
            if(fecha[6]=='0'&&fecha[7]=='1'){
                summontomes1= montoInt+summontomes1;
                sumadescmes1= descInt+sumadescmes1;
                contm1++;

                //cout << "mes1: "<< summontomes1<<endl;
                //cout << "desmes1: "<< sumadescmes1<<endl;
            }
            if(fecha[6]=='0'&&fecha[7]=='2'){
                summontomes2= montoInt+summontomes2;
                sumadescmes2= descInt+sumadescmes2;
                //cout << "mes2: "<< summontomes2<<endl;
                contm2++;
            }
            if(fecha[6]=='0'&&fecha[7]=='3'){
                summontomes3= montoInt+summontomes3;
                sumadescmes3= descInt+sumadescmes3;
                //cout << "mes3: "<< summontomes3<<endl;
                contm3++;
                //if (i>1992299){
                    //cout << "Cont:" << i << "\tnombre"<< nombre<< "\tMonto" << montoInt<< "\tDescuento"<<descInt  << "\tFECHA:" << fecha << "\tESTADO:" << estado << std::endl;
                 //   cout << line << endl;
                //    cout<< "sumamonto"<< summontomes3<<endl;
               // }
            }
            if(fecha[6]=='0'&&fecha[7]=='4'){
                summontomes4= montoInt+summontomes4;
                sumadescmes4= descInt+sumadescmes4;
                //cout << "mes3: "<< summontomes3<<endl;
                contm4++;
            }
            if(fecha[6]=='0'&&fecha[7]=='5'){
                summontomes5= montoInt+summontomes5;
                sumadescmes5= descInt+sumadescmes5;
                //cout << "mes3: "<< summontomes3<<endl;
                contm5++;
            }
            if(fecha[6]=='0'&&fecha[7]=='6'){
                summontomes6= montoInt+summontomes6;
                sumadescmes6= descInt+sumadescmes6;
                //cout << "mes3: "<< summontomes3<<endl;
                contm6++;
            }
            if(fecha[6]=='0'&&fecha[7]=='7'){
                summontomes7= montoInt+summontomes7;
                sumadescmes7= descInt+sumadescmes7;
                //cout << "mes3: "<< summontomes3<<endl;
                contm7++;
            }
            if(fecha[6]=='0'&&fecha[7]=='8'){
                summontomes8= montoInt+summontomes8;
                sumadescmes8= descInt+sumadescmes8;
                //cout << "mes3: "<< summontomes3<<endl;
                contm8++;
            }
            if(fecha[6]=='0'&&fecha[7]=='9'){
                summontomes9= montoInt+summontomes9;
                sumadescmes9= descInt+sumadescmes9;
                //cout << "mes3: "<< summontomes3<<endl;
                contm9++;
            }
            if(fecha[6]=='1'&&fecha[7]=='0'){
                summontomes10= montoInt+summontomes10;
                sumadescmes10= descInt+sumadescmes10;
                //cout << "mes3: "<< summontomes3<<endl;
                contm10++;
            }
            if(fecha[6]=='1'&&fecha[7]=='1'){
                summontomes11= montoInt+summontomes11;
                sumadescmes11= descInt+sumadescmes11;
                //cout << "mes3: "<< summontomes3<<endl;
                contm11++;
            }
            if(fecha[6]=='1'&&fecha[7]=='2'){
                summontomes12= montoInt+summontomes12;
                sumadescmes12= descInt+sumadescmes12;
                //cout << "mes3: "<< summontomes3<<endl;
                contm12++;
            }




         //float c = (float)summontomes1 / 3;
         //cout << "mes1: "<< summontomes1<<endl;
         //cout << "descuento: "<< sumadescmes1 <<endl;
         i++;

        }
   s++;
        //std::cout << "Cont:" << i << "\tMonto" << montoInt<< "\tDescuento"<<descInt  << "\tFECHA:" << fecha << "\tESTADO:" << estado << std::endl;

    }
   long long int totalcomprado = 0;
   float a=0.00;
   a= totalcomprado/contm1;
   float tasainflacion12 = 0.00;
   float tasainflacion2 = 0.00;
   float tasainflacion3 = 0.00;
   float tasainflacion4 = 0.00;
   float tasainflacion5 = 0.00;
   float tasainflacion6 = 0.00;
   float tasainflacion7 = 0.00;
   float tasainflacion8 = 0.00;
   float tasainflacion9 = 0.00;
   float tasainflacion10 = 0.00;
   float tasainflacion11 = 0.00;
   //ipcbase = (float)totalcomprado;
   //totalcomprado = summontomes1+sumadescmes1;
   totalcomprado = summontomes1-sumadescmes1;
   float ipcbase = (static_cast<float>(totalcomprado)/static_cast<float>(totalcomprado))*100 ;// totalmesactual/totalmesbase*100
   cout << "mes1: "<< summontomes1<<endl;
   cout << "descuentomes1: "<< sumadescmes1 <<endl;
   cout << "totalcomprado: "<< totalcomprado <<endl;
   cout << "ipcbase: "<< ipcbase <<endl;
   cout << "cantidad: "<< a <<endl;


   long long int totalcomprado2=0;
   //totalcomprado2 = summontomes2-sumadescmes2;
   totalcomprado2 = summontomes2-sumadescmes2;
   float ipcbase2 = (static_cast<float>(totalcomprado2)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion2 = ((ipcbase2 - ipcbase)/ipcbase)*100;
   //float value = floor(tasainflacion * 100) / 100;
   cout << "mes2: "<< summontomes2<<endl;
   cout << "descuentomes2: "<< sumadescmes2 <<endl;
   cout << "total comprado: "<< totalcomprado2 <<endl;
   cout << "ipcbase2: "<< ipcbase2 <<endl;
   cout << "tasainflacionmes2: "<< tasainflacion2 <<endl;
   cout << "cantidad: "<< contm2 <<endl;

   long long int totalcomprado3=0;
   //totalcomprado3 = summontomes3sumadescmes3;
   totalcomprado3 = summontomes3-sumadescmes3;
   float ipcbase3 = (static_cast<float>(totalcomprado3)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion3= ((ipcbase3 - ipcbase2)/ipcbase2)*100;
   cout << "mes3: "<< summontomes3<<endl;
   cout << "descuentomes3: "<< sumadescmes3 <<endl;
   cout << "totalcomprado3: "<< totalcomprado3 <<endl;
   cout << "ipcbase3: "<< ipcbase3 <<endl;
   cout << "tasainflacionmes3: "<< tasainflacion3 <<endl;
   cout << "cantidad: "<< contm3 <<endl;

   long long int totalcomprado4=0;
   //totalcomprado4 = summontomes4-sumadescmes4;
   totalcomprado4 = summontomes4-sumadescmes4;
   float ipcbase4 = (static_cast<float>(totalcomprado4)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion4= ((ipcbase4 - ipcbase3)/ipcbase3)*100;
   cout << "mes4: "<< summontomes4<<endl;
   cout << "descuentomes4: "<< sumadescmes4 <<endl;
   cout << "totalcomprado4: "<< totalcomprado4 <<endl;
   cout << "ipcbase4: "<< ipcbase4 <<endl;
   cout << "tasainflacionmes4: "<< tasainflacion4 <<endl;
   cout << "cantidad: "<< contm4 <<endl;

   long long int totalcomprado5=0;
   //totalcomprado5 = summontomes5-sumadescmes5;
   totalcomprado5 = summontomes5-sumadescmes5;
   float ipcbase5 = (static_cast<float>(totalcomprado5)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion5= ((ipcbase5 - ipcbase4)/ipcbase4)*100;
   cout << "mes5: "<< summontomes5<<endl;
   cout << "descuentomes5: "<< sumadescmes5 <<endl;
   cout << "totalcomprado5: "<< totalcomprado5 <<endl;
   cout << "ipcbase5: "<< ipcbase5 <<endl;
   cout << "tasainflacionmes5: "<< tasainflacion5 <<endl;
   cout << "cantidad: "<< contm5 <<endl;

   long long int totalcomprado6=0;
   //totalcomprado6 = summontomes6-sumadescmes6;
   totalcomprado6 = summontomes6-sumadescmes6;
   float ipcbase6 = (static_cast<float>(totalcomprado6)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion6= ((ipcbase6 - ipcbase5)/ipcbase5)*100;
   cout << "mes6: "<< summontomes6<<endl;
   cout << "descuentomes6: "<< sumadescmes6 <<endl;
   cout << "totalcomprado6: "<< totalcomprado6 <<endl;
   cout << "ipcbase6: "<< ipcbase6 <<endl;
   cout << "tasainflacionmes6: "<< tasainflacion6 <<endl;
   cout << "cantidad: "<< contm6 <<endl;

   long long int totalcomprado7=0;
   //totalcomprado7 = summontomes7-sumadescmes7;
   totalcomprado7 = summontomes7-sumadescmes7;
   float ipcbase7 = (static_cast<float>(totalcomprado7)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion7= ((ipcbase7 - ipcbase6)/ipcbase6)*100;
   cout << "mes7: "<< summontomes7<<endl;
   cout << "descuentomes7: "<< sumadescmes7 <<endl;
   cout << "totalcomprado7: "<< totalcomprado7 <<endl;
   cout << "ipcbase7: "<< ipcbase7 <<endl;
   cout << "tasainflacionmes7: "<< tasainflacion7 <<endl;
   cout << "cantidad: "<< contm7 <<endl;

   long long int totalcomprado8=0;
   //totalcomprado8 = summontomes8-sumadescmes8;
   totalcomprado8 = summontomes8-sumadescmes8;
   float ipcbase8 = (static_cast<float>(totalcomprado8)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion8= ((ipcbase8 - ipcbase7)/ipcbase7)*100;
   cout << "mes8: "<< summontomes8<<endl;
   cout << "descuentomes8: "<< sumadescmes8 <<endl;
   cout << "totalcomprado8: "<< totalcomprado8 <<endl;
   cout << "ipcbase8: "<< ipcbase8 <<endl;
   cout << "tasainflacionmes8: "<< tasainflacion8 <<endl;
   cout << "cantidad: "<< contm8 <<endl;

   long long int totalcomprado9=0;
   //totalcomprado9 = summontomes9-sumadescmes9;
   totalcomprado9 = summontomes9-sumadescmes9;
   float ipcbase9 = (static_cast<float>(totalcomprado9)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion9= ((ipcbase9 - ipcbase8)/ipcbase8)*100;
   cout << "mes9: "<< summontomes9<<endl;
   cout << "descuentomes9: "<< sumadescmes9 <<endl;
   cout << "totalcomprado9: "<< totalcomprado9 <<endl;
   cout << "ipcbase9: "<< ipcbase9 <<endl;
   cout << "tasainflacionmes9: "<< tasainflacion9 <<endl;
   cout << "cantidad: "<< contm9 <<endl;

   long long int totalcomprado10=0;
   //totalcomprado10 = summontomes10-sumadescmes10;
   totalcomprado10 = summontomes10-sumadescmes10;
   float ipcbase10 = (static_cast<float>(totalcomprado10)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion10= ((ipcbase10 - ipcbase9)/ipcbase9)*100;
   cout << "mes10: "<< summontomes10<<endl;
   cout << "descuentomes10: "<< sumadescmes10 <<endl;
   cout << "totalcomprado10: "<< totalcomprado10 <<endl;
   cout << "ipcbase10: "<< ipcbase10 <<endl;
   cout << "tasainflacionmes10: "<< tasainflacion10 <<endl;
   cout << "cantidad: "<< contm10 <<endl;

   long long int totalcomprado11=0;
   //totalcomprado11 = summontomes11-sumadescmes11;
   totalcomprado11 = summontomes11-sumadescmes11;
   float ipcbase11 = (static_cast<float>(totalcomprado11)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion11= ((ipcbase11 - ipcbase10)/ipcbase10)*100;
   cout << "mes11: "<< summontomes11<<endl;
   cout << "descuentomes11: "<< sumadescmes11 <<endl;
   cout << "totalcomprado11: "<< totalcomprado11 <<endl;
   cout << "ipcbase11: "<< ipcbase11 <<endl;
   cout << "tasainflacionmes11: "<< tasainflacion11 <<endl;
   cout << "cantidad: "<< contm11 <<endl;

   long long int totalcomprado12=0;
   //totalcomprado12 = summontomes12-sumadescmes12;
   totalcomprado12 = summontomes12-sumadescmes12;
   float ipcbase12 = (static_cast<float>(totalcomprado12)/static_cast<float>(totalcomprado))*100 ; // totalmesactual/totalmesbase*100
   tasainflacion12= ((ipcbase12 - ipcbase11)/ipcbase11)*100;
   cout << "mes12: "<< summontomes12<<endl;
   cout << "descuentomes12: "<< sumadescmes12 <<endl;
   cout << "totalcomprado12: "<< totalcomprado12 <<endl;
   cout << "ipcbase12: "<< ipcbase12 <<endl;
   cout << "tasainflacionmes12: "<< tasainflacion12 <<endl;
   cout << "cantidad: "<< contm12 <<endl;

   cout << "datos aprobados: "<< i <<endl;
   cout << "datos totales: "<< s <<endl;
   float iflacionf;
   float prueba;
   iflacionf = tasainflacion2+tasainflacion3+tasainflacion4+tasainflacion5+tasainflacion6+tasainflacion7+tasainflacion8+tasainflacion9+tasainflacion10+tasainflacion11+tasainflacion12;
   prueba= (tasainflacion12-tasainflacion2)/tasainflacion2;
   cout << "inflacion final: "<< iflacionf <<endl;

   clock_t end = clock();
   double elapsed = double(end - start)/CLOCKS_PER_SEC;
   cout << "tiempocpu: "<<  elapsed <<endl;
   return 0;
}


