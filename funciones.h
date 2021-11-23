#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void gotoxy(int x, int y);

void pintar();

void opcionMenu();

void lanzarDados12(int V12[],int cantdado);

void lanzarDados(int V6[],int cantdado);

void mostrarDados(int V[],int cantdado);

int sumarDados(int V[],int cant);

int mostrarDadosj1(int V[],int cant);

int mostrarDadosj2(int V[],int cant);

int DADOS_SELECCIONADOR(int v[],int dadoStock);

int SUMAR(int v[], int v2[],int tam2);

void TIRADA_EXITOSA_J1(int SUMA_SELECCIONADA,int CANTIDAD_DADOS_ELEGIDOS,int& dadoStock1,int& dadoStock2,int& SCORE1);

void TIRADA_EXITOSA_J2(int SUMA_SELECCIONADA2,int CANTIDAD_DADOS_ELEGIDOS2,int& dadoStock1,int& dadoStock2,int& SCORE2);

void TIRADA_EXITOSA_J1TRAMPA(int SUMA_SELECCIONADA,int CANTIDAD_DADOS_ELEGIDOS,int& SCORE1);

void TIRADA_EXITOSA_J2TRAMPA(int SUMA_SELECCIONADA2,int CANTIDAD_DADOS_ELEGIDOS2,int& SCORE2);

void PONER_CERO(int v[],int tam);


#endif // FUNCIONES_H_INCLUDED
