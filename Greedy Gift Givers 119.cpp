#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

struct asociation{
    string Nombre;
    int dineroNeto;
    int numeroGrupo;
};

struct asociation gitfingGroups[1000]{
};

int cont_giftgrp = 0;
int cont_numeroGrupo = 0;


void actualizarLista(string Nombre,int dinero,int numGrupo){
    //Un contador indicador de hasta donde esta el grupo de gitfingGroup
    
    for(int i=0;i<cont_giftgrp;i++){
        if (Nombre == gitfingGroups[i].Nombre && numGrupo == gitfingGroups[i].numeroGrupo){
            gitfingGroups[i].dineroNeto = gitfingGroups[i].dineroNeto + dinero;
        }
    }
}

void generateGiftingGroup(string S_cantidadP){
    int N_personas;
    
    istringstream iss1(S_cantidadP);
    iss1 >> N_personas;
    
    //Consigo los nombres
    string temp;
    getline(cin,temp);
    istringstream iss2(temp);
    
    //Mientras iss no sea null
    while (!iss2.eof()){
        string temp;
        iss2 >> temp;
        
        gitfingGroups[cont_giftgrp].Nombre=temp;
        cont_giftgrp++;
        
        gitfingGroups[cont_giftgrp].numeroGrupo=cont_numeroGrupo;
    }
    
    //Ingreso cada pago de integrante
    for (int i = 0;i<N_personas;i++){
        string Entrada;
        string Nombre_temp;
        int dineroSpent,numPersonas;
        
        getline(cin,Entrada);
        
        //Estos 3 primeros parametros son fijos de cada linea
        istringstream iss(Entrada);
        iss >> Nombre_temp;
        iss >> dineroSpent;
        iss >> numPersonas;
        
        //Tengo que quitarle dinero al que entrega
        actualizarLista(Nombre_temp,-dineroSpent,cont_numeroGrupo);
        
        //Darle dinero a cada persona esta cantidad = dineroSpent/numPersonas
        int dineroRepartir;
        
        //En caso el numero de personas es 0 a repartir se le devuelve su dinero y se agrega a su net.
        if (numPersonas == 0){
            actualizarLista(Nombre_temp,2*dineroSpent,cont_numeroGrupo);
        }
        else{
            dineroRepartir = dineroSpent/numPersonas;
            while (!iss.eof()){
                string Nombre;
                iss >> Nombre;
                actualizarLista(Nombre,dineroRepartir,cont_numeroGrupo);
            }
        }

    }
    
    //Al final para decir que termine de grupo
    cont_numeroGrupo++;
    
    
}

void imprimirResultado(){
    int temp_impresion = 0;
    
    for (int i=0;i<cont_giftgrp;i++){
        //if (temp_impresion != gitfingGroups[i].numeroGrupo){
        //    cout << "\n";
        //    temp_impresion = gitfingGroups[i].numeroGrupo;
        //}
        cout << gitfingGroups[i].Nombre << " " << gitfingGroups[i].dineroNeto << " " << gitfingGroups[i].numeroGrupo << endl;
    }
    
};


int main(){
    bool isRunning = true;
    string S_cantidadP;
    
    while (isRunning){
        getline(cin,S_cantidadP);
        
        if (S_cantidadP != ""){
            generateGiftingGroup(S_cantidadP);
        }
        else{
            isRunning = false;
        }
    }
    
    imprimirResultado();
    
    
    
    
    
    return 0;
}