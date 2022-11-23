// PROYECTO-POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include "LoginController.h"
#include "ClienteController.h"
#include "ProductoController.h"
#include "CategoriaController.h"
#include "TipoPersonalController.h"
#include "PersonalController.h"
#include "VentasController.h"
#include "DetallesDeVentaController.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

DetallesDeVentaController* DetalleVenControl = new DetallesDeVentaController();
VentasController* VentaControl = new VentasController();
TipoPersonalController* TipoPersoControl = new TipoPersonalController();
PersonalController* PersonControl = new PersonalController();
CategoriaController* CateControl = new CategoriaController();
ProductoController* ProducControl = new ProductoController();
LoginController* LoginControl = new LoginController();
ClienteController* ClienteControl = new ClienteController();

int Comprobacion(string usua, string contra);
void Datos();
void Datos2();
void cuadro(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y);

/*INICIO DE SESION*/
void InicioDeSesion();
void ListarUsuarios();
void CrearCuenta();
void InicioCrearCuenta();

/*CLIENTES*/
void MenuOpciones();
void AgregarCliente();
void ListarCliente();
void BuscarCliente();
void ModificarCliente();
void EliminarCliente();
void RegistroDeClientes();

/*PRODUCTOS*/
void RegistroDeProductos();
void AgregarProducto();
void ListarProducto();
void BuscarProducto();
void ModificarProducto();
void EliminarProducto();
void Categorias();

/*PERSONAL*/
void RegistroDePersonal();
void AgregarPersonal();
void ListarPersonal();
void BuscarPersonal();
void ModificarPersonal();
void EliminarPersonal();
void TiposPerson();

/*VENTAS*/
void RegistroDeVenta();
void AgregarVenta();
void Factura(string fecha, int codcliente, int codpersonal, int codventa);
void BuscarVenta();
void EliminarVenta();
void ListarVenta();

