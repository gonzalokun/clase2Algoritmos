#include "gtest/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

//Completar para el ejercicio 5

TEST(borrado, borrar_y_verificar){
	Diccionario d;

	d.definir(1, 4);
	d.definir(2, 5);
	d.definir(3, 9);

	d.borrar(2);

	ASSERT_FALSE(d.def(2));
}

TEST(borrado, verificar_restantes){
	Diccionario d;

	d.definir(1, 4);
	d.definir(2, 5);
	d.definir(3, 9);
	d.definir(15, 67);
	d.definir(8, 9);

	d.borrar(15);

	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_TRUE(d.def(3));
	ASSERT_TRUE(d.def(8));

	ASSERT_EQ(d.obtener(1), 4);
	ASSERT_EQ(d.obtener(2), 5);
	ASSERT_EQ(d.obtener(3), 9);
	ASSERT_EQ(d.obtener(8), 9);
}

TEST(borrado, verificar_no_cambios){
	Diccionario d;

	d.definir(1, 4);
	d.definir(10, 5);
	d.definir(3, 9);
	d.definir(20, 19);

	d.borrar(55);

	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(10));
	ASSERT_TRUE(d.def(3));
	ASSERT_TRUE(d.def(20));

	ASSERT_EQ(d.obtener(1), 4);
	ASSERT_EQ(d.obtener(10), 5);
	ASSERT_EQ(d.obtener(3), 9);
	ASSERT_EQ(d.obtener(20), 19);
}

#endif

#if EJ >= 6

// Completar para el ejercicio 6

TEST(listaDeClaves, verificar_que_sean_claves){
	Diccionario d;

	d.definir(1, 4);
	d.definir(10, 5);
	d.definir(3, 9);
	d.definir(20, 19);

	std::vector<Clave> vectorDeClaves = d.claves();

	for(int i = 0; i < vectorDeClaves.size(); i++){
		ASSERT_TRUE(d.def(vectorDeClaves[i]));
	}
}

TEST(listaDeClaves, permutacion){
	Diccionario d, d2;

	d.definir(1, 4);
	d.definir(10, 5);
	d.definir(3, 9);
	d.definir(20, 19);

	d2.definir(1, 43);
	d2.definir(20, 3);
	d2.definir(10, 2);
	d2.definir(3, 7);

	ASSERT_TRUE(d.esPermutacion(d.claves(), d2.claves()));
	ASSERT_TRUE(d2.esPermutacion(d2.claves(), d.claves()));
}

#endif

#if EJ >= 7

// Completar para el ejercicio 7

#endif

#if EJ >= 8

#endif

