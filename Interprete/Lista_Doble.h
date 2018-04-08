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
    void Elimina_Lista();
    void Selecciona();
    void Selecciona_Impares();
    void Elimina_Impares();
    void Selecciona_Pares();
    void Elimina_Pares();
    void Numeros_Aleatorios(int);
    void OrdenamM();
    void OrdenaMm();
    void Insertar_NIU(int);
    void Insertar_NPU(int);
    void Operaciones(int,char);
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
void ListaDoble::Elimina_Lista(){
    if(lista!=NULL){
Nodo *aux=lista,*aux2;
while(aux!=NULL){aux2=aux->siguiente;Elimina_Dato(aux->dato);aux=aux2;}}
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

float ObtRand(int paso, float randommatrix[]){
    float unico;
    unico = (rand() % 200);
    for(int i=0;i<=paso;i++)
    {
        if( randommatrix[i]==unico)
        {
            unico = (rand() % 2000) / 100.0;
            continue;
        }
    }
    return unico;
}

void ListaDoble::Numeros_Aleatorios(int paso)
{
    float random[paso];
        for (int i = 0; i < paso; i++) {
                random[i] =ObtRand(i,random);
                Inserta(random[i]);
        }
}

void ListaDoble::OrdenamM(){
 Nodo *p=lista;
    while(p!=NULL)
    {
        Nodo *j= p->siguiente;
        while(j!=NULL){
            if(p->dato > j->dato)
            {
                float aux=j->dato;
                j->dato= p->dato;
                p->dato = aux;
            }
            j=j->siguiente;
        }
        p= p->siguiente;
    }
    Selecciona();

}

void ListaDoble::OrdenaMm(){
 Nodo *p=lista;
    while(p!=NULL)
    {
        Nodo *j= p->siguiente;
        while(j!=NULL){
            if(p->dato < j->dato)
            {
                float aux=j->dato;
                j->dato= p->dato;
                p->dato = aux;
            }
            j=j->siguiente;
        }
        p= p->siguiente;
    }
    Selecciona();
}
void ListaDoble::Insertar_NPU(int paso){
    int i=0;
    while(i<paso){
        float random[paso];
        random[i] =ObtRand(i,random);
        if(fmod(random[i],2)==0){ Inserta(random[i]); i++;}}
}

void ListaDoble::Insertar_NIU(int paso){
   int i=0;
    while(i<paso){
        float random[paso];
        random[i] =ObtRand(i,random);
        if(fmod(random[i],2.0)==1.0){ Inserta(random[i]); i++;}}
}

void ListaDoble::Elimina_Impares(){
    if(lista!=NULL){
        Nodo *aux=lista,*aux2;
        while(aux!=NULL){

                if((fmod(aux->dato,2.0))==1.0)
                {cout<<"Dato eliminado: "<<aux->dato<<endl;
                aux2=aux->siguiente;Elimina_Dato(aux->dato);aux=aux2;}else{
                aux=aux->siguiente;}
        }
    }
}
void ListaDoble::Elimina_Pares(){
    if(lista!=NULL){
        Nodo *aux=lista,*aux2;
        while(aux!=NULL){

                if((fmod(aux->dato,2))==0.0)
                {cout<<"Dato eliminado: "<<aux->dato<<endl;
                aux2=aux->siguiente;Elimina_Dato(aux->dato);aux=aux2;}else{
                aux=aux->siguiente;}
        }
    }
}

void ListaDoble::Selecciona_Pares(){
    if(lista!=NULL){
        Nodo *aux=lista;
        while(aux!=NULL){if((fmod(aux->dato,2))==0){cout<<aux->dato<<endl;aux=aux->siguiente;}}}
}

void ListaDoble::Selecciona_Impares(){
    if(lista!=NULL){
        Nodo *aux=lista;
        while(aux!=NULL){if((fmod(aux->dato,2))==1){cout<<aux->dato<<endl;aux=aux->siguiente;}}}
}

void ListaDoble::Operaciones(int variable, char operacion){
    switch(operacion){
        case '+' :{
                if(lista!=NULL){
                    Nodo *aux=lista;
                    while(aux!=NULL){cout<<"Sumando "<<variable<<" a "<<aux->dato;aux->dato=aux->dato+variable;aux=aux->siguiente;}}
                break;
            }
        case '-' :{
                if(lista!=NULL){
                    Nodo *aux=lista;
                    while(aux!=NULL){cout<<"Restando "<<variable<<" a "<<aux->dato;aux->dato=aux->dato-variable;aux=aux->siguiente;}}
                break;
            }
        case '*' :{
                if(lista!=NULL){
                    Nodo *aux=lista;
                    while(aux!=NULL){cout<<"Multiplicando "<<variable<<" a "<<aux->dato;aux->dato=aux->dato*variable;aux=aux->siguiente;}}
                break;
            }
        case '/' :{
                if(lista!=NULL){
                    Nodo *aux=lista;
                    while(aux!=NULL){cout<<"Dividiendo "<<variable<<" a "<<aux->dato;aux->dato=aux->dato/variable;aux=aux->siguiente;}}
                break;
            }

    }
}
