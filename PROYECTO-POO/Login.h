#pragma once

#include <iostream>
using namespace std;

class Login
{
private:
	string Usuario;
	string Contrasenia;
public:
	Login()
	{
	}
	Login(string nick, string contra)
	{
		Usuario = nick;
		Contrasenia = contra;
	}
	//SET
	void SetUsuario(string nick)
	{
		this->Usuario = nick;
	}
	void SetContrasenia(string contra)
	{
		this->Contrasenia = contra;
	}
	//GET

	string GetUsuario()
	{
		return Usuario;
	}
	string GetContrasenia()
	{
		return Contrasenia;
	}
};