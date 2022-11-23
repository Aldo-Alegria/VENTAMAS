#pragma once
#include <iostream>
#include "TipoPersonal.h"
#include <vector>
#include <fstream>
using namespace std;

class TipoPersonalController
{
private:
	vector<TipoPersonal> VectorTipoPersonal;
public:
	TipoPersonalController()
	{
		CargarDatosDelArchivoAlVector();
	}
	void AgregarTipoPersonal(TipoPersonal obj)
	{
		VectorTipoPersonal.push_back(obj);
	}
	TipoPersonal GetObjeto(int pos)
	{
		return VectorTipoPersonal[pos];
	}
	int Tamanio()
	{
		return VectorTipoPersonal.size();
	}
	int NumeroCodigo()
	{
		if (Tamanio() == 0)
		{
			return 1;
		}
		else
		{
			return 	VectorTipoPersonal[Tamanio() - 1].GetCodigoTipPersonal() + 1;
		}
	}
	//AGREGAR DATOS  AL VECTOR
	void GrabarAlArchivo(TipoPersonal obj)
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("TipoPersonal.csv", ios::app);
			if (archivoTipoPersonal.is_open())
			{
				archivoTipoPersonal << obj.GetCodigoTipPersonal() << ";" << obj.GetNomTipPersonal() << ";" << endl;
				archivoTipoPersonal.close();
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
			string 	temporal[2];
			fstream	archivoTipoPersonal;
			archivoTipoPersonal.open("TipoPersonal.csv", ios::in);
			if (archivoTipoPersonal.is_open())
			{
				while (!archivoTipoPersonal.eof() && getline(archivoTipoPersonal, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					TipoPersonal obj(stoi(temporal[0]), temporal[1]);

					AgregarTipoPersonal(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	//Buscar por codigo
	TipoPersonal BuscarPorCodigo(int codigo)
	{
		TipoPersonal objError;
		objError.SetNomTipPersonal("ERROR");

		int inf = 0, sup = VectorTipoPersonal.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorTipoPersonal[mitad].GetCodigoTipPersonal() == codigo) {
				ban = "V";
				break;
			}
			if (VectorTipoPersonal[mitad].GetCodigoTipPersonal() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorTipoPersonal[mitad].GetCodigoTipPersonal() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorTipoPersonal[mitad];
		}
		else {
			return objError;
		}
	}
	//Listar

};