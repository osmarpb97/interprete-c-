//Autor: Osmar Pérez Bautista
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
using namespace std;
#include "lista_doble.h"


class interprete
{
public:
    interprete();
    void menu();void palabrasclave();void ejecutar();void diccionario(); void invalido();
    char palabras[10][100],clave[10][30];
    char *separar,*pasopalabra;
    int numpalabras,o;
    float num[3];
    ListaDoble *listadoble;

};

void interprete::menu()
{
    pasopalabra=new char;
    cout<<"Interprete de listas simplemente ligadas\nAyuda para ver los comandos"<<endl;
    fflush(stdin);
    cin.getline(pasopalabra,500);
    cout<<"Inroduciste la palabra "<<pasopalabra<<endl;
    palabrasclave();
}

interprete::interprete(){numpalabras=0;separar=new char;listadoble=new ListaDoble[10],o=0;}

void interprete::palabrasclave()
{
    char diccionariop[25][16]= {"Ayuda","Lista","IMPRIME","Ordena","+","Salir","Selecciona","Unicos","Inserta","Valor","-","Mayor","Menor","Valores","Aleatorios","/","Pares","Impares","*","numeros","final","elimina","numero","actualiza"};
    int i=0;
    while(o!=0){o--;};
    separar=strtok(pasopalabra," ");
    while(separar!=NULL)
    {
        for (int k=0; k<25; k++)
        {
        if (strcasecmp(separar,diccionariop[k])==0){
        strcpy(palabras[i],separar);
        palabras[i];
        i++;}}
        if (isdigit(separar[0]))
        {
            num[o]= atof(separar);
            o++;
        }
        separar=strtok(NULL," ");
    }
        numpalabras=i;
        i=0;
        ejecutar();
}

void interprete::invalido(){
    cout<<"Comando no valido"<<endl;
    system("PAUSE>NULL");
    system("cls");
    memset(palabras,'\0',strlen(palabras[0]));
    menu();
}

void interprete::ejecutar()
{
    int salir,numi;
    while(salir==0){
    if(strcasecmp(palabras[0],"AYUDA")==0)
    {
        system("CLS");
        cout<<"------------------SIN IMPLEMENTAR------------------";
        system("PAUSE>NULL");
        system("cls");
        memset(palabras,'\0',strlen(palabras[0]));
        menu();
    }
    //IMPRIMIR
    else if(strcasecmp(palabras[0],"IMPRIME")==0||strcasecmp(palabras[0],"SELECCIONA")==0){
        system("CLS");
        if(strcasecmp(palabras[1],"LISTA")==0){
        numi=num[0];
        listadoble[numi].Selecciona();
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"PARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].Selecciona_Pares();
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"IMPARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].Selecciona_Impares();
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else{invalido();}
    }
    //INSERTAR
     else if(strcasecmp(palabras[0],"INSERTA")==0){
        system("CLS");
        //POR ALEATORIOS
        if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].Numeros_Aleatorios(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}
        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"IMPARES")==0){
        numi=num[1];
        listadoble[numi].Insertar_NIU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}
        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"PARES")==0){
        numi=num[1];
        listadoble[numi].Insertar_NPU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}
        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"UNICOS")==0&&strcasecmp(palabras[4],"PARES")==0){
        numi=num[1];
        listadoble[numi].Insertar_NPU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"UNICOS")==0&&strcasecmp(palabras[4],"PARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].Insertar_NPU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"UNICOS")==0&&strcasecmp(palabras[4],"IMPARES")==0){
        numi=num[1];
        listadoble[numi].Insertar_NPU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"ALEATORIOS")==0&&strcasecmp(palabras[3],"UNICOS")==0&&strcasecmp(palabras[4],"IMPARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].Insertar_NPU(num[0]);
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        //POR VALOR
        else if((strcasecmp(palabras[1],"VALOR")==0||strcasecmp(palabras[1],"NUMERO")==0)&&strcasecmp(palabras[2],"LISTA")==0){
            numi=num[1];
            listadoble[numi].Inserta(num[0]);
            memset(palabras,'\0',strlen(palabras[0]));
            menu();
        }
        else{invalido();}
    }
    //ORDENA
     else if(strcasecmp(palabras[0],"ORDENA")==0){
        system("CLS");
        //MAYOR MENOR
        if(strcasecmp(palabras[1],"MAYOR")==0&&strcasecmp(palabras[2],"MENOR")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].OrdenaMm();
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}

        //MENOR MAYOR
        else if(strcasecmp(palabras[1],"MENOR")==0&&strcasecmp(palabras[2],"MAYOR")==0&&strcasecmp(palabras[3],"LISTA")==0){
        numi=num[1];
        listadoble[numi].OrdenamM();
        memset(palabras,'\0',strlen(palabras[0]));
        menu();}
        else{invalido();}
    }

    //EXTRAE O ELIMINA
    else if(strcasecmp(palabras[0],"ELIMINA")==0){
            system("CLS");
             if(strcasecmp(palabras[1],"LISTA")==0){
                numi=num[1];
                listadoble[numi].Elimina_Lista();
                memset(palabras,'\0',strlen(palabras[0]));
                menu();
            }
            else if((strcasecmp(palabras[1],"VALOR")==0||strcasecmp(palabras[1],"NUMERO")==0)&&strcasecmp(palabras[2],"LISTA")==0){
                numi=num[1];
                listadoble[numi].Elimina_Dato(num[0]);
                memset(palabras,'\0',strlen(palabras[0]));
                menu();
            }
            else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"PARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
                numi=num[1];
                listadoble[numi].Elimina_Pares();
                memset(palabras,'\0',strlen(palabras[0]));
                menu();
            }
            else if((strcasecmp(palabras[1],"VALORES")==0||strcasecmp(palabras[1],"NUMEROS")==0)&&strcasecmp(palabras[2],"IMPARES")==0&&strcasecmp(palabras[3],"LISTA")==0){
                numi=num[1];
                listadoble[numi].Elimina_Impares();
                memset(palabras,'\0',strlen(palabras[0]));
                menu();
            }
            else{invalido();}
    }
    //COMANDOS INVALIDOS Y SALIDA
    else if(strcasecmp(palabras[0],"SALIR")==0){
            cout<<"Programa Terminado";
            salir=1;
    }
    else {invalido();
}}}

int main()
{
    interprete llamar;
    llamar.menu();
    system("PAUSE>NULL");
}
