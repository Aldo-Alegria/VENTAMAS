#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Cliente.h"
using namespace std;

class ClienteController
{
private:
	vector <Cliente> VectorCliente;
public:
	ClienteController()
	{
		GrabarDelArchivoAlVector();
	}
	void AgregarCliente(Cliente obj)
	{
		VectorCliente.push_back(obj);
	}
	Cliente GetObjeto(int pos)
	{
		return VectorCliente[pos];
	}
	int Tamanio()
	{
		return VectorCliente.size();
	}
	int NumeroCodigo()
	{
		if (Tamanio() == 0)
		{
			return 1;
		}
		else
		{
			return VectorCliente[Tamanio() - 1].GetCodigo() + 1;
		}
	}
	Cliente BuscarPorCodigo(int codigo)
	{
		Cliente objError;
		objError.SetNombre("ERROR");

		int inf = 0, sup = VectorCliente.size(), mitad = (inf + sup) / 2;
		string ban = "F";

		while (inf <= sup) {
			if (VectorCliente[mitad].GetCodigo() == codigo) {
				ban = "V";
				break;
			}
			if (VectorCliente[mitad].GetCodigo() > codigo) {
				sup = mitad;
				mitad = (inf + sup) / 2;
			}
			if (VectorCliente[mitad].GetCodigo() < codigo) {
				inf = mitad;
				mitad = (inf + sup) / 2;
			}
		}
		if (ban == "V") {
			return VectorCliente[mitad];
		}
		else {
			return objError;
		}
	}
	/*
	Cliente BuscarPorCodigo(int cod)
	{
		Cliente objError;
		objError.SetNombre("ERROR");
		for (Cliente x : VectorCliente)
		{
			if (cod == x.GetCodigo())
			{
				return x;
			}
		}
		return objError;
	}
	*/
	bool Modificar(Cliente obj1, Cliente obj2)
	{
		for (int i = 0; i < VectorCliente.size(); i++)
		{
			if (obj1.GetCodigo() == VectorCliente[i].GetCodigo())
			{
				VectorCliente[i].SetNombre(obj2.GetNombre());
				VectorCliente[i].SetEdad(obj2.GetEdad());
				VectorCliente[i].SetDni(obj2.GetDni());
				return true;
			}
		}
		return false;
	}
	int ObtenerPosicion(Cliente obj)
	{
		for (int i = 0; i < VectorCliente.size(); i++)
		{
			if (obj.GetCodigo() == VectorCliente[i].GetCodigo())
			{
				return i;
			}
		}
		return -1;
	}
	void Eliminar(Cliente obj)
	{
		VectorCliente.erase(VectorCliente.begin() + ObtenerPosicion(obj));

	}
	void GrabarAlArchivo(Cliente obj)
	{

		try {
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::app);
			if (archivoCliente.is_open())
			{
				archivoCliente << obj.GetCodigo() << ";" << obj.GetNombre() << ";" << obj.GetEdad() << ";" << obj.GetDni() << ";" << endl;
				archivoCliente.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un problema al grabar al archivo ";
		}
	}
	void GrabarDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[4];
			fstream	archivoCliente;
			archivoCliente.open("clientes.csv", ios::in);
			if (archivoCliente.is_open())
			{
				while (!archivoCliente.eof() && getline(archivoCliente, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Cliente objCliente(stoi(temporal[0]), temporal[1], stoi(temporal[2]), temporal[3]);
					AgregarCliente(objCliente);
				}
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
			fstream archivoCliente;
			archivoCliente.open("clientes.csv", ios::out);
			if (archivoCliente.is_open())
			{
				for (Cliente x : VectorCliente)
				{
					archivoCliente << x.GetCodigo() << ";" << x.GetNombre() << ";" << x.GetEdad() << ";" << x.GetDni() << ";" << endl;
				}
				archivoCliente.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};