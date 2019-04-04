
#include "stdafx.h"
#include <cstddef>  // size_t
#include <string>
#include <algorithm>  // max, min
#include "Animal.cpp"

using namespace std;


class Gallinita : public Animal {

public:

	Gallinita() = delete;
	Gallinita(const Gallinita&) = delete;
	Gallinita(Gallinita&&) = delete;
	Gallinita& operator=(const Gallinita&) = delete;
	Gallinita& operator=(Gallinita&&) = delete;
	~Gallinita() = default;

	explicit Gallinita(const size_t num) : Animal("Gallinita " + to_string(num), 12) {

	}

	Gallinita(const size_t num, const size_t huevosMaximo) : Animal("Gallinita " + to_string(num), huevosMaximo) {

	}

	void explotar(const size_t cantidad) /* override */ {

		if (actual == 0) throw AnimalTieneHambre{ this };
		actual = static_cast<size_t>(max(static_cast<int>(actual - cantidad), 0));

	}

	string getTipoAlimento() const noexcept /* override */ {

		return "huevos";
	}
};
