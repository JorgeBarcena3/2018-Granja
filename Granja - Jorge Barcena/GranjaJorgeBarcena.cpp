// GranjaJorgeBarcena.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Vaquita.cpp"
#include "Gallinita.cpp"
#include <cstddef>   // size_t
#include <string>
#include <iostream>
#include <stdexcept> // runtime_error
#include <cstdlib>   // rand()

using namespace std;


Animal* posicionAnimal(const string& nombre, Animal** ab, Animal** ae) {

	if (ab == nullptr || ae == nullptr || ab >= ae)
		throw runtime_error{ "Invalid parameters" };

	for (; ab < ae && nombre != (*ab)->getId(); ab++);

	return ab == ae ? nullptr : *ab;
}

void mostrarGranja(Animal** gb, Animal** ge) {

	cout << "---------------------" << endl;
	cout << " Estado de la granja " << endl;
	cout << "---------------------" << endl;

	for (; gb < ge; gb++)
		cout << (*gb)->getId() << ": " << (*gb)->getCapacidadActual() << " " << (*gb)->getTipoAlimento() << endl;
}

int main() {

	const size_t numVaquitas{ 3 };
	const size_t numGallinitas{ 7 };
	const size_t numAnimales{ numVaquitas + numGallinitas };

	size_t i{ 0 };

	Animal* animales[numAnimales];
	Animal** const animales_begin{ animales };
	Animal** const animales_end{ animales + numAnimales };

	Vaquita
		campanera{ "Campanera", 10 },
		barrueca{ "Barrueca",  15 },
		berraka{ "Berraka",   20 };

	animales[0] = &campanera;
	animales[1] = &barrueca;
	animales[2] = &berraka;

	for (i = numVaquitas; i < numAnimales / 2; i++)
		animales[i] = new Gallinita{ i };

	for (; i < numAnimales; i++)
		animales[i] = new Gallinita{ i, 6 };

	size_t rondas{ 10 };

	while (rondas > 0) {

		size_t semilla{ static_cast<size_t>(rand() % 10 + 1) };

		mostrarGranja(animales_begin, animales_end);

		try {

			for (Animal** a{ animales_begin }; a < animales_end; a++)
				(*a)->explotar(semilla);

		}
		catch (AnimalTieneHambre& e) {

			cout << e.what() << endl;
			Animal* a{ posicionAnimal(e.getId(), animales_begin, animales_end) };
			if (a == nullptr) throw runtime_error{ "¿Pero de qué vas?" };

			a->alimentar(semilla);
			cout << "Alimento para " << a->getId() << ": " << semilla << endl;;
		}

		rondas--;
	}

	for (Animal** gallinaPtrPtr{ animales_begin + numVaquitas }; gallinaPtrPtr < animales_end; gallinaPtrPtr++) {

		delete dynamic_cast<Gallinita*>(*gallinaPtrPtr);
	}

	cin.get();

	return 0;
}
