#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<stdlib.h>
#include <fstream>
#include "Login.h"
using namespace std;

class LoginController
{
private:
	vector <Login> VectorLogin; /*Creamos el arreglo dinamico de objetos*/
public:
	LoginController()
	{
		CargarDatosArchivoVector();
	};
	void AgregarUsuario(Login obj)
	{
		VectorLogin.push_back(obj);
	}
	Login GetObjeto(int pos)
	{
		return VectorLogin[pos];
	}
	int Tamanio()
	{
		return VectorLogin.size();
	}

	void GrabarEnArchivo(Login obj)
	{
		try
		{
			fstream archivoLogin;
			archivoLogin.open("login.csv", ios::app);
			if (archivoLogin.is_open())
			{
				archivoLogin << obj.GetUsuario() << ";" << obj.GetContrasenia() << ";" << endl;
				archivoLogin.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	void CargarDatosArchivoVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[2];
			fstream	archivoLogin;
			archivoLogin.open("login.csv", ios::in);
			if (archivoLogin.is_open())
			{
				while (!archivoLogin.eof() && getline(archivoLogin, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Login objLogin((temporal[0]), temporal[1]);
					AgregarUsuario(objLogin);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}

};