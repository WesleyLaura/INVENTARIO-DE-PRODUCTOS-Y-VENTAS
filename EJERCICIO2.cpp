/*2. Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar
productos, así como gestionar las ventas.

Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad
(entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
A: Registrar un nuevo producto.
B: Listar los productos registrados.
C: Buscar un producto por nombre.
D: Actualizar los datos de un producto.
E: Eliminar un producto.
F: Registrar una venta.
G: Listar las ventas realizadas.
H: Calcular el total de ventas realizadas.
S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción. */

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

const int MAX_PRODUCTOS = 100;
const int MAX_VENTAS = 100;

Producto productos[MAX_PRODUCTOS];
Venta ventas[MAX_VENTAS];

int numProductos = 0;
int numVentas = 0;
int nextVentaId = 1;

void registrarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        cout << "Ingrese el nombre del producto: ";
        cin >> productos[numProductos].nombre;
        cout << "Ingrese el precio del producto: ";
        cin >> productos[numProductos].precio;
        numProductos++;
        cout << "Producto registrado exitosamente.\n";
    } else {
        cout << "No se pueden registrar más productos. Capacidad máxima alcanzada.\n";
    }
}
void listarProductos() {
    for (int i = 0; i < numProductos; i++) {
        cout << "Nombre: " << productos[i].nombre << ", Precio: "<<"$ " << productos[i].precio << "\n";
    }
}

void buscarProducto() {
    string nombre;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin >> nombre;
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            cout << "Nombre: " << productos[i].nombre << ", Precio: " << productos[i].precio << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void actualizarProducto() {
    string nombre;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> nombre;
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            cout << "Ingrese el nuevo nombre del producto: ";
            cin >> productos[i].nombre;
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> productos[i].precio;
            cout << "Producto actualizado exitosamente.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void eliminarProducto() {
    string nombre;
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin >> nombre;
    int i;
    for (i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            break;
        }
    }
    if (i < numProductos) {
        for (int j = i; j < numProductos - 1; j++) {
            productos[j] = productos[j + 1];
        }
        numProductos--;
        cout << "Producto eliminado exitosamente.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    int op;
    do {
        cout << "\n---------------------MENÚ DE OPCIONES----------------------\n";
        cout << "1: Registrar un nuevo producto.\n";
        cout << "2: Listar los productos registrados.\n";
        cout << "3: Buscar un producto por nombre.\n";
        cout << "4: Actualizar los datos de un producto.\n";
        cout << "5: Eliminar un producto.\n";
        /*cout << "6: Registrar una venta.\n";
        cout << "7: Listar las ventas realizadas.\n";
        cout << "8: Calcular el total de ventas realizadas.\n";
        cout << "9: Salir del programa.\n";*/
        cout << "\nSeleccione una opción: ";
        cin >> op;

        switch (op) {
            case 1 :
                registrarProducto();
                break;
            case 2 :
                listarProductos();
                break;
            case 3 :
                buscarProducto();
                break;
            case 4 :
                actualizarProducto();
                break;
            case 5 :
                eliminarProducto();
                break;
            /*case 6 :
                registrarVenta();
                break;
            case 7 :
                listarVentas();
                break;
            case 8 :
                calcularTotalVentas();
                break;
            case 9 :
                cout << "Saliendo del programa...\n";
                break;*/
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
        
    } while (op != 9);

    return 0;
}
