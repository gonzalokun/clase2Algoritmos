/* Completar */
#include "Diccionario.h"
#include <vector>

Diccionario::Diccionario() {
    //Lo hace vacio por defecto no???????????
}

Diccionario::Asociacion::Asociacion(Clave c, Valor v) : clave(c), valor(v){}

void Diccionario::definir(Clave k, Valor v) {

    for(int i = 0; i < _asociaciones.size(); i++){
        if(_asociaciones[i].clave == k){
            _asociaciones[i].valor = v;
            return;
        }
    }

    //ESTA VERSION FUNCA
    //Diccionario::Asociacion as = Diccionario::Asociacion(k, v);

    Diccionario::Asociacion  as(k, v);

    _asociaciones.push_back(as);

}

bool Diccionario::def(Clave k) const {
    bool definida = false;

    for(int i = 0; i < _asociaciones.size(); i++){
        if(_asociaciones[i].clave == k){
            definida = true;
            break;
        }
    }

    return definida;
}

//SOBREIMPLEMENTADO PROBABLEMENTE, HAY QUE PREGUNTAR
Valor Diccionario::obtener(Clave k) const {
    Valor val = -1;

    for(int i = 0; i < _asociaciones.size(); i++){
        if(_asociaciones[i].clave == k){
            val = _asociaciones[i].valor;
        }
    }

    return val;
}

void Diccionario::borrar2(Clave k) {
    int indiceParaBorrar = -1;

    for(int i = 0; i < _asociaciones.size();i++){
        if(_asociaciones[i].clave == k){
            indiceParaBorrar = i;
        }
    }

    if(indiceParaBorrar >= 0){
        //ESTO LO DICE LA DOCUMENTACION DE VECTORES DE C++
        _asociaciones.erase(_asociaciones.begin() + indiceParaBorrar);
    }
}

void Diccionario::borrar(Clave k) {
    int indiceParaBorrar = -1;

    for(int i = 0; i < _asociaciones.size();i++){
        if(_asociaciones[i].clave == k){
            indiceParaBorrar = i;
        }
    }

    if(indiceParaBorrar >= 0){

        //Muevo el ultimo elemento al final
        for(int i = indiceParaBorrar; i < _asociaciones.size() - 1; i++){
            std::swap(_asociaciones[i], _asociaciones[i + 1]);
        }

        //Lo elimino
        _asociaciones.pop_back();
    }
}

std::vector<Clave> Diccionario::claves() const {
    std::vector<Clave> clavesADevolver;

    for(int i = 0; i< _asociaciones.size(); i++){
        clavesADevolver.push_back(_asociaciones[i].clave);
    }

    return  clavesADevolver;
}

/*
int Diccionario::cantidadElem() {
    return (int) _asociaciones.size();
}
*/

bool Diccionario::esPermutacion(std::vector<Clave> v1, std::vector<Clave> v2) {
    bool esPermu = true;

    if(v1.size() == v2.size()){

        for(int i = 0; i < v1.size(); i++){
            bool encontrado = false;

            for(int j = 0; j < v2.size(); j++){
                if(v1[i] == v2[j]){
                    encontrado = true;
                }
            }

            if(not encontrado){
                esPermu = false;
                break;
            }
        }

    }

    else{
        esPermu = false;
    }

    return esPermu;
}

bool Diccionario::operator==(Diccionario o) {
    bool iguales = true;

    if(esPermutacion(claves(), o.claves())){

        for(int i = 0; i < claves().size();i++){

            if(obtener(claves()[i]) != o.obtener(claves()[i])){
                iguales = false;
            }

        }

    }

    else{
        iguales = false;
    }

    return iguales;
}