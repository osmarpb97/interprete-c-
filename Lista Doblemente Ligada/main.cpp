#include <iostream>

using namespace std;

class Nodo{
public:
    float dato;
    Nodo *siguiente,*anterior;
    Nodo(){siguiente=NULL,anterior=NULL;}
};

class ListaDoble{
public:
    void Inserta(float);
    void Elimina_Dato(float);
    void Selecciona();
    Nodo *lista,*ultimo;
    ListaDoble(){lista=NULL,ultimo=NULL;}
};

void ListaDoble::Inserta(float paso){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=paso;
    if(lista==NULL){
        lista=ultimo=nuevo_nodo;}
    else{
        ultimo->siguiente=nuevo_nodo;
        ultimo->siguiente->anterior=ultimo;
        ultimo=ultimo->siguiente;
    }
}

void ListaDoble::Elimina_Dato(float paso){
    Nodo *aux=lista;
    if(lista!=NULL){
        while((aux->siguiente!=NULL)&&(aux->dato!=paso)){
            aux=aux->siguiente;
        }
        if(aux->siguiente==NULL&&aux->anterior==NULL&&aux->dato==paso){
            lista=NULL;
            delete aux;
        }
        else if(aux->anterior==NULL&&aux->siguiente!=NULL&&aux->dato==paso){
            aux=aux->siguiente;
            delete aux->anterior;
            lista=aux;
            lista->anterior=NULL;
        }
        else if(aux->anterior!=NULL&&aux->siguiente!=NULL&&aux->dato==paso){
            aux->anterior->siguiente=aux->siguiente;
            aux->siguiente->anterior=aux->anterior;
            delete aux;
        }
        else if(aux->anterior!=NULL&&aux->siguiente==NULL&&aux->dato==paso){
            aux=aux->anterior;
            delete aux->siguiente;
            aux->siguiente=NULL;
            ultimo=aux;
        }
    }
}

void ListaDoble::Selecciona(){
    if(lista!=NULL){
Nodo *aux=lista;
while(aux!=NULL){cout<<aux->dato<<endl;aux=aux->siguiente;}}
}



int main()
{
    int op;
    float dato;
    ListaDoble Objeto;
    while (op!=0){
        cin>>op;
        switch (op){
            case 1:{
                cout<<"Inserta dato:";
                cin>>dato;
                Objeto.Inserta(dato);
                break;
            }
            case 2:{
                cout<<"Dato a eliminar:";
                cin>>dato;
                Objeto.Elimina_Dato(dato);
                break;
            }
            case 3:{
                Objeto.Selecciona();
                break;
            }
        }
    }


    return 0;
}
