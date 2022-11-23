#pragma once
#include <iostream>
using namespace std;

class Ventas
{
private:
	int CodVenta;
	string FechaVenta;
	float TotalVenta;
	string EstadoDeVenta;
	int CodCliente;
	int CodPersonal;
public:
	Ventas() {

	}
	Ventas(int codven, string fecha, float totalven, string estado, int codcliente, int codperso) {
		CodVenta = codven;
		FechaVenta = fecha;
		TotalVenta = totalven;
		CodCliente = codcliente;
		EstadoDeVenta = estado;
		CodPersonal = codperso;
	}
	//SET
	void SetCodVenta(int codven) {
		CodVenta = codven;
	}
	void SetFechaVenta(string fecha) {
		FechaVenta = fecha;
	}
	void SetTotalVenta(float totalven) {
		TotalVenta = totalven;
	}
	void SetEstadoDeVenta(string estado) {
		EstadoDeVenta = estado;
	}
	void SetCodCliente(int codcliente) {
		CodCliente = codcliente;
	}
	void SetCodPersonal(int codperso) {
		CodPersonal = codperso;
	}
	//GET
	int GetCodVenta() {
		return CodVenta;
	}
	string GetFechaVenta() {
		return FechaVenta;
	}
	float GetTotalVenta() {
		return TotalVenta;
	}
	int GetCodCliente() {
		return CodCliente;
	}
	string GetEstadoDeVenta() {
		return EstadoDeVenta;
	}
	int GetCodPersonal() {
		return CodPersonal;
	}
};