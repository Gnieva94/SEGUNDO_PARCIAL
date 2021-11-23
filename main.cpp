#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define color SetConsoleTextAttribute
#include "funciones.h"

using namespace std;

int main()
{
    srand(time(NULL));
    pintar();
    int opcionMenu, opcionVolver, maximoscore=0;
    string jugador1, jugador2, maximojugador;
    system("pause>nulls");
    system("cls");
    do
    {
        cout<<"   "<<endl;
        cout<<"-----------"<<endl;
        cout<<"1-JUGAR"<<endl;
        cout<<"2-ESTADISTICAS"<<endl;
        cout<<"3-CREDITOS"<<endl;
        cout<<"-----------"<<endl;
        cout<<"0-SALIR"<<endl;
        cin>>opcionMenu;
        switch (opcionMenu)
        {
        case 1:
        {
            int dadoStock1=6, dadoStock2=6, dado1=0, dado2=0, SCORE1=0, SCORE2=0, ronda;
            int VdadosJ1[dadoStock1], VdadosJ2[dadoStock2], Vdados12[2];
            PONER_CERO(VdadosJ1,dadoStock1);
            PONER_CERO(VdadosJ2,dadoStock2);
            PONER_CERO(Vdados12,2);
            system("cls");
            ///INGRESO DE NOMBRES
            cout<<"----------------- INGRESE NOMBRE DEL JUGADOR N*1 -----------------"<<endl;
            cin>>jugador1;
            cout<<endl;
            cout<<"----------------- INGRESE NOMBRE DEL JUGADOR N*2 -----------------"<<endl;
            cin>>jugador2;
            cout<<endl;
            system("cls");
            cout<<"--------------------- COMENCEMOS A JUGAR -------------------------"<<endl;
            ///CADA JUGADOR LANZA UN DADO PARA DECIDIR QUIEN EMPIEZA
            cout<<jugador1<<", LANCE UN DADO."<<endl;
            lanzarDados(VdadosJ1, dadoStock1);
            cout<<"SU DADO ES EL NUMERO: ";
            dado1=mostrarDadosj1(VdadosJ1,1);
            cout<<endl<<endl;
            cout<<jugador2<<", LANCE UN DADO."<<endl;
            lanzarDados(VdadosJ2, dadoStock2);
            cout<<"SU DADO ES EL NUMERO: ";
            dado2=mostrarDadosj2(VdadosJ2,1);
            cout<<endl;
            cout<<endl<<"PRESIONE ENTER PARA CONTINUAR..."<<endl;
            system("pause>nulls");

            if(dado1==dado2)
            {
                cout<<endl<<"PRESIONE ENTER PARA VOLVER A TIRAR."<<endl;
                system("pause>nulls");
                while(dado1==dado2)
                {
                    ///EN CASO DE EMPATE SE VUELVE A TIRAR
                    system("cls");
                    cout<<"------------------------- NUEVA TIRADA ---------------------------"<<endl;
                    cout<<jugador1<<", VUELVE A LANZAR UN DADO."<<endl;
                    lanzarDados(VdadosJ1, dadoStock1);
                    cout<<"SU DADO ES EL NUMERO: ";
                    dado1=mostrarDadosj1(VdadosJ1,1);
                    cout<<endl<<endl;
                    cout<<jugador2<<" VUELVE A LANZAR UN DADO"<<endl;
                    lanzarDados(VdadosJ2, dadoStock2);
                    cout<<"SU DADO ES EL NUMERO: ";
                    dado2=mostrarDadosj2(VdadosJ2,1);
                    cout<<endl<<endl;
                    system("pause>nulls");
                }
                cout<<"PRESIONE ENTER PARA INICIAR RONDA."<<endl;
                system("pause>nulls");
            }
            ///EMPIEZA JUGADOR 1
            if(dado1>dado2)
            {
                ronda=1;
                bool TRAMPA=false,TRAMPA2=false;
                bool INICIALTRAMPA=false,INICIALTRAMPA2=false,CARTELTRAMPA=false,CARTELTRAMPA2=false;
                system("cls");
                cout<<"------------------------ COMIENZA EL JUEGO -----------------------"<<endl;
                while(ronda!=6&&dadoStock1!=0&&dadoStock2!=0)
                {
                    cout<<"----------------------------- RONDA "<<ronda<<" ----------------------------"<<endl;
                    ///JUGADOR 1
                    ///LANZA DADOS DE 12 CARAS PARA DETERMINAR NUMERO OBJETIVO.
                    int VdadosJ1[dadoStock1], Dados_Elegidos[dadoStock1], cantDadosElegidos=0;
                    int nObjetivo=0;
                    int sumaSeleccionada=0;
                    int opcion,dadotrampa,nuevovalor;
                    bool penalizacionj1=false;
                    PONER_CERO(VdadosJ1,dadoStock1);
                    PONER_CERO(Dados_Elegidos,dadoStock1);
                    cout<<jugador1<<", LANZA DADOS DE 12 CARAS."<<endl;
                    lanzarDados12(Vdados12, 2);
                    cout<<"TUS NUMEROS SON: ";
                    mostrarDados(Vdados12,2);
                    nObjetivo=sumarDados(Vdados12,2);
                    cout<<endl<<endl;
                    cout<<"TU TIRADA Y NUMERO OBJETIVO ES DE: "<<nObjetivo<<endl<<endl;
                    cout<<"AHORA DEBES LANZAR TUS DADOS STOCK."<<endl;
                    lanzarDados(VdadosJ1, dadoStock1);
                    mostrarDados(VdadosJ1, dadoStock1);
                    cout<<endl<<endl;
                    if(!TRAMPA)
                    {
                        cout<<"DESEA REALIZAR TRAMPA?"<<endl;
                        cout<<"1)SI o 0)NO"<<endl;
                        cin>>opcion;
                        switch(opcion)
                        {
                        case 1:
                        {
                            if(!TRAMPA)
                            {
                                cout<<"CUAL DADO DESEAS MODIFICAR?"<<endl;
                                cin>>dadotrampa;
                                cout<<"DIGITE EL NUEVO VALOR."<<endl;
                                cin>>nuevovalor;
                                VdadosJ1[dadotrampa-1]=nuevovalor;
                                cout<<"TUS ''NUEVOS'' DADOS STOCK..."<<endl;
                                mostrarDados(VdadosJ1, dadoStock1);
                                TRAMPA=true;
                                jugador1="TRAMPOSO";
                            }
                        }
                        break;
                        }
                    }
                    cout<<endl<<endl;
                    cantDadosElegidos=DADOS_SELECCIONADOR(Dados_Elegidos, dadoStock1);
                    if(cantDadosElegidos>0)
                    {
                        sumaSeleccionada=SUMAR(VdadosJ1,Dados_Elegidos,cantDadosElegidos);
                    }
                    else
                    {
                        cout<<endl<<"NO UTILIZO DADOS."<<endl;
                        penalizacionj1=true;
                    }
                    cout<<endl<<"LA SUMA SELECCIONADA ES DE: "<<sumaSeleccionada<<endl<<endl;
                    if(sumaSeleccionada==nObjetivo)
                    {
                        if(TRAMPA==true&&INICIALTRAMPA==false)
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            TIRADA_EXITOSA_J1TRAMPA(sumaSeleccionada,cantDadosElegidos,SCORE1);
                            INICIALTRAMPA=true;
                        }
                        else
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            ///MULTIPLICAR SUMA SELECCIONADA * DADOS ELEGIDOS + TOTAL GENERADO EN RONDAS ANTERIORES
                            ///RESTAR DADOS ELEGIDOS DE DADOS STOCK Y ENVIAR AL RIVAL
                            TIRADA_EXITOSA_J1(sumaSeleccionada,cantDadosElegidos,dadoStock1,dadoStock2,SCORE1);
                        }
                    }
                    if(sumaSeleccionada!=nObjetivo||penalizacionj1==true)
                    {
                        cout<<"TIRADA NO EXITOSA. SE TE PENALIZA CON 1 DADO DEL RIVAL."<<endl<<endl;
                        dadoStock1++;
                        if(dadoStock2>1)
                        {
                            dadoStock2--;
                        }
                        if(TRAMPA)
                        {
                            INICIALTRAMPA=true;
                        }
                    }
                    cout<<endl;
                    cout<<"SCORE "<<jugador1<<": "<< SCORE1 << endl;
                    cout<<"DADOS STOCK EN POSESION: " << dadoStock1 << endl;
                    if(TRAMPA==true&&CARTELTRAMPA==false)
                    {
                        cout<<"DADOS STOCK PASADOS AL RIVAL: NUNGUNO TRAMPOSO!"<<endl;
                        CARTELTRAMPA=true;
                    }
                    else
                    {
                        if(cantDadosElegidos>0&&penalizacionj1==false)
                        {
                            cout<<"DADOS STOCK PASADOS AL RIVAL: " << cantDadosElegidos << endl;
                        }
                        else
                        {
                            if(penalizacionj1)
                            {
                                cout<<"DADOS STOCK PASADOS AL RIVAL: 0"<<endl;
                            }
                        }
                    }
                    cout<<endl<<"PRESIONE ENTER PARA CONTINUAR..."<<endl;
                    system("pause>nulls");
                    system("cls");
                    cout<<"----------------------------- RONDA "<<ronda<<" ----------------------------"<<endl;
                    ///JUGADOR 2
                    ///LANZA DADOS DE 12 CARAS PARA DETERMINAR NUMERO OBJETIVO.
                    int Dados_Elegidos2[dadoStock2], cantDadosElegidos2=0;
                    int nObjetivo2=0;
                    int sumaSeleccionada2=0;
                    int opcion2,dadotrampa2,nuevovalor2;
                    bool penalizacionj2=false;
                    PONER_CERO(VdadosJ2,dadoStock2);
                    PONER_CERO(Dados_Elegidos2,dadoStock2);
                    cout<<jugador2<<", LANZA DADOS DE 12 CARAS."<<endl;
                    lanzarDados12(Vdados12, 2);
                    cout<<"TUS NUMEROS SON: ";
                    mostrarDados(Vdados12,2);
                    nObjetivo2=sumarDados(Vdados12,2);
                    cout<<endl<<endl;
                    cout<<"TU TIRADA Y NUMERO OBJETIVO ES DE: "<<nObjetivo2<<endl<<endl;
                    cout<<"AHORA DEBES LANZAR TUS DADOS STOCK."<<endl;
                    lanzarDados(VdadosJ2, dadoStock2);
                    mostrarDados(VdadosJ2, dadoStock2);
                    cout<<endl<<endl;
                    if(!TRAMPA2)
                    {
                        cout<<"DESEA REALIZAR TRAMPA?"<<endl;
                        cout<<"1)SI o 0)NO"<<endl;
                        cin>>opcion2;
                        switch(opcion2)
                        {
                        case 1:
                        {
                            if(!TRAMPA2)
                            {
                                cout<<"CUAL DADO DESEAS MODIFICAR?"<<endl;
                                cin>>dadotrampa2;
                                cout<<"DIGITE EL NUEVO VALOR."<<endl;
                                cin>>nuevovalor2;
                                VdadosJ2[dadotrampa2-1]=nuevovalor2;
                                cout<<"TUS ''NUEVOS'' DADOS STOCK..."<<endl;
                                mostrarDados(VdadosJ2, dadoStock2);
                                TRAMPA2=true;
                                jugador2="TRAMPOSO";
                            }
                        }
                        break;
                        }
                    }
                    cout<<endl<<endl;
                    cantDadosElegidos2=DADOS_SELECCIONADOR(Dados_Elegidos2, dadoStock2);
                    if(cantDadosElegidos2>0)
                    {
                        sumaSeleccionada2=SUMAR(VdadosJ2,Dados_Elegidos2,cantDadosElegidos2);
                    }
                    else
                    {
                        cout<<endl<<"NO UTILIZO DADOS."<<endl;
                        penalizacionj2=true;
                    }
                    cout<<endl<<"LA SUMA SELECCIONADA ES DE: "<<sumaSeleccionada2<<endl<<endl;
                    if(sumaSeleccionada2==nObjetivo2)
                    {
                        if(TRAMPA2==true&&INICIALTRAMPA2==false)
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            TIRADA_EXITOSA_J2TRAMPA(sumaSeleccionada2,cantDadosElegidos2,SCORE2);
                            INICIALTRAMPA2=true;
                        }
                        else
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            ///MULTIPLICAR SUMA SELECCIONADA * DADOS ELEGIDOS + TOTAL GENERADO EN RONDAS ANTERIORES
                            ///RESTAR DADOS ELEGIDOS DE DADOS STOCK Y ENVIAR AL RIVAL
                            TIRADA_EXITOSA_J2(sumaSeleccionada2,cantDadosElegidos2,dadoStock1,dadoStock2,SCORE2);
                        }
                    }
                    if(sumaSeleccionada2!=nObjetivo2||penalizacionj2==true)
                    {
                        cout<<"TIRADA NO EXITOSA. SE TE PENALIZA CON 1 DADO DEL RIVAL."<<endl<<endl;
                        dadoStock2++;
                        if(dadoStock1>1)
                        {
                            dadoStock1--;
                        }
                        if(TRAMPA2)
                        {
                            INICIALTRAMPA2=true;
                        }
                    }
                    cout<<endl;
                    cout<<"SCORE "<<jugador2<<": "<< SCORE2 << endl;
                    cout<<"DADOS STOCK EN POSESION: " << dadoStock2 << endl;
                    if(TRAMPA2==true&&CARTELTRAMPA2==false)
                    {
                        cout<<"DADOS STOCK PASADOS AL RIVAL: NUNGUNO TRAMPOSO!"<<endl;
                        CARTELTRAMPA2=true;
                    }
                    else
                    {
                        if(cantDadosElegidos2>0&&penalizacionj2==false)
                        {
                            cout<<"DADOS STOCK PASADOS AL RIVAL: " << cantDadosElegidos2 << endl;
                        }
                        else
                        {
                            if(penalizacionj2)
                            {
                                cout<<"DADOS STOCK PASADOS AL RIVAL: 0"<<endl;
                            }
                        }
                    }
                    cout<<endl<<"PRESIONE ENTER PARA CONTINUAR..."<<endl;
                    ronda++;
                    system("pause>nulls");
                    system("cls");
                }
            }
            ///EMPIEZA JUGADOR 2
            if(dado2>dado1)
            {
                ronda=1;
                bool TRAMPA=false,TRAMPA2=false;
                bool INICIALTRAMPA=false,INICIALTRAMPA2=false,CARTELTRAMPA=false,CARTELTRAMPA2=false;
                system("cls");
                cout<<"------------------------ COMIENZA EL JUEGO -----------------------"<<endl;
                while(ronda!=6&&dadoStock1!=0&&dadoStock2!=0)
                {
                    cout<<"----------------------------- RONDA "<<ronda<<" ----------------------------"<<endl;
                    ///LANZA DADOS DE 12 CARAS PARA DETERMINAR NUMERO OBJETIVO.
                    ///JUGADOR 2
                    int Dados_Elegidos2[dadoStock2], cantDadosElegidos2=0;
                    int nObjetivo2=0;
                    int sumaSeleccionada2=0;
                    int opcion2,dadotrampa2,nuevovalor2;
                    bool penalizacionj2=false;
                    PONER_CERO(VdadosJ2,dadoStock2);
                    PONER_CERO(Dados_Elegidos2,dadoStock2);
                    cout<<jugador2<<", LANZA DADOS DE 12 CARAS."<<endl;
                    lanzarDados12(Vdados12, 2);
                    cout<<"TUS NUMEROS SON: ";
                    mostrarDados(Vdados12,2);
                    nObjetivo2=sumarDados(Vdados12,2);
                    cout<<endl<<endl;
                    cout<<"TU TIRADA Y NUMERO OBJETIVO ES DE: "<<nObjetivo2<<endl<<endl;
                    cout<<"AHORA DEBES LANZAR TUS DADOS STOCK."<<endl;
                    lanzarDados(VdadosJ2, dadoStock2);
                    mostrarDados(VdadosJ2,dadoStock2);
                    cout<<endl<<endl;
                    if(!TRAMPA2)
                    {
                        cout<<"DESEA REALIZAR TRAMPA?"<<endl;
                        cout<<"1)SI o 0)NO"<<endl;
                        cin>>opcion2;
                        switch(opcion2)
                        {
                        case 1:
                        {
                            if(!TRAMPA2)
                            {
                                cout<<"CUAL DADO DESEAS MODIFICAR?"<<endl;
                                cin>>dadotrampa2;
                                cout<<"DIGITE EL NUEVO VALOR."<<endl;
                                cin>>nuevovalor2;
                                VdadosJ2[dadotrampa2-1]=nuevovalor2;
                                cout<<"TUS ''NUEVOS'' DADOS STOCK..."<<endl;
                                mostrarDados(VdadosJ2, dadoStock2);
                                TRAMPA2=true;
                                jugador2="TRAMPOSO";
                            }
                        }
                        break;
                        }
                    }
                    cout<<endl<<endl;
                    cantDadosElegidos2=DADOS_SELECCIONADOR(Dados_Elegidos2, dadoStock2);
                    if(cantDadosElegidos2>0)
                    {
                        sumaSeleccionada2=SUMAR(VdadosJ2,Dados_Elegidos2,cantDadosElegidos2);
                    }
                    else
                    {
                        cout<<endl<<"NO UTILIZO DADOS."<<endl;
                        penalizacionj2=true;
                    }
                    cout<<endl<<"LA SUMA SELECCIONADA ES DE: "<<sumaSeleccionada2<<endl<<endl;
                    if(sumaSeleccionada2==nObjetivo2)
                    {
                        if(TRAMPA2==true&&INICIALTRAMPA2==false)
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            TIRADA_EXITOSA_J2TRAMPA(sumaSeleccionada2,cantDadosElegidos2,SCORE2);
                            INICIALTRAMPA2=true;
                        }
                        else
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            ///MULTIPLICAR SUMA SELECCIONADA * DADOS ELEGIDOS + TOTAL GENERADO EN RONDAS ANTERIORES
                            ///RESTAR DADOS ELEGIDOS DE DADOS STOCK Y ENVIAR AL RIVAL
                            TIRADA_EXITOSA_J2(sumaSeleccionada2,cantDadosElegidos2,dadoStock1,dadoStock2,SCORE2);
                        }
                    }
                    if(sumaSeleccionada2!=nObjetivo2||penalizacionj2==true)
                    {
                        cout<<"TIRADA NO EXITOSA. SE TE PENALIZA CON 1 DADO DEL RIVAL."<<endl<<endl;
                        dadoStock2++;
                        if(dadoStock1>1)
                        {
                            dadoStock1--;
                        }
                        if(TRAMPA2)
                        {
                            INICIALTRAMPA2=true;
                        }
                    }
                    cout<<endl;
                    cout<<"SCORE "<<jugador2<<": "<< SCORE2 << endl;
                    cout<<"DADOS STOCK EN POSESION: " << dadoStock2 << endl;
                    if(TRAMPA2==true&&CARTELTRAMPA2==false)
                    {
                        cout<<"DADOS STOCK PASADOS AL RIVAL: NUNGUNO TRAMPOSO!"<<endl;
                        CARTELTRAMPA2=true;
                    }
                    else
                    {
                        if(cantDadosElegidos2>0&&penalizacionj2==false)
                        {
                            cout<<"DADOS STOCK PASADOS AL RIVAL: " << cantDadosElegidos2 << endl;
                        }
                        else
                        {
                            if(penalizacionj2)
                            {
                                cout<<"DADOS STOCK PASADOS AL RIVAL: 0"<<endl;
                            }
                        }
                    }
                    cout<<endl<<"PRESIONE ENTER PARA CONTINUAR..."<<endl;
                    system("pause>nulls");
                    system("cls");
                    cout<<"----------------------------- RONDA "<<ronda<<" ----------------------------"<<endl;
                    ///JUGADOR 1
                    ///LANZA DADOS DE 12 CARAS PARA DETERMINAR NUMERO OBJETIVO.
                    int Dados_Elegidos[dadoStock1], cantDadosElegidos=0;
                    int nObjetivo=0;
                    int sumaSeleccionada=0;
                    int opcion,dadotrampa,nuevovalor;
                    bool penalizacionj1=false;
                    PONER_CERO(VdadosJ1,dadoStock1);
                    PONER_CERO(Dados_Elegidos,dadoStock1);
                    cout<<jugador1<<", LANZA DADOS DE 12 CARAS."<<endl;
                    lanzarDados12(Vdados12, 2);
                    cout<<"TUS NUMEROS SON: ";
                    mostrarDados(Vdados12,2);
                    nObjetivo=sumarDados(Vdados12,2);
                    cout<<endl<<endl;
                    cout<<"TU TIRADA Y NUMERO OBJETIVO ES DE: "<<nObjetivo<<endl<<endl;
                    cout<<"AHORA DEBES LANZAR TUS DADOS STOCK."<<endl;
                    lanzarDados(VdadosJ1, dadoStock1);
                    mostrarDados(VdadosJ1,dadoStock1);
                    if(!TRAMPA)
                    {
                        cout<<endl<<endl;
                        cout<<"DESEA REALIZAR TRAMPA?"<<endl;
                        cout<<"1)SI o 0)NO"<<endl;
                        cin>>opcion;
                        switch(opcion)
                        {
                        case 1:
                        {
                            if(!TRAMPA)
                            {
                                cout<<"CUAL DADO DESEAS MODIFICAR?"<<endl;
                                cin>>dadotrampa;
                                cout<<"DIGITE EL NUEVO VALOR."<<endl;
                                cin>>nuevovalor;
                                VdadosJ1[dadotrampa-1]=nuevovalor;
                                cout<<"TUS ''NUEVOS'' DADOS STOCK..."<<endl;
                                mostrarDados(VdadosJ1, dadoStock1);
                                TRAMPA=true;
                                jugador1="TRAMPOSO";
                            }
                        }
                        break;
                        }
                    }
                    cout<<endl<<endl;
                    cantDadosElegidos=DADOS_SELECCIONADOR(Dados_Elegidos, dadoStock1);
                    if(cantDadosElegidos>0)
                    {
                        sumaSeleccionada=SUMAR(VdadosJ1,Dados_Elegidos,cantDadosElegidos);
                    }
                    else
                    {
                        cout<<endl<<"NO UTILIZO DADOS."<<endl;
                        penalizacionj1=true;
                    }
                    cout<<endl<<"LA SUMA SELECCIONADA ES DE: "<<sumaSeleccionada<<endl<<endl;
                    if(sumaSeleccionada==nObjetivo)
                    {
                        if(TRAMPA==true&&INICIALTRAMPA==false)
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            TIRADA_EXITOSA_J1TRAMPA(sumaSeleccionada,cantDadosElegidos,SCORE1);
                            INICIALTRAMPA=true;
                        }
                        else
                        {
                            cout<<"TIRADA EXITOSA."<<endl;
                            ///MULTIPLICAR SUMA SELECCIONADA * DADOS ELEGIDOS + TOTAL GENERADO EN RONDAS ANTERIORES
                            ///RESTAR DADOS ELEGIDOS DE DADOS STOCK Y ENVIAR AL RIVAL
                            TIRADA_EXITOSA_J1(sumaSeleccionada,cantDadosElegidos,dadoStock1,dadoStock2,SCORE1);
                        }
                    }
                    if(sumaSeleccionada!=nObjetivo||penalizacionj1==true)
                    {
                        cout<<"TIRADA NO EXITOSA. SE TE PENALIZA CON 1 DADO DEL RIVAL."<<endl<<endl;
                        dadoStock1++;
                        if(dadoStock2>1)
                        {
                            dadoStock2--;
                        }
                        if(TRAMPA)
                        {
                            INICIALTRAMPA=true;
                        }
                    }
                    cout<<endl;
                    cout<<"SCORE "<<jugador1<<": "<< SCORE1 << endl;
                    cout<<"DADOS STOCK EN POSESION: " << dadoStock1 << endl;
                    if(TRAMPA==true&&CARTELTRAMPA==false)
                    {
                        cout<<"DADOS STOCK PASADOS AL RIVAL: NUNGUNO TRAMPOSO!"<<endl;
                        CARTELTRAMPA=true;
                    }
                    else
                    {
                        if(cantDadosElegidos>0&&penalizacionj1==false)
                        {
                            cout<<"DADOS STOCK PASADOS AL RIVAL: " << cantDadosElegidos << endl;
                        }
                        else
                        {
                            if(penalizacionj1)
                            {
                                cout<<"DADOS STOCK PASADOS AL RIVAL: 0"<<endl;
                            }
                        }
                    }
                    cout<<endl<<"PRESIONE ENTER PARA CONTINUAR..."<<endl;
                    ronda++;
                    system("pause>nulls");
                    system("cls");
                }

            }
            if(dadoStock1==0)
            {
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<endl<<"El jugador "<<jugador1<<" logro quedarse sin dados ganando automaticamente la partida."<<endl;
                cout<<"Obtiene 10.000(Mil) puntos bien piolitas."<<endl;
                SCORE1+=10000;
                cout<<endl<<"SCORE FINAL: "<<SCORE1<<"."<<endl;
                cout<<"----------------------------------------------------------------------------"<<endl;
                system("pause>nulls");
                system("cls");
            }
            if(dadoStock2==0)
            {
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<endl<<"El jugador "<<jugador2<<" logro quedarse sin dados ganando automaticamente la partida."<<endl;
                cout<<"Obtiene 10.000(Mil) puntos bien piolitas."<<endl;
                SCORE2+=10000;
                cout<<endl<<"SCORE FINAL: "<<SCORE2<<"."<<endl;
                cout<<"----------------------------------------------------------------------------"<<endl;
                system("pause>nulls");
                system("cls");
            }
            system("cls");
            if(SCORE1>SCORE2)
            {
                maximoscore=SCORE1;
                maximojugador=jugador1;
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<endl<<maximojugador<<" ES EL GANADOR."<<endl<<endl;
                cout<<"----------------------------------------------------------------------------"<<endl;
                system("pause>nulls");
                system("cls");
            }
            else
            {
                maximoscore=SCORE2;
                maximojugador=jugador2;
                cout<<"----------------------------------------------------------------------------"<<endl;
                cout<<endl<<maximojugador<<" ES EL GANADOR."<<endl<<endl;
                cout<<"----------------------------------------------------------------------------"<<endl;
                system("pause>nulls");
                system("cls");
            }
            break;
        }
        case 2:
        {
            system("cls");
            cout<<"EL MAXIMO PUNTAJE LO TIENE "<<maximojugador<<endl;
            cout<<"EL MAXIMO PUNTAJE ES "<<maximoscore<<endl;
            system("pause>nulls");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            cout<<"INTEGRANTES:"<<endl;
            cout<<"25647, BARRETO FERNANDO"<<endl;
            cout<<"24921, BELTRAN TEO"<<endl;
            cout<<"25556, NIEVA GUSTAVO"<<endl;
            system("pause>nulls");
            system("cls");
            break;
        }
        case 0:
        {
            cout<<"------------------------"<<endl;
            cout<<"SEGURO QUE QUIERE SALIR?"<<endl;
            cout<<"------------------------"<<endl;
            cout<<"1-SI"<<endl;
            cout<<"2-NO"<<endl;
            cin>>opcionVolver;
            cout<<" "<<endl;
            system("cls");
            if (opcionVolver==1)
            {
                return 0;
            }
            else
            {
                return main();
            }
            break;
        }
        default:
        {
            system("cls");
            cout<<"OPCION NO VALIDA, INGRESE OTRA PORFAVOR"<<endl;
            break;
        }
        }
    }
    while (opcionMenu!=99999);
    system("pause");
    return 0;
}
