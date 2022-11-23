#pragma once
#include <iostream>
using namespace std;

class Categoria
{
private:
	int CodCate;
	string NomCate;
public:
	Categoria()
	{

	}
	Categoria(int cod, string nom)
	{
		CodCate = cod;
		NomCate = nom;
	}
	//SET
	void SetCodCate(int cod)
	{
		CodCate = cod;
	}
	void SetNomCate(string nom)
	{
		NomCate = nom;
	}
	//GET
	int GetCodCate()
	{
		return CodCate;
	}
	string GetNomCate()
	{
		return NomCate;
	}
};