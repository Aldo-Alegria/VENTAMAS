#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Categoria.h"
using namespace std;

class CategoriaController
{
private:
	vector <Categoria> VectorCategoria;
public:
	CategoriaController()
	{
		CargarDatosDelArchivoAlVector();
	}
	void AgregarCategoria(Categoria obj)
	{
		VectorCategoria.push_back(obj);
	}
	Categoria GetObjeto(int pos)
	{
		return VectorCategoria[pos];
	}
	int Tamanio()
	{
		return VectorCategoria.size();
	}
	int ObtenerPosicion(Categoria obj)
	{
		for (int i = 0; i < VectorCategoria.size(); i++)
		{
			if (obj.GetCodCate() == VectorCategoria[i].GetCodCate())
			{
				return i;
			}
		}
		return -1;
	}
	Categoria BuscarPorCodigo(int codigo)
	{
		Categoria objError;
		objError.SetNomCate("ERROR");

		int inf = 0, sup = VectorCategoria.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorCategoria[mitad].GetCodCate() == codigo) {
				ban = "V";
				break;
			}
			if (VectorCategoria[mitad].GetCodCate() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorCategoria[mitad].GetCodCate() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorCategoria[mitad];
		}
		else {
			return objError;
		}
	}
	void GrabarAlArchivo(Categoria obj)
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("categorias.csv", ios::app);
			if (archivoProducto.is_open())
			{
				archivoProducto << obj.GetCodCate() << ";" << obj.GetNomCate() << ";" << endl;
				archivoProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	void GrabarModificadoAlArchivo()
	{
		try {
			fstream archivoProducto;
			archivoProducto.open("categorias.csv", ios::out);
			if (archivoProducto.is_open())
			{
				for (Categoria x : VectorCategoria)
				{
					archivoProducto << x.GetCodCate() << ";" << x.GetNomCate() << ";" << endl;
				}
				archivoProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	void CargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[2];
			fstream	archivoProducto;
			archivoProducto.open("categorias.csv", ios::in);
			if (archivoProducto.is_open())
			{
				while (!archivoProducto.eof() && getline(archivoProducto, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Categoria obj(stoi(temporal[0]), temporal[1]);

					AgregarCategoria(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};