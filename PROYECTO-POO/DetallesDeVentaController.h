#pragma once
#include <iostream>
#include "DetallesDeVenta.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class DetallesDeVentaController
{
private:
	vector <DetallesDeVenta> VectorDetallesDeVenta;
public:
	DetallesDeVentaController() {
		CargarDatosDelArchivoAlVector();
	}
	void AgregarDetalleDeVenta(DetallesDeVenta obj) {
		VectorDetallesDeVenta.push_back(obj);
	}
	DetallesDeVenta GetObjeto(int pos) {
		return VectorDetallesDeVenta[pos];
	}
	int Tamanio() {
		return VectorDetallesDeVenta.size();
	}
	void GrabarAlArchivo(DetallesDeVenta obj)
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("DetallesDeVenta.csv", ios::app);
			if (archivoTipoPersonal.is_open())
			{
				archivoTipoPersonal << obj.GetCodVenta() << ";" << obj.GetCodProducto() << ";" << obj.GetCantidad() << ";" << obj.GetPrecioVenta() << ";" << endl;
				archivoTipoPersonal.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un problema al grabar en el archivo!!!";
		}
	}
	void CargarDatosDelArchivoAlVector()
	{

		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[4];
			fstream	archivoTipoPersonal;
			archivoTipoPersonal.open("DetallesDeVenta.csv", ios::in);
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

					DetallesDeVenta obj(stoi(temporal[0]), stoi(temporal[1]), stoi(temporal[2]), stof(temporal[3]));

					AgregarDetalleDeVenta(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	DetallesDeVenta BuscarPorCodigo(int codigo)
	{
		DetallesDeVenta objError;
		objError.SetCantidad(-1);

		int inf = 0, sup = VectorDetallesDeVenta.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorDetallesDeVenta[mitad].GetCodVenta() == codigo) {
				ban = "V";
				break;
			}
			if (VectorDetallesDeVenta[mitad].GetCodVenta() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorDetallesDeVenta[mitad].GetCodVenta() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorDetallesDeVenta[mitad];
		}
		else {
			return objError;
		}
	}
};