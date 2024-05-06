#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;

class Reserva {
private:
	string 	id;
	string	restaurante;
    string hora;
    string comidas;

public:
	Reserva(string _id) {
		id = _id;
		restaurante	= "";
		hora = "00:00";
	}

	Reserva(string _id, string _restaurante, string _hora, string _comidas) {
		id = _id;
		restaurante	= _restaurante;
		hora = _hora;
		comidas = _comidas;
	}

	void setReserva(string _restaurante, string _hora, string _comidas) {
		restaurante	= _restaurante;
		hora = _hora;
		comidas = _comidas;
	}

	string getRestaurante() {
		return(restaurante);
	}

	string getComidas() {
		return comidas;
	}

	void guardarArchivo(ofstream &fsalida) {
	    fsalida.write(reinterpret_cast<char *>(&id), sizeof(id));
		fsalida.write(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
		fsalida.write(reinterpret_cast<char *>(&hora), sizeof(hora));
        fsalida.write(reinterpret_cast<char *>(&comidas), sizeof(comidas));
	}

	bool leerArchivo(ifstream &fentrada) {
		bool k = false;
		if (fentrada.is_open() == true) {
			fentrada.read(reinterpret_cast<char *>(&id), sizeof(id));
			if (fentrada.eof() == false) {
				fentrada.read(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
                fentrada.read(reinterpret_cast<char *>(&hora), sizeof(hora));
                fentrada.read(reinterpret_cast<char *>(&comidas), sizeof(comidas));
				k = true;
			}else {
				//cout << endl << "Registro no existe";
			}
		}else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	bool eliminar(fstream &fes, int nroReg){
		bool k = false;
		if (fes.is_open() == true) {
			fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.read(reinterpret_cast<char *>(&id), sizeof(id));
			if (fes.eof() == false) {
				fes.read(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
                fes.read(reinterpret_cast<char *>(&hora), sizeof(hora));
                fes.read(reinterpret_cast<char *>(&comidas), sizeof(comidas));


				fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
				fes.write(reinterpret_cast<char *>(&id), sizeof(id));
                fes.write(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
                fes.write(reinterpret_cast<char *>(&hora), sizeof(hora));
                fes.write(reinterpret_cast<char *>(&comidas), sizeof(comidas));
				k = true;
			}else {
				cout << endl << "Registro no existe";
			}
		}else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}


	bool modificar(fstream &fes, int nroReg){
		bool k = false;
		if (fes.is_open() == true) {
			string idAux;
			idAux=id;
			fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.read(reinterpret_cast<char *>(&id), sizeof(id));
			if (fes.eof() == false) {
				id=idAux;
				fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
				fes.write(reinterpret_cast<char *>(&id), sizeof(id));
                fes.write(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
                fes.write(reinterpret_cast<char *>(&hora), sizeof(hora));
                fes.write(reinterpret_cast<char *>(&comidas), sizeof(comidas));
				k = true;
			}else {
				cout << endl << "Registro no existe";
			}
		}else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	bool buscar(ifstream &fentrada, int nroReg) {
		bool k = false;
		if (fentrada.is_open() == true) {
			fentrada.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fentrada.read(reinterpret_cast<char *>(&id), sizeof(id));
			fentrada.read(reinterpret_cast<char *>(&restaurante), sizeof(restaurante));
            fentrada.read(reinterpret_cast<char *>(&hora), sizeof(hora));
            fentrada.read(reinterpret_cast<char *>(&comidas), sizeof(comidas));
			if (fentrada.eof() == false) {
				k = true;
			}
			else {
				//cout << endl << "Registro no XX existe";
			}
		}
		else {
			cout << endl << "Arhivo no existe";
		}
		return(k);
	}

	int getTamBytesRegistro() {
		return(sizeof(id) + sizeof(restaurante) + sizeof(hora) + sizeof(comidas));
	}

};

class DatosAdmin{
private:
	string  nomArchivo;
	Reserva *reserva;
	int id;

public:

	DatosAdmin(string nomArch){
		nomArchivo=nomArch;
		id = 0;
	}

	void introducirDatos(Reserva *newReg) {
        string	restaurante;
        string hora;
        string comidas;
		cout <<endl<<endl<<"Introducir los siguientes datos --->>> :"<<endl;
		fflush( stdin );
		cout << "Restaurante : ";
		cin >> restaurante;
		cout << "hora";
		cin >> hora;
		cout << "comidas";
		getline(cin, comidas);
        newReg->setReserva(restaurante, hora, comidas);
	}


	void mostrarRegistro(int nroReg){
		cout << endl << nroReg << ".-  " << reserva->getRestaurante();

	}
	void adicionarNuevo() {
		ofstream fsalida(nomArchivo, ios::app | ios::binary);
		reserva = new Reserva(to_string(id++));
		introducirDatos(reserva);
		reserva->guardarArchivo(fsalida);
		fsalida.close();
	}

	void listar() {
		int cr = 0;
		cout << endl<<endl << "Los registros son --->>> : " << endl;
		reserva = new Reserva(0);
		ifstream fentrada(nomArchivo, ios::in | ios::binary);
		while (reserva->leerArchivo(fentrada) == true) {
			cr++;
            mostrarRegistro(cr);
		}
		fentrada.close();
	}

	int buscarReg() {
		int nroReg;
		cout << endl<<endl<< "Introducir numero de registro a buscar :  ";
		cin >> nroReg;
		reserva = new Reserva(0);
		ifstream fentrada(nomArchivo, ios::in | ios::binary);
		if(reserva->buscar(fentrada,nroReg) == true) {
			mostrarRegistro(nroReg);
		} else {
			cout << endl << "Registro no existe";
			nroReg=-1;
		}
		fentrada.close();
		return(nroReg);
	}

	void eliminarReg() {
		int nroReg;
		nroReg = buscarReg();
		if(nroReg > 0){
			fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
			reserva = new Reserva("0");
			if (reserva->eliminar(fes, nroReg) == true) {
				cout << endl << "Registro eliminado correctmente "<<endl;
			} else {
				cout << endl << "Registro no existe pa eliminar"<<endl;
			}
			fes.close();
		}
	}

	void modificarReg() {
		int nroReg;
		nroReg = buscarReg();
		if(nroReg>0){
			fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
			reserva = new Reserva(0);
			introducirDatos(reserva);
			if (reserva->modificar(fes, nroReg) == true) {
				cout << endl << "modificado correctamente... "<< endl ;
			} else {
				cout << endl << "Registro no existe pa modificar";
			}
			fes.close();
		}

	}

};

int main() {
	DatosAdmin *amig = new DatosAdmin("amigOO.dat");
	amig->adicionarNuevo();
	amig->listar();
	//amig->buscarReg();
	//amig->eliminarReg();
	//amig->modificarReg();
	//amig->listar();
	getch();
}
