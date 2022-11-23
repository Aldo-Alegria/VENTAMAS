#pragma once
#include <iostream>
using namespace std;

class DetallesDeVenta
{
private:
	int CodVenta;
	int CodProducto;
	int Cantidad;
	float PrecioVenta;
public:
	DetallesDeVenta() {

	}
	DetallesDeVenta(int codven, int codproduc, int can, float precioven) {
		CodVenta = codven;
		CodProducto = codproduc;
		Cantidad = can;
		PrecioVenta = precioven;
	}
	//SET
	void SetCodVenta(int codven) {
		CodVenta = codven;
	}
	void SetCodProducto(int codproduc) {
		CodProducto = codproduc;
	}
	void SetCantidad(int can) {
		Cantidad = can;
	}
	void SetPrecioVenta(float precioven) {
		PrecioVenta = precioven;
	}
	//GET
	int GetCodVenta() {
		return CodVenta;
	}
	int GetCodProducto() {
		return CodProducto;
	}
	int GetCantidad() {
		return Cantidad;
	}
	float GetPrecioVenta() {
		return PrecioVenta;
	}
};