#pragma once
#include <iostream>
using namespace std;

class Producto
{
private:
	int 	CodProduc;
	string 	NomProduc;
	float 	PrecioProduc;
	int 	StockProduc;
	int		CodCategoria;
public:
	~Producto()
	{

	}
	Producto()
	{

	}
	Producto(int cod, string name, float precio, int stock, int codcate)
	{
		CodProduc = cod;
		NomProduc = name;
		PrecioProduc = precio;
		StockProduc = stock;
		CodCategoria = codcate;
	}
	//SET
	void SetCodProduc(int cod)
	{
		CodProduc = cod;
	}
	void SetNomProduc(string name)
	{
		NomProduc = name;
	}
	void SetPrecioProduc(float precio)
	{
		PrecioProduc = precio;
	}
	void SetStockProduc(int stock)
	{
		StockProduc = stock;
	}
	void SetCodCategoria(int codcate)
	{
		CodCategoria = codcate;
	}
	//GET
	int GetCodProduc()
	{
		return CodProduc;
	}
	string GetNomProduc()
	{
		return NomProduc;
	}
	float GetPrecioProduc()
	{
		return PrecioProduc;
	}
	int GetStockProduc()
	{
		return StockProduc;
	}
	int GetCodCate()
	{
		return CodCategoria;
	}
};