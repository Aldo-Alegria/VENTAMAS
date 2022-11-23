#pragma once
#include <iostream>
using namespace std;

class TipoPersonal
{
private:
	int CodTipPersonal;
	string NomTipPersonal;


public:
	TipoPersonal()
	{

	}
	TipoPersonal(int cod, string name)
	{
		CodTipPersonal = cod;
		NomTipPersonal = name;
	}
	~TipoPersonal()
	{

	}
	/*SET*/
	void SetCodigoTipPersonal(int cod)
	{
		CodTipPersonal = cod;
	}
	void SetNomTipPersonal(string name)
	{
		NomTipPersonal = name;
	}
	//*GET*
	int GetCodigoTipPersonal()
	{
		return CodTipPersonal;
	}
	string GetNomTipPersonal()
	{
		return NomTipPersonal;
	}
};