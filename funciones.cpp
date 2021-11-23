#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define color SetConsoleTextAttribute
#include "funciones.h"

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    hCon= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}
void pintar()
{
    ///lineas orizontales
    for(int x=2; x<105; x++)
    {
        gotoxy (x,3);
        printf("%c",205);
        gotoxy (x,10);
        printf("%c",205);
    }
    ///lineas verticales
    for(int x=4; x<10; x++)
    {
        gotoxy (2,x);
        printf("%c",186);
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
        color(hConsole,x);
        cout<<"                    REVENGE          REVENGE          REVENGE          REVENGE        ";
        color(hConsole,7);
        gotoxy (104,x);
        printf("%c",186);
    }
    ///esquinas
    gotoxy(2,3);
    printf("%c",201);
    gotoxy(2,10);
    printf("%c",200);
    gotoxy(104,3);
    printf("%c",187);
    gotoxy(104,10);
    printf("%c",188);
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<"                  ------------------------  PRESIONE ENTER  ------------------------";
}
void opcionMenu();
void lanzarDados12(int V12[],int cantdado)
{
    for(int x=0; x<cantdado; x++)
    {
        V12[x]= 1+ rand()%12;
    }
}
void lanzarDados(int V6[],int cantdado)
{
    for(int x=0; x<cantdado; x++)
    {
        V6[x]= 1+ rand()%6;
    }
}
void mostrarDados(int V[],int cantdado)
{
    for (int x=0; x<cantdado; x++)
    {
        cout<<V[x]<<" ";
    }
}
int sumarDados(int V[],int cant)
{
    int x, suma=0;
    for(x=0; x<cant; x++)
    {
        suma+=V[x];
    }
    return suma;
}
int mostrarDadosj1(int V[],int cant)
{
    int dado1=0;
    for (int x=0; x<cant; x++)
    {
        dado1+=V[x];
        cout<<dado1<<" ";
    }
    return dado1;
}
int mostrarDadosj2(int V[],int cant)
{
    int dado2=0;
    for (int x=0; x<cant; x++)
    {
        dado2+=V[x];
        cout<<dado2<<" ";
    }
    return dado2;
}
int DADOS_SELECCIONADOR(int v[],int dadoStock)
{
    ///ESTA ES PARA QUE TE TOME LA POSICION Y NO EL VALOR INGRESADO
    int n,na, con=0;
    cout<<"Seleccione los dados a sumar(cero para finalizar): "<<endl;
    cin>>n;
    while(n!=0)
    {
        if(n>=1&&n<=dadoStock&&n!=na)
        {
            v[con]=n;
            con++;
            na=n;
        }
        else
        {
            cout<<"Ingrese un numero del 1 al "<<dadoStock<<"."<<endl;
        }
        cin>>n;
    }
    return con;
}
int SUMAR(int v[], int v2[],int tam2)
{
    ///SUMA EL VALOR DE LOS DADOS ELEGIDOS
    int acu=0;
    for(int x=0; x<tam2; x++)
    {
        acu+=v[v2[x]-1];
    }
    return acu;
}
void TIRADA_EXITOSA_J1(int SUMA_SELECCIONADA,int CANTIDAD_DADOS_ELEGIDOS,int& dadoStock1,int& dadoStock2,int& SCORE1)
{
    ///TE DA EL PUNTAJE Y LE DA LOS DADOS USADOS AL OTRO
    SCORE1+=(SUMA_SELECCIONADA*CANTIDAD_DADOS_ELEGIDOS);
    dadoStock1-=CANTIDAD_DADOS_ELEGIDOS;
    dadoStock2+=CANTIDAD_DADOS_ELEGIDOS;
}
void TIRADA_EXITOSA_J2(int SUMA_SELECCIONADA2,int CANTIDAD_DADOS_ELEGIDOS2,int& dadoStock1,int& dadoStock2,int& SCORE2)
{
    ///TE DA EL PUNTAJE Y LE DA LOS DADOS USADOS AL OTRO
    SCORE2+=(SUMA_SELECCIONADA2*CANTIDAD_DADOS_ELEGIDOS2);
    dadoStock1+=CANTIDAD_DADOS_ELEGIDOS2;
    dadoStock2-=CANTIDAD_DADOS_ELEGIDOS2;
}
void TIRADA_EXITOSA_J1TRAMPA(int SUMA_SELECCIONADA,int CANTIDAD_DADOS_ELEGIDOS,int& SCORE1)
{
    ///TE DA EL PUNTAJE
    SCORE1+=(SUMA_SELECCIONADA*CANTIDAD_DADOS_ELEGIDOS);
}
void TIRADA_EXITOSA_J2TRAMPA(int SUMA_SELECCIONADA2,int CANTIDAD_DADOS_ELEGIDOS2,int& SCORE2)
{
    ///TE DA EL PUNTAJE
    SCORE2+=(SUMA_SELECCIONADA2*CANTIDAD_DADOS_ELEGIDOS2);
}
void PONER_CERO(int v[],int tam)
{
    for(int x=0; x<tam; x++)
    {
        v[x]=0;
    }
}