int main()
{
	Datos2();
	Datos();
	InicioCrearCuenta();
}
void Datos2() {
	TipoPersonal obj1(1, "Administrador");
	TipoPersoControl->AgregarTipoPersonal(obj1);
	TipoPersoControl->GrabarAlArchivo(obj1);
	TipoPersonal obj2(2, "Coordinador");
	TipoPersoControl->AgregarTipoPersonal(obj2);
	TipoPersoControl->GrabarAlArchivo(obj2);
	TipoPersonal obj3(3, "Practicante");
	TipoPersoControl->AgregarTipoPersonal(obj3);
	TipoPersoControl->GrabarAlArchivo(obj3);
	TipoPersonal obj4(4, "Supervisor");
	TipoPersoControl->AgregarTipoPersonal(obj4);
	TipoPersoControl->GrabarAlArchivo(obj4);
}
void Datos() {
	Categoria obj1(1, "Procesador");
	CateControl->AgregarCategoria(obj1);
	CateControl->GrabarAlArchivo(obj1);
	Categoria obj2(2, "Placa madre");
	CateControl->AgregarCategoria(obj2);
	CateControl->GrabarAlArchivo(obj2);
	Categoria obj3(3, "Tarjeta Grafica");
	CateControl->AgregarCategoria(obj3);
	CateControl->GrabarAlArchivo(obj3);
	Categoria obj4(4, "Memoria RAM");
	CateControl->AgregarCategoria(obj4);
	CateControl->GrabarAlArchivo(obj4);
	Categoria obj5(5, "Fuente de poder");
	CateControl->AgregarCategoria(obj5);
	CateControl->GrabarAlArchivo(obj5);
	Categoria obj6(6, "Monitor");
	CateControl->AgregarCategoria(obj6);
	CateControl->GrabarAlArchivo(obj6);
	Categoria obj7(7, "Perifericos");
	CateControl->AgregarCategoria(obj7);
	CateControl->GrabarAlArchivo(obj7);
}
void InicioCrearCuenta()
{
	int otp;
	do {
		cuadro(30, 1, 82, 20);
		cuadro(30, 4, 82, 3);
		gotoxy(35, 2); printf("          BIENVENIDO A VENTAMASS  ");
		gotoxy(44, 5); cout << "Crear cuenta         [1]\n";
		gotoxy(44, 6); cout << "Iniciar Sesion       [2]\n";
		gotoxy(44, 7); cout << "Listar Usuarios      [3]\n";
		gotoxy(44, 8); cout << "Salir                [4]\n\n";
		gotoxy(44, 10); cout << "Elija una opcion: ";
		cin >> otp;

		switch (otp)
		{
		case 1: CrearCuenta(); break;
		case 2: InicioDeSesion(); break;
		case 3: ListarUsuarios(); break;
		case 4: gotoxy(41, 12); cout << "Gracias por usar nuestro programa :D"; break;
		default:gotoxy(41, 12); cout << "Por favor poner un numero entre [1-4]\n"; system("pause"); system("cls");
		}
	} while (otp != 4);
}
void CrearCuenta()
{
	system("cls");
	string usua;
	string contra;

	cin.ignore();
	cuadro(42, 7, 80, 18);
	cuadro(42, 4, 80, 6);
	gotoxy(46, 5); cout << "       CREAR CUENTA NUEVA ";
	gotoxy(46, 8); cout << "Digite el usuario: ";
	getline(cin, usua);
	gotoxy(46, 9); cout << "Digite su password: ";
	char caracter;
	caracter = _getch();
	contra = "";

	while (caracter != 13) {// Enter en ASCII
		if (caracter != 8) // Backspace en ASCII
		{
			contra.push_back(caracter);
			cout << "*";
		}
		else {
			if (contra.length() > 0) {
				cout << "\b \b";
				contra.pop_back(); // Borra el último caracter
			}

		}
		caracter = _getch();
	}
	//Crear el objeto tipo login
	Login objlogin(usua, contra);
	//Agregar el objeto al arreglo
	LoginControl->AgregarUsuario(objlogin);
	//Agregar al archivo
	LoginControl->GrabarEnArchivo(objlogin);
	system("cls");
}
void ListarUsuarios()
{
	system("cls");
	cuadro(35, 2, 84, 10);
	for (int i = 0; i < LoginControl->Tamanio(); i++)
	{
		gotoxy(48, 4 + i); cout << "Usuario " << i + 1 << ":  " << LoginControl->GetObjeto(i).GetUsuario() << "\n\n\n\n\n\n";
	}
	system("pause");
	system("cls");
}
void InicioDeSesion()
{
	system("cls");
	int ban;
	string usua;
	string contra;
	cin.ignore();
	cuadro(36, 7, 90, 18);
	cuadro(36, 4, 90, 6);
	gotoxy(53, 5); cout << "INICIO DE SESION";
	gotoxy(46, 8); cout << "Digite su usuario: ";
	getline(cin, usua);
	gotoxy(46, 9); cout << "Digite su password: ";
	char caracter;
	caracter = _getch();
	contra = "";

	while (caracter != 13) {// Enter en ASCII
		if (caracter != 8) // Backspace en ASCII
		{
			contra.push_back(caracter);
			cout << "*";
		}
		else {
			if (contra.length() > 0) {
				cout << "\b \b";
				contra.pop_back(); // Borra el último caracter
			}

		}
		caracter = _getch();
	}

	ban = Comprobacion(usua, contra);
	if (ban == 1)
	{
		gotoxy(49, 16); cout << "ESTAS DENTRO DEL SISTEMA!" << endl;
		system("pause");
		system("cls");
		MenuOpciones();
	}
	else {
		gotoxy(46, 10); cout << "NO ENTRASTE AL SISTEMA";
		gotoxy(46, 11); cout << "Verifique su usuario y contrasenia por favor\n";
	}
	system("pause");
	system("cls");
}
int Comprobacion(string usua, string contra)
{
	int x = 0;
	for (int i = 0; i < LoginControl->Tamanio(); i++)
	{
		if (usua == LoginControl->GetObjeto(i).GetUsuario() && contra == LoginControl->GetObjeto(i).GetContrasenia()) {
			x = 1;
		}
	}
	return x;
}
void MenuOpciones()
{
	int otp;
	do {
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(36, 1); cout << "         BIENVENIDO A LA BASE DE DATOS";
		gotoxy(37, 5); cout << "Registro de clientes			[1]\n";
		gotoxy(37, 6); cout << "Registro de productos			[2]\n";
		gotoxy(37, 7); cout << "Registro de vendedores			[3]\n";
		gotoxy(37, 8); cout << "Registro de ventas				[4]\n";
		gotoxy(37, 9); cout << "Salir					[5]\n\n";
		gotoxy(37, 11); cout << "Ingrese una opcion: ";
		cin >> otp;

		switch (otp)
		{
		case 1: RegistroDeClientes(); break;
		case 2: RegistroDeProductos(); break;
		case 3: RegistroDePersonal(); break;
		case 4: RegistroDeVenta(); break;
		case 5: system("cls"); break;
		default: gotoxy(40, 12); cout << "Escoga una opcion entre [1-4] por favor \n";
		}
	} while (otp != 5);
}
void RegistroDeClientes()
{
	system("cls");
	int otp;
	do {
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(51, 1); cout << "REGISTRO DE CLIENTES";
		gotoxy(38, 4); cout << "Agregar cliente nuevo			[1]\n";
		gotoxy(38, 5); cout << "Buscar cliente				[2]\n";
		gotoxy(38, 6); cout << "Modificar cliente				[3]\n";
		gotoxy(38, 7); cout << "Elminar cliente				[4]\n";
		gotoxy(38, 8); cout << "Listar clientes				[5]\n";
		gotoxy(38, 9); cout << "Salir					[6]\n";
		gotoxy(38, 11); cout << "Ingrese una opcion: ";
		cin >> otp;

		switch (otp)
		{
		case 1: AgregarCliente(); break;
		case 2: BuscarCliente(); break;
		case 3: ModificarCliente(); break;
		case 4: EliminarCliente(); break;
		case 5: ListarCliente(); break;
		case 6: system("cls"); break;
		default: gotoxy(42, 14); cout << "Escoga una opcion entre [1-6] por favor \n";
		}
	} while (otp != 6);
}
void AgregarCliente()
{
	string ban;
	do {

		system("cls");
		int cod = ClienteControl->NumeroCodigo();
		string nom;
		int ed;
		string dni;
		cin.ignore();
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(50, 1); cout << "REGISTRO DE CLIENTE";
		gotoxy(42, 4); cout << "Codigo: " << cod << endl;
		gotoxy(42, 5); cout << "Nombre completo: ";
		getline(cin, nom);
		gotoxy(42, 6); cout << "Edad: ";
		cin >> ed;
		gotoxy(42, 7); cout << "DNI: ";
		cin >> dni;

		Cliente objCliente(cod, nom, ed, dni);
		ClienteControl->AgregarCliente(objCliente);
		ClienteControl->GrabarAlArchivo(objCliente);

		gotoxy(42, 9); cout << "Desea agregar otro? (S/s)";
		cin >> ban;
	} while (ban == "S" || ban == "s");
	system("cls");
}
void ListarCliente()
{
	system("cls");
	cuadro(30, 0, 83, 2);
	cuadro(30, 3, 83, 23);

	gotoxy(32, 1); cout << "Codigo" << endl;
	gotoxy(49, 1); cout << "Nombre" << endl;
	gotoxy(65, 1); cout << "Edad" << endl;
	gotoxy(76, 1); cout << "DNI" << endl;

	for (int i = 0; i < ClienteControl->Tamanio(); i++)
	{
		gotoxy(35, 4 + i); cout << ClienteControl->GetObjeto(i).GetCodigo();
		gotoxy(46, 4 + i); cout << ClienteControl->GetObjeto(i).GetNombre();
		gotoxy(66, 4 + i); cout << ClienteControl->GetObjeto(i).GetEdad();
		gotoxy(74, 4 + i); cout << ClienteControl->GetObjeto(i).GetDni() << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	system("pause");
	system("cls");
}
void BuscarCliente()
{
	system("cls");
	int cod;
	cuadro(35, 0, 84, 2);
	cuadro(35, 3, 84, 20);
	gotoxy(40, 1); cout << "Ingrese el codigo del cliente a buscar: ";
	cin >> cod;

	Cliente objCliente = ClienteControl->BuscarPorCodigo(cod);
	if (objCliente.GetNombre() != "ERROR")
	{
		gotoxy(40, 10); cout << "Cliente encontrado satisfactoriamente\n\n";
		gotoxy(40, 5); cout << "Codigo: " << objCliente.GetCodigo() << endl;
		gotoxy(40, 6); cout << "Nombre completo: " << objCliente.GetNombre() << endl;
		gotoxy(40, 7); cout << "Edad: " << objCliente.GetEdad() << endl;
		gotoxy(40, 8); cout << "DNI: " << objCliente.GetDni() << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		gotoxy(40, 4); cout << "No se encontro al cliente buscado\n";
	}
	system("pause");
	system("cls");
}
void ModificarCliente()
{
	system("cls");
	int cod;
	cuadro(35, 0, 84, 2);
	cuadro(35, 3, 84, 20);
	gotoxy(44, 1); cout << "Ingrese el codigo a modificar: ";
	cin >> cod;

	Cliente objCliente1 = ClienteControl->BuscarPorCodigo(cod);
	if (objCliente1.GetNombre() != "ERROR")
	{
		gotoxy(40, 4); cout << "Codigo: " << objCliente1.GetCodigo() << endl;
		gotoxy(40, 5); cout << "Nombre completo: " << objCliente1.GetNombre() << endl;
		gotoxy(40, 6); cout << "Edad: " << objCliente1.GetEdad() << endl;
		gotoxy(40, 7); cout << "DNI: " << objCliente1.GetDni() << endl;
		gotoxy(45, 9); cout << "-----------------------------" << endl;

		string nom; int ed; string dni;
		cin.ignore();
		gotoxy(53, 10); cout << "MODIFICAR DATOS";
		gotoxy(40, 12); cout << "Nombre completo: ";
		getline(cin, nom);
		gotoxy(40, 13); cout << "Edad: ";
		cin >> ed;
		gotoxy(40, 14); cout << "DNI: ";
		cin >> dni;

		Cliente objCliente2(objCliente1.GetCodigo(), nom, ed, dni);
		bool ObjetoModificado = ClienteControl->Modificar(objCliente1, objCliente2);

		if (ObjetoModificado == true)
		{
			gotoxy(43, 17); cout << "Cliente modificado satisfactoriamente\n\n\n\n\n\n";
			ClienteControl->GrabarModificadoAlArchivo();
		}
		else
		{
			gotoxy(43, 18); cout << "Cliente no se pudo modificar\n";
		}
	}
	else
	{
		gotoxy(40, 6); cout << "No se pudo modificar al cliente buscado\n";
	}
	system("pause");
	system("cls");
}
void EliminarCliente()
{
	system("cls");
	int cod;
	cuadro(35, 1, 84, 3);
	cuadro(35, 4, 84, 10);
	gotoxy(40, 2); cout << "Ingrese el codigo a eliminar: ";
	cin >> cod;

	Cliente objCliente = ClienteControl->BuscarPorCodigo(cod);
	if (objCliente.GetNombre() != "ERROR")
	{
		gotoxy(40, 5); cout << "Se pudo eliminar satisfactoriamente" << "\n\n\n\n\n\n";
		ClienteControl->Eliminar(objCliente);
		ClienteControl->GrabarModificadoAlArchivo();
	}
	else
	{
		gotoxy(40, 6); cout << "No se pudo eliminar al cliente buscado"; cout << "\n\n\n\n\n";
	}
	system("pause");
	system("cls");
}
void RegistroDeProductos()
{
	system("cls");
	int otp;
	do
	{
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(51, 1); cout << "REGISTRO DE PRODUCTOS";
		gotoxy(38, 4); cout << "Agregar productos				[1]\n";
		gotoxy(38, 5); cout << "Buscar productos				[2]\n";
		gotoxy(38, 6); cout << "Modificar productos			[3]\n";
		gotoxy(38, 7); cout << "Elminar productos				[4]\n";
		gotoxy(38, 8); cout << "Listar productos				[5]\n";
		gotoxy(38, 9); cout << "Salir					[6]\n\n";
		gotoxy(38, 11); cout << "Ingrese una opcion--> ";
		cin >> otp;

		switch (otp)
		{
		case 1: AgregarProducto(); break;
		case 2: BuscarProducto(); break;
		case 3: ModificarProducto(); break;
		case 4: EliminarProducto(); break;
		case 5: ListarProducto(); break;
		case 6: system("cls"); break;
		default: gotoxy(38, 11); cout << "Escoga una opcion entre [1-6] por favor \n";

		}
	} while (otp != 6);
}
void Categorias()
{
	gotoxy(80, 6); cout << "CATEGORIAS";
	gotoxy(80, 8); cout << "Procesador	[1]\n";
	gotoxy(80, 9); cout << "Placa madre	[2]\n";
	gotoxy(80, 10); cout << "Tarjeta Grafica	[3]\n";
	gotoxy(80, 11); cout << "Memoria RAM	[4]\n";
	gotoxy(80, 12); cout << "Fuente de poder	[5]\n";
	gotoxy(80, 13); cout << "Monitor		[6]\n";
	gotoxy(80, 14); cout << "Perifericos	[7]\n";
	gotoxy(80, 15); cout << "Elija una opcion: ";
}
void AgregarProducto()
{
	string ban;
	do
	{
		system("cls");
		int cod = ProducControl->NumeroCodigo();
		string nom;
		float precio;
		int stock;
		int cate;
		cin.ignore();
		cuadro(30, 0, 100, 2);
		cuadro(30, 3, 100, 25);
		gotoxy(55, 1); cout << "REGISTRO DE PRODUCTO";
		gotoxy(34, 7); cout << "Codigo: " << cod << endl;
		gotoxy(34, 8); cout << "Nombre: ";
		getline(cin, nom);
		gotoxy(34, 9); cout << "Precio: ";
		cin >> precio;
		gotoxy(34, 10); cout << "Stock: ";
		cin >> stock;
		Categorias();
		cin >> cate;

		Producto objProducto(cod, nom, precio, stock, cate);
		ProducControl->AgregarProducto(objProducto);
		ProducControl->GrabarAlArchivo(objProducto);

		gotoxy(40, 22); cout << "Desea agregar otro? (S/s)";
		cin >> ban;
	} while (ban == "S" || ban == "s");
	system("cls");
}
void ListarProducto()
{

	system("cls");
	cuadro(29, 0, 100, 2);
	cuadro(29, 3, 100, 25);
	gotoxy(31, 1); cout << "Codigo";
	gotoxy(46, 1); cout << "Nombre";
	gotoxy(62, 1); cout << "Precio";
	gotoxy(73, 1); cout << "Stock";
	gotoxy(86, 1); cout << "Categoria";
	for (int i = 0; i < ProducControl->Tamanio(); i++)
	{
		gotoxy(45, 4 + i); Categoria objCategoria = CateControl->BuscarPorCodigo(ProducControl->GetObjeto(i).GetCodCate());
		gotoxy(33, 4 + i); cout << ProducControl->GetObjeto(i).GetCodProduc() << "\t";
		gotoxy(45, 4 + i); cout << ProducControl->GetObjeto(i).GetNomProduc() << "\t";
		gotoxy(63, 4 + i); cout << ProducControl->GetObjeto(i).GetPrecioProduc() << "\t";
		gotoxy(74, 4 + i); cout << ProducControl->GetObjeto(i).GetStockProduc() << "\t";
		gotoxy(87, 4 + i); cout << objCategoria.GetNomCate() << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	system("pause");
	system("cls");
}
void BuscarProducto()
{
	system("cls");
	int cod;
	cuadro(35, 1, 84, 3);

	gotoxy(45, 2); cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	Producto objProducto = ProducControl->BuscarPorCodigo(cod);
	Categoria objCategoria = CateControl->BuscarPorCodigo(objProducto.GetCodCate());
	if (objProducto.GetNomProduc() != "ERROR")
	{
		cuadro(35, 4, 84, 14);
		gotoxy(42, 5); cout << "Producto encontrado satisfactoriamente\n\n";
		gotoxy(39, 8); cout << "Codigo: " << objProducto.GetCodProduc() << endl;
		gotoxy(39, 9); cout << "Nombre: " << objProducto.GetNomProduc() << endl;
		gotoxy(39, 10); cout << "Precio: " << objProducto.GetPrecioProduc() << endl;
		gotoxy(39, 11); cout << "Stock: " << objProducto.GetStockProduc() << endl;
		gotoxy(39, 12); cout << "Categoria: " << objCategoria.GetNomCate() << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		gotoxy(45, 4); cout << "No se encontro el producto buscado\n";
	}
	system("pause");
	system("cls");
}
void ModificarProducto()
{
	system("cls");
	int cod;
	cuadro(13, 0, 102, 2);
	gotoxy(43, 1); cout << "Ingrese el codigo a modificar: ";
	cin >> cod;

	Producto objProducto1 = ProducControl->BuscarPorCodigo(cod);
	Categoria objCategoria = CateControl->BuscarPorCodigo(objProducto1.GetCodCate());

	if (objProducto1.GetNomProduc() != "ERROR")
	{
		cuadro(13, 3, 102, 22);
		gotoxy(43, 4); cout << "Producto encontrado satisfactoriamente\n\n";
		gotoxy(17, 6); cout << "Codigo: " << objProducto1.GetCodProduc() << endl;
		gotoxy(17, 8); cout << "Nombre: " << objProducto1.GetNomProduc() << endl;
		gotoxy(17, 9); cout << "Precio: " << objProducto1.GetPrecioProduc() << endl;
		gotoxy(17, 10); cout << "Stock: " << objProducto1.GetStockProduc() << endl;
		gotoxy(17, 11); cout << "Categoria: " << objCategoria.GetNomCate() << endl;

		string nom; float precio; int stock; int cate;
		cin.ignore();
		gotoxy(52, 6); cout << "--> MODIFICAR DATOS <--\n";
		gotoxy(48, 8); cout << "Nombre: ";
		getline(cin, nom);
		gotoxy(48, 9); cout << "Precio: ";
		cin >> precio;
		gotoxy(48, 10); cout << "Stock: ";
		cin >> stock;
		Categorias();
		cin >> cate;

		Producto objProducto2(objProducto1.GetCodProduc(), nom, precio, stock, cate);
		bool ObjetoModificado = ProducControl->Modificar(objProducto1, objProducto2);

		if (ObjetoModificado == true)
		{
			gotoxy(43, 19); cout << "Objeto modificado satisfactoriamente\n\n\n\n\n";
			ProducControl->GrabarModificadoAlArchivo();
		}
		else
		{
			cout << "Objeto no se pudo modificar\n";
		}
	}
	else
	{
		cout << "No se pudo modificar al producto buscado\n";
	}
	system("pause");
	system("cls");
}
void EliminarProducto()
{
	system("cls");
	int cod;
	cuadro(35, 1, 84, 3);
	gotoxy(43, 2); cout << "Ingrese el codigo a eliminar: ";
	cin >> cod;

	Producto objProducto = ProducControl->BuscarPorCodigo(cod);
	if (objProducto.GetNomProduc() != "ERROR")
	{
		cuadro(35, 4, 84, 8);
		gotoxy(43, 6); cout << "Se pudo eliminar satisfactoriamente\n";
		ProducControl->Eliminar(objProducto);
		ProducControl->GrabarModificadoAlArchivo();
	}
	else
	{
		gotoxy(40, 4); cout << "No se pudo eliminar al cliente buscado\n";
	}
	system("pause");
	system("cls");
}
void RegistroDePersonal() {
	system("cls");
	int otp;
	do
	{
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(52, 1); cout << "REGISTRO PERSONAL";
		gotoxy(38, 5); cout << "Agregar personal				[1]\n";
		gotoxy(38, 6); cout << "Buscar personal				[2]\n";
		gotoxy(38, 7); cout << "Modificar personal			[3]\n";
		gotoxy(38, 8); cout << "Elminar personal				[4]\n";
		gotoxy(38, 9); cout << "Listar personal				[5]\n";
		gotoxy(38, 10); cout << "Salir					[6]\n\n";
		gotoxy(38, 12); cout << "Ingrese una opcion: ";
		cin >> otp;

		switch (otp)
		{
		case 1: AgregarPersonal(); break;
		case 2: BuscarPersonal(); break;
		case 3: ModificarPersonal(); break;
		case 4: EliminarPersonal(); break;
		case 5: ListarPersonal(); break;
		case 6: cout << system("cls"); break;
		gotoxy(40, 13); default: cout << "Escoga una opcion entre [1-6] por favor ";
		}
	} while (otp != 6);
}
void TiposPerson() {
	gotoxy(82, 6); cout << "TIPOS DE PERSONAL";
	gotoxy(82, 8); cout << "Administrador		[1]\n";
	gotoxy(82, 9); cout << "Coordinador		[2]\n";
	gotoxy(82, 10); cout << "Practicante		[3]\n";
	gotoxy(82, 11); cout << "Supervisor		[4]\n";

	gotoxy(82, 13); cout << "Elija una opcion: ";
}
void AgregarPersonal() {
	string ban;
	do
	{
		system("cls");
		int cod = PersonControl->NumeroCodigo();
		string nom;
		string usu;
		string contra;
		int codtipo;
		cin.ignore();
		cuadro(15, 0, 110, 2);
		cuadro(15, 3, 110, 20);
		gotoxy(52, 1); cout << "REGISTRO DE PERSONAL";
		gotoxy(17, 6); cout << "Codigo: " << cod << endl;
		gotoxy(17, 7); cout << "Nombre Completo: ";
		getline(cin, nom);
		cin.ignore();
		gotoxy(17, 8); cout << "Usuario: ";
		cin >> usu;
		gotoxy(17, 9); cout << "Password: ";
		cin >> contra;
		TiposPerson();
		cin >> codtipo;

		Personal objPerso(cod, nom, usu, contra, codtipo);
		PersonControl->AgregarPersonal(objPerso);
		PersonControl->GrabarAlArchivo(objPerso);

		gotoxy(40, 17); cout << "Desea agregar otro? (S/s)";
		cin >> ban;
	} while (ban == "S" || ban == "s");
	system("pause");
	system("cls");
}
void ListarPersonal()
{
	system("cls");
	cuadro(29, 0, 100, 2);
	cuadro(29, 3, 100, 25);
	gotoxy(31, 1); cout << "Codigo";
	gotoxy(45, 1); cout << "Nombre";
	gotoxy(62, 1); cout << "Usuario";
	gotoxy(73, 1); cout << "Password";
	gotoxy(88, 1); cout << "Tipo";

	for (int i = 0; i < PersonControl->Tamanio(); i++)
	{
		gotoxy(45, 4 + i); TipoPersonal objPersonal = TipoPersoControl->BuscarPorCodigo(PersonControl->GetObjeto(i).GetCodigoTipoPer());
		gotoxy(33, 4 + i); cout << PersonControl->GetObjeto(i).GetCodigoPersonal();
		gotoxy(44, 4 + i); cout << PersonControl->GetObjeto(i).GetNombrePersonal();
		gotoxy(63, 4 + i); cout << PersonControl->GetObjeto(i).GetUsuarioPersonal();
		gotoxy(74, 4 + i); cout << PersonControl->GetObjeto(i).GetPassPersonal();
		gotoxy(87, 4 + i); cout << objPersonal.GetNomTipPersonal() << "\n\n\n\n\n\n";
	}
	system("pause");
	system("cls");
}
void BuscarPersonal() {
	system("cls");
	int cod;
	cuadro(35, 0, 84, 2);
	string ban;
	gotoxy(43, 1); cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	Personal objPersonal = PersonControl->BuscarPorCodigo(cod);
	TipoPersonal objTipoPersonal = TipoPersoControl->BuscarPorCodigo(objPersonal.GetCodigoTipoPer());
	if (objPersonal.GetNombrePersonal() != "ERROR")
	{
		cuadro(35, 3, 84, 20);
		gotoxy(41, 5); cout << "Codigo: " << objPersonal.GetCodigoPersonal() << endl;
		gotoxy(41, 6); cout << "Nombre: " << objPersonal.GetNombrePersonal() << endl;
		gotoxy(41, 7); cout << "Usuario: " << objPersonal.GetUsuarioPersonal() << endl;
		gotoxy(41, 8); cout << "Contrasenia: " << objPersonal.GetPassPersonal() << endl;
		gotoxy(41, 9); cout << "Tipo: " << objTipoPersonal.GetNomTipPersonal() << endl << endl;
		gotoxy(41, 11); cout << "Personal encontrado satisfactoriamente\n";
		system("pause");
		system("cls");
	}
}
void ModificarPersonal() {
	system("cls");
	int cod;
	cuadro(15, 0, 110, 2);
	cuadro(15, 3, 110, 20);
	gotoxy(40, 1); cout << "Ingrese el codigo a modificar: ";
	cin >> cod;

	Personal objPersonal = PersonControl->BuscarPorCodigo(cod);
	TipoPersonal objTipoPersonal = TipoPersoControl->BuscarPorCodigo(objPersonal.GetCodigoTipoPer());

	if (objPersonal.GetNombrePersonal() != "ERROR")
	{
		gotoxy(43, 4); cout << "Personal encontrado satisfactoriamente\n";
		gotoxy(17, 6); cout << "Codigo: " << objPersonal.GetCodigoPersonal() << endl;
		gotoxy(17, 8); cout << "Nombre: " << objPersonal.GetNombrePersonal() << endl;
		gotoxy(17, 9); cout << "Usuario: " << objPersonal.GetUsuarioPersonal() << endl;
		gotoxy(17, 10); cout << "Contrasenia: " << objPersonal.GetPassPersonal() << endl;
		gotoxy(17, 11); cout << "Tipo: " << objTipoPersonal.GetNomTipPersonal() << endl;

		string nom; string usu; string contra; int codtipo;
		cin.ignore();
		gotoxy(53, 6); cout << "MODIFICAR DATOS";
		gotoxy(48, 8); cout << "Nombre: ";
		getline(cin, nom);
		cin.ignore();
		gotoxy(48, 9); cout << "Usuario: ";
		getline(cin, usu);
		cin.ignore();
		gotoxy(48, 10); cout << "Password: ";
		getline(cin, contra);
		cin.ignore();
		TiposPerson();
		cin >> codtipo;

		Personal objPerso2(objPersonal.GetCodigoPersonal(), nom, usu, contra, codtipo);
		bool ObjetoModificado = PersonControl->Modificar(objPersonal, objPerso2);

		if (ObjetoModificado == true)
		{
			gotoxy(43, 15); cout << "\nObjeto modificado satisfactoriamente" "\n\n\n\n\n\n\n\n\n";
			PersonControl->GrabarModificadoAlArchivo();
		}
		else
		{
			cout << "\nObjeto no se pudo modificar\n";
		}
	}
	else
	{
		cout << "\nNo se pudo modificar al cliente buscado\n";
	}
	system("pause");
	system("cls");
}
void EliminarPersonal() {
	system("cls");
	int cod;
	cout << "Ingrese el codigo del personal a eliminar:";
	cin >> cod;

	Personal objPersonal = PersonControl->BuscarPorCodigo(cod);
	if (objPersonal.GetNombrePersonal() != "ERROR")
	{
		cout << "Se pudo eliminar satisfactoriamente";
		PersonControl->Eliminar(objPersonal);
		PersonControl->GrabarModificadoAlArchivo();
	}
	else
	{
		cout << "No se pudo eliminar el personal buscado";
	}
	system("pause");
	system("cls");
}
void RegistroDeVenta()
{
	system("cls");
	int otp;
	do
	{
		cuadro(35, 0, 84, 2);
		cuadro(35, 3, 84, 20);
		gotoxy(52, 1); cout << "REGISTRO DE VENTA";
		gotoxy(38, 5); cout << "Agregar venta				[1]\n";
		gotoxy(38, 6); cout << "Buscar venta				[2]\n";
		gotoxy(38, 9); cout << "Salir					[3]\n\n";
		gotoxy(38, 11); cout << "Ingrese una opcion: ";
		cin >> otp;

		switch (otp)
		{
		case 1: AgregarVenta(); break;
		case 2: BuscarVenta(); break;
		case 3: cout << system("cls"); break;
		gotoxy(40, 13); default: cout << "Escoga una opcion entre [1-4] por favor ";
		}
	} while (otp != 3);
}
void AgregarVenta()
{
	system("cls");
	int codventa = VentaControl->NumeroCodigo();
	string fecha = "23/11/2022";
	string estado = "Activo";
	float totalventa = 0;
	float precioventa;
	int codcliente;
	int codpersonal;
	int codproduc;
	int cant;
	cuadro(20, 0, 106, 2);
	cuadro(20, 4, 106, 50);
	gotoxy(54, 1); cout << "VENTA DE LOS PRODUCTOS";
	gotoxy(35, 5); cout << "Codigo: " << codventa << endl;
	gotoxy(70, 5); cout << "Fecha: " << fecha << endl;
	gotoxy(35, 6); cout << "Estado: " << estado << "\n\n";
	gotoxy(25, 8); cout << "Ingrese el codigo de cliente: ";
	cin >> codcliente;

	Cliente cliente = ClienteControl->BuscarPorCodigo(codcliente);
	gotoxy(25, 10); cout << "Nombre: " << cliente.GetNombre() << endl;
	gotoxy(25, 11); cout << "Edad: " << cliente.GetEdad() << endl;
	gotoxy(25, 12); cout << "DNI: " << cliente.GetDni() << endl << endl;

	gotoxy(70, 8); cout << "Ingrese el codigo de personal: ";
	cin >> codpersonal;
	Personal personal = PersonControl->BuscarPorCodigo(codpersonal);
	TipoPersonal tipopersonal = TipoPersoControl->BuscarPorCodigo(personal.GetCodigoTipoPer());
	gotoxy(70, 10); cout << "Nombre: " << personal.GetNombrePersonal() << endl;
	gotoxy(70, 11); cout << "Usuario: " << personal.GetUsuarioPersonal() << endl;
	gotoxy(70, 12); cout << "Trabajo: " << tipopersonal.GetNomTipPersonal() << endl << endl;

	gotoxy(25, 14); cout << "-----------------------------------------------------------------------------";
	string ban;
	string ban2;
	do {
		do {
			gotoxy(55, 16); cout << "PRODUCTOS EN VENTA";
			gotoxy(40, 18); cout << "Codigo";
			gotoxy(53, 18); cout << "Nombre";
			gotoxy(70, 18); cout << "Precio";
			gotoxy(81, 18); cout << "Stock";
			for (int i = 0; i < ProducControl->Tamanio(); i++) {
				gotoxy(42, 19 + i); cout << ProducControl->GetObjeto(i).GetCodProduc() << "\t";
				gotoxy(50, 19 + i); cout << ProducControl->GetObjeto(i).GetNomProduc() << "\t";
				gotoxy(71, 19 + i); cout << ProducControl->GetObjeto(i).GetPrecioProduc() << "\t";
				gotoxy(83, 19 + i); cout << ProducControl->GetObjeto(i).GetStockProduc() << endl;
			}
			gotoxy(35, 32); cout << "Ingrese el codigo del producto a comprar: ";
			cin >> codproduc;

			Producto producto = ProducControl->BuscarPorCodigo(codproduc);
			if (producto.GetNomProduc() == "ERROR") {
				gotoxy(35, 34); cout << "Producto no encontrado";
				system("pause");
				system("cls");
			}
			else {
				gotoxy(52, 34); cout << "Producto encontrado";
				gotoxy(35, 35); cout << "Codigo: " << producto.GetCodProduc() << endl;
				gotoxy(35, 36); cout << "Nombre: " << producto.GetNomProduc() << endl;
				gotoxy(35, 37); cout << "Precio: " << producto.GetPrecioProduc() << endl;
				gotoxy(35, 38); cout << "Stock: " << producto.GetStockProduc() << endl;
			}
			gotoxy(35, 40); cout << "Ingrese la cantidad que llevara: ";
			cin >> cant;
			precioventa = cant * producto.GetPrecioProduc();
			gotoxy(35, 41); cout << "Confirma la compra de este producto? (S/s): ";
			cin >> ban2;
			if (ban2 == "S" || ban2 == "s") {
				DetallesDeVenta detalle(codventa, codproduc, cant, precioventa);
				DetalleVenControl->AgregarDetalleDeVenta(detalle);
				DetalleVenControl->GrabarAlArchivo(detalle);
				totalventa += detalle.GetPrecioVenta();
				Producto producto2(producto.GetCodProduc(), producto.GetNomProduc(), producto.GetPrecioProduc(), producto.GetStockProduc() - cant, producto.GetCodCate());
				bool comproba = ProducControl->Modificar(producto, producto2);
				if (comproba == true)
				{
					ProducControl->GrabarModificadoAlArchivo();
				}
			}
		} while (ban2 == "N" || ban2 == "n");
		gotoxy(35, 42); cout << "Desea agregar otro producto? (S/s): ";
		cin >> ban;
		if (ban == "N" || ban == "n") {
			Ventas venta(codventa, fecha, totalventa, estado, codcliente, codpersonal);
			VentaControl->AgregarVenta(venta);
			VentaControl->GrabarAlArchivo(venta);
			system("cls");
		}
		else {
			system("cls");
		}
	} while (ban == "S" || ban == "s");
	Factura(fecha, codcliente, codpersonal, codventa);
}
void Factura(string fecha, int codcliente, int codpersonal, int codventa)
{
	int q = 0;

	gotoxy(34, 11); cout << "ESPERE UN RATO... ESTAMOS GENERANDO SU FACTURA" << endl;

	system("pause");
	system("cls");
	cuadro(38, 0, 90, 2);
	cuadro(38, 3, 90, 50);
	gotoxy(56, 1); cout << "FACTURA DE VENTA" << endl;
	gotoxy(40, 4); cout << "Fecha: " << fecha << endl;
	gotoxy(40, 5); cout << "--------------------------------------" << endl;
	Cliente cliente = ClienteControl->BuscarPorCodigo(codcliente);
	gotoxy(40, 6); cout << "Nombre del cliente: " << cliente.GetNombre() << endl;
	gotoxy(40, 7); cout << "--------------------------------------" << endl;
	Personal personal = PersonControl->BuscarPorCodigo(codpersonal);
	TipoPersonal tipopersonal = TipoPersoControl->BuscarPorCodigo(personal.GetCodigoTipoPer());
	gotoxy(40, 8); cout << "Nombre del Vendedor: " << personal.GetNombrePersonal() << endl;
	gotoxy(40, 9); cout << "Cargo del vendedor: " << tipopersonal.GetNomTipPersonal() << endl;
	gotoxy(40, 10); cout << "--------------------------------------" << endl << endl;

	gotoxy(60, 12); cout << "PRODUCTOS" << endl;
	for (int i = 0; i < DetalleVenControl->Tamanio(); i++)
	{
		if (codventa == DetalleVenControl->GetObjeto(i).GetCodVenta()) {
			Producto producto = ProducControl->BuscarPorCodigo(DetalleVenControl->GetObjeto(i).GetCodProducto());
			Categoria categoria = CateControl->BuscarPorCodigo(producto.GetCodCate());
			gotoxy(40, 14 + q); cout << "Producto: " << producto.GetNomProduc() << endl;
			gotoxy(40, 15 + q); cout << "Cantidad: " << DetalleVenControl->GetObjeto(i).GetCantidad() << endl;
			gotoxy(40, 16 + q); cout << "Categoria del producto: " << categoria.GetNomCate() << endl;
			gotoxy(40, 17 + q); cout << "El precio por lo adquirido es s/: " << DetalleVenControl->GetObjeto(i).GetPrecioVenta() << endl;
			gotoxy(40, 19 + q); cout << "------------------------------------------------" << endl;
			q += 6;
		}
	}
	Ventas venta = VentaControl->BuscarPorCodigo(codventa);
	gotoxy(40, 15 + q); cout << "El precio total es s/: " << venta.GetTotalVenta() << "\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
void BuscarVenta()
{
	system("cls");
	int cod;
	cuadro(35, 0, 84, 2);
	string ban;
	gotoxy(43, 1); cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	Ventas venta = VentaControl->BuscarPorCodigo(cod);
	//
	int q = 0;

	gotoxy(34, 11); cout << "ESPERE UN RATO... ESTAMOS GENERANDO SU FACTURA" << endl;

	system("pause");
	system("cls");
	cuadro(38, 0, 90, 2);
	cuadro(38, 3, 90, 50);
	gotoxy(56, 1); cout << "FACTURA DE VENTA" << endl;
	gotoxy(40, 4); cout << "Fecha: " << venta.GetFechaVenta() << endl;
	gotoxy(40, 5); cout << "--------------------------------------" << endl;
	Cliente cliente = ClienteControl->BuscarPorCodigo(venta.GetCodCliente());
	gotoxy(40, 6); cout << "Nombre del cliente: " << cliente.GetNombre() << endl;
	gotoxy(40, 7); cout << "--------------------------------------" << endl;
	Personal personal = PersonControl->BuscarPorCodigo(venta.GetCodPersonal());
	TipoPersonal tipopersonal = TipoPersoControl->BuscarPorCodigo(personal.GetCodigoTipoPer());
	gotoxy(40, 8); cout << "Nombre del Vendedor: " << personal.GetNombrePersonal() << endl;
	gotoxy(40, 9); cout << "Cargo del vendedor: " << tipopersonal.GetNomTipPersonal() << endl;
	gotoxy(40, 10); cout << "--------------------------------------" << endl << endl;

	gotoxy(60, 12); cout << "PRODUCTOS" << endl;
	for (int i = 0; i < DetalleVenControl->Tamanio(); i++)
	{
		if (cod == DetalleVenControl->GetObjeto(i).GetCodVenta()) {
			Producto producto = ProducControl->BuscarPorCodigo(DetalleVenControl->GetObjeto(i).GetCodProducto());
			Categoria categoria = CateControl->BuscarPorCodigo(producto.GetCodCate());
			gotoxy(40, 14 + q); cout << "Producto: " << producto.GetNomProduc() << endl;
			gotoxy(40, 15 + q); cout << "Cantidad: " << DetalleVenControl->GetObjeto(i).GetCantidad() << endl;
			gotoxy(40, 16 + q); cout << "Categoria del producto: " << categoria.GetNomCate() << endl;
			gotoxy(40, 17 + q); cout << "El precio por lo adquirido es s/: " << DetalleVenControl->GetObjeto(i).GetPrecioVenta() << endl;
			gotoxy(40, 19 + q); cout << "------------------------------------------------" << endl;
			q += 6;
		}

	}
	gotoxy(40, 15 + q); cout << "El precio total es s/: " << venta.GetTotalVenta() << "\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	for (i = x1; i < x2; i++)
	{
		gotoxy(i, y1), cout << "\304";
		gotoxy(i, y2), cout << "\304";

	}

	for (i = y1; i < y2; i++)
	{
		gotoxy(x1, i), cout << "\263";
		gotoxy(x2, i), cout << "\263";
	}

	gotoxy(x1, y1); cout << "\332";
	gotoxy(x1, y2); cout << "\300";
	gotoxy(x2, y1); cout << "\277";
	gotoxy(x2, y2); cout << "\331";

}
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
