#pragma once
#include <iostream>
using namespace std;

class Personal
{
private:
	int CodPersonal;
	string NomPersonal;
	string UsuPersonal;
	string PassPersonal;
	int CodTipPersonal;


public:
	Personal()
	{

	}
	Personal(int codper, string name, string usuario, string pass, int codtipoper)
	{
		CodPersonal = codper;
		NomPersonal = name;
		UsuPersonal = usuario;
		PassPersonal = pass;
		CodTipPersonal = codtipoper;
	}
	/*SET*/
	void SetCodigoPersonal(int codper)
	{
		CodPersonal = codper;
	}
	void SetNombrePersonal(string name)
	{
		NomPersonal = name;
	}
	void SetUsuarioPersonal(string usuario)
	{
		UsuPersonal = usuario;
	}
	void SetPassPersonal(string pass)
	{
		PassPersonal = pass;
	}
	void SetCodigoTipoPer(int codtipoper)
	{
		CodTipPersonal = codtipoper;
	}
	//*GET*
	int GetCodigoPersonal()
	{
		return CodPersonal;
	}
	string GetNombrePersonal()
	{
		return NomPersonal;
	}
	string GetUsuarioPersonal()
	{
		return UsuPersonal;
	}
	string GetPassPersonal()
	{
		return PassPersonal;
	}
	int GetCodigoTipoPer()
	{
		return CodTipPersonal;
	}
};