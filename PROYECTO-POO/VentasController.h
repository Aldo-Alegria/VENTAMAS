#pragma once
#include <iostream>
#include "Ventas.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class VentasController
{
private:
	vector <Ventas> VectorVenta;
public:
	VentasController() {
		CargarDatosDelArchivoAlVector();
	}
	void AgregarVenta(Ventas obj) {
		VectorVenta.push_back(obj);
	}
	Ventas GetObjeto(int pos) {
		return VectorVenta[pos];
	}
	int Tamanio() {
		return VectorVenta.size();
	}
	int NumeroCodigo() {
		if (VectorVenta.size() == 0) {
			return 1;
		}
		else {
			return VectorVenta[Tamanio() - 1].GetCodVenta() + 1;
		}
	}
	void GrabarAlArchivo(Ventas obj)
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("Ventas.csv", ios::app);
			if (archivoTipoPersonal.is_open())
			{
				archivoTipoPersonal << obj.GetCodVenta() << ";" << obj.GetFechaVenta() << ";" << obj.GetTotalVenta() << ";" << obj.GetEstadoDeVenta() << ";" << obj.GetCodCliente() << ";" << obj.GetCodPersonal() << ";" << endl;
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
			string 	temporal[6];
			fstream	archivoTipoPersonal;
			archivoTipoPersonal.open("Ventas.csv", ios::in);
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

					Ventas obj(stoi(temporal[0]), temporal[1], stof(temporal[2]), temporal[3], stoi(temporal[4]), stoi(temporal[5]));

					AgregarVenta(obj);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
	Ventas BuscarPorCodigo(int codigo)
	{
		Ventas objError;
		objError.SetEstadoDeVenta("ERROR");

		int inf = 0, sup = VectorVenta.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorVenta[mitad].GetCodVenta() == codigo) {
				ban = "V";
				break;
			}
			if (VectorVenta[mitad].GetCodVenta() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorVenta[mitad].GetCodVenta() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorVenta[mitad];
		}
		else {
			return objError;
		}
	}
};