#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

#include <vector>

typedef int Clave;
typedef int Valor;

class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;
	void borrar(Clave k);
	void borrar2(Clave k);
	std::vector<Clave> claves() const;
	bool operator==(Diccionario o);
	//int cantidadElem();
	bool esPermutacion(std::vector<Clave> v1, std::vector<Clave> v2);
	
private:
	// Completar para el ejercicio 3
	//Che, es para el 4 no?
	struct Asociacion{
		Asociacion(Clave c, Valor v);
		Clave clave;
		Valor valor;
	};

	std::vector<Asociacion> _asociaciones;
	
};

#endif /*__DICCIONARIO_H__*/
