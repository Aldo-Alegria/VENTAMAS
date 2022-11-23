#pragma once
#include <iostream>
#include <vector>
#include "Producto.h"
#include "CategoriaController.h"
#include <fstream>
using namespace std;

class ProductoController
{
private:
	vector<Producto> VectorProducto;
public:
	~ProductoController()
	{

	}
	ProductoController()
	{
		CargarDatosDelArchivoAlVector();
	}
	void AgregarProducto(Producto obj)
	{
		VectorProducto.push_back(obj);
	}
	Producto GetObjeto(int pos)
	{
		return VectorProducto[pos];
	}
	int Tamanio()
	{
		return VectorProducto.size();
	}
	//Correlativo del numero
	int NumeroCodigo()
	{
		if (Tamanio() == 0)
		{
			return 1;
		}
		else
		{
			return 	VectorProducto[Tamanio() - 1].GetCodProduc() + 1;
		}
	}
	Producto BuscarPorCodigo(int codigo)
	{
		Producto objError;
		objError.SetNomProduc("ERROR");

		int inf = 0, sup = VectorProducto.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorProducto[mitad].GetCodProduc() == codigo) {
				ban = "V";
				break;
			}
			if (VectorProducto[mitad].GetCodProduc() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorProducto[mitad].GetCodProduc() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorProducto[mitad];
		}
		else {
			return objError;
		}
	}
	/*
	Producto BuscarPorCodigo(int codigo)
	{
		Producto objError;
		objError.SetNomProduc("ERROR");
		for (int i = 0; i < VectorProducto.size(); i++)
		{
			if (codigo == VectorProducto[i].GetCodProduc())
			{
				return VectorProducto[i];
			}
		}
		return objError;
	}
	Producto BuscarPorCodigo2(int codigo)
	{
		Producto objError;
		objError.SetNomProduc("ERROR");
		for (Producto x : VectorProducto)//La x es el arreglo
		{
			if (codigo == x.GetCodProduc())
			{
				return x;
			}
		}
		return objError;
	}
	*/
	bool Modificar(Producto Modificar, Producto DatosModificados)
	{
		for (int i = 0; i < VectorProducto.size(); i++)
		{
			if (Modificar.GetCodProduc() == VectorProducto[i].GetCodProduc())
			{
				VectorProducto[i].SetNomProduc(DatosModificados.GetNomProduc());
				VectorProducto[i].SetPrecioProduc(DatosModificados.GetPrecioProduc());
				VectorProducto[i].SetStockProduc(DatosModificados.GetStockProduc());
				VectorProducto[i].SetCodCategoria(DatosModificados.GetCodCate());
				return true;
			}
		}
		return false;
	}
	void GrabarAlArchivo(Producto obj)
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("Productos.csv", ios::app);
			if (archivoProducto.is_open())
			{
				archivoProducto << obj.GetCodProduc() << ";" << obj.GetNomProduc() << ";" << obj.GetPrecioProduc() << ";" << obj.GetStockProduc() << ";" << obj.GetCodCate() << ";" << endl;
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
			archivoProducto.open("Productos.csv", ios::out);
			if (archivoProducto.is_open())
			{
				for (Producto x : VectorProducto)
				{
					archivoProducto << x.GetCodProduc() << ";" << x.GetNomProduc() << ";" << x.GetPrecioProduc() << ";" << x.GetStockProduc() << ";" << x.GetCodCate() << ";" << endl;
				}
				archivoProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	int ObtenerPosicion(Producto obj)
	{
		for (int i = 0; i < VectorProducto.size(); i++)
		{
			if (obj.GetCodProduc() == VectorProducto[i].GetCodProduc())
			{
				return i;
			}
		}
		return -1;
	}
	void Eliminar(Producto obj)
	{
		VectorProducto.erase(VectorProducto.begin() + ObtenerPosicion(obj));

	}
	void CargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[5];
			fstream	archivoProducto;
			archivoProducto.open("Productos.csv", ios::in);
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

					Producto obj(stoi(temporal[0]), temporal[1],
						stof(temporal[2]), stoi(temporal[3]), stoi(temporal[4]));

					AgregarProducto(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};