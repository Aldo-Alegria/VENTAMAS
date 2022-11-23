#pragma once
#include <iostream>
#include "personal.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class PersonalController
{
private:
	vector<Personal> VectorPersonal;
public:
	PersonalController()
	{
		CargarDatosDelArchivoAlVector();
	}
	void AgregarPersonal(Personal obj)
	{
		VectorPersonal.push_back(obj);
	}
	Personal GetObjeto(int pos)
	{
		return VectorPersonal[pos];
	}
	int Tamanio()
	{
		return VectorPersonal.size();
	}

	//Para que el codigo siga de 1 en 1 
	int NumeroCodigo()
	{
		if (Tamanio() == 0)
		{
			return 1;
		}
		else
		{
			return 	VectorPersonal[Tamanio() - 1].GetCodigoPersonal() + 1;
		}
	}

	//AGREGAR DATOS  AL VECTOR
	void GrabarAlArchivo(Personal obj)
	{
		try
		{
			fstream archivoPersonal;
			archivoPersonal.open("Personal.csv", ios::app);
			if (archivoPersonal.is_open())
			{
				archivoPersonal << obj.GetCodigoPersonal() << ";" << obj.GetNombrePersonal() << ";" << obj.GetUsuarioPersonal() << ";" << obj.GetPassPersonal() << ";" << obj.GetCodigoTipoPer() << ";" << endl;
				archivoPersonal.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un problema al grabar en el archivo!!!";
		}
	}

	//AGREGAR DATOS AL ARCHIVO DENTRO DEL VECTOR
	void CargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[5];
			fstream	archivoPersonal;
			archivoPersonal.open("Personal.csv", ios::in);
			if (archivoPersonal.is_open())
			{
				while (!archivoPersonal.eof() && getline(archivoPersonal, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Personal obj(stoi(temporal[0]), temporal[1],
						temporal[2], temporal[3], stoi(temporal[4]));

					AgregarPersonal(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	//Buscar por codigo
	Personal BuscarPorCodigo(int codigo)
	{
		Personal objError;
		objError.SetNombrePersonal("ERROR");

		int inf = 0, sup = VectorPersonal.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorPersonal[mitad].GetCodigoPersonal() == codigo) {
				ban = "V";
				break;
			}
			if (VectorPersonal[mitad].GetCodigoPersonal() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorPersonal[mitad].GetCodigoPersonal() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorPersonal[mitad];
		}
		else {
			return objError;
		}
	}
	/*
	Personal buscardatos(int codigo)
	{
		Personal objError;
		objError.setNomApePersonal("ERROR");

		for (int i = 0; i < vectorPersonal.size(); i++)
		{
			if (codigo == vectorPersonal[i].getCodPersonal())
			{
				return vectorPersonal[i];
			}
		}
		return objError;
	}
	*/
	//Modificar Clientes

	bool Modificar(Personal obj1Modificar, Personal obj2Modificado)
	{
		for (int i = 0; i < VectorPersonal.size(); i++)
		{
			if (obj1Modificar.GetCodigoPersonal() == VectorPersonal[i].GetCodigoPersonal())
			{
				VectorPersonal[i].SetNombrePersonal(obj2Modificado.GetNombrePersonal());
				VectorPersonal[i].SetUsuarioPersonal(obj2Modificado.GetUsuarioPersonal());
				VectorPersonal[i].SetPassPersonal(obj2Modificado.GetPassPersonal());
				VectorPersonal[i].SetCodigoTipoPer(obj2Modificado.GetCodigoTipoPer());
				return true;
			}
		}
		return false;
	}

	//Modificar para el nuevo archivo

	void GrabarModificadoAlArchivo()
	{
		try {
			fstream archivoPersonal;
			archivoPersonal.open("Personal.csv", ios::out);
			if (archivoPersonal.is_open())
			{
				for (Personal x : VectorPersonal)
				{
					archivoPersonal << x.GetCodigoPersonal() << ";" << x.GetNombrePersonal() << ";" << x.GetUsuarioPersonal() << ";" << x.GetPassPersonal() << ";" << x.GetCodigoTipoPer() << ";" << endl;
				}
				archivoPersonal.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}

	//Para eliminar datos 
	int ObtenerPosicion(Personal obj)
	{
		for (int i = 0; i < VectorPersonal.size(); i++)
		{
			if (obj.GetCodigoPersonal() == VectorPersonal[i].GetCodigoPersonal())
			{
				return i;
			}
		}
		return -1;
	}
	void Eliminar(Personal obj)
	{
		VectorPersonal.erase(VectorPersonal.begin() + ObtenerPosicion(obj));
	}
};