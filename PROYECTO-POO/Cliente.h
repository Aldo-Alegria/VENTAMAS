#pragma once
#include <iostream>
using namespace std;

class Cliente
{
private:
	int Codigo;
	string NombreApe;
	int Edad;
	string Dni;
public:
	Cliente() {

	}
	Cliente(int cod, string nomape, int ed, string dni) {
		Codigo = cod;
		NombreApe = nomape;
		Edad = ed;
		Dni = dni;
	}
	//SET
	void SetCodigo(int cod) {
		Codigo = cod;
	}
	void SetNombre(string nomape) {
		NombreApe = nomape;
	}
	void SetEdad(int ed) {
		Edad = ed;
	}
	void SetDni(string dni) {
		Dni = dni;
	}
	//GET
	int GetCodigo() {
		return Codigo;
	}
	string GetNombre() {
		return NombreApe;
	}
	int GetEdad() {
		return Edad;
	}
	string GetDni() {
		return Dni;
	}
};