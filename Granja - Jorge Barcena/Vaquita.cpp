
#include "stdafx.h"
#include <cstddef>  // size_t
#include <string>
#include <algorithm> // max, min
#include "Animal.cpp"

using namespace std;


class Vaquita : public Animal {

public:

	Vaquita() = delete;
	Vaquita(const Vaquita&) = delete;
	Vaquita(Vaquita&&) = delete;
	Vaquita& operator=(const Vaquita&) = delete;
	Vaquita& operator=(Vaquita&&) = delete;
	~Vaquita() = default;

	Vaquita(const string id, const size_t capacity) : Animal("Vaquita " + id, capacity) {

	}

	void explotar(const size_t cantidad) /* override */ {

		if (cantidad > actual) throw AnimalTieneHambre{ this };
		actual -= cantidad;

	}

	string getTipoAlimento() const noexcept /* override */ {

		return "litros";
	}
};
