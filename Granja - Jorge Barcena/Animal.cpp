#pragma once

#include "stdafx.h"
#include <cstddef>   // size_t
#include <string>
#include <algorithm> // min

using namespace std;

class AnimalTieneHambre; // forward reference

class Animal {

public:

	Animal() = delete;
	Animal(const Animal&) = delete;
	Animal(Animal&&) = delete;
	Animal& operator=(const Animal&) = delete;
	Animal& operator=(Animal&&) = delete;
	~Animal() = default;

	Animal(const string id, const size_t maximo) : id{ id }, maximo{ maximo }, actual{ maximo } {
	}

	size_t getCapacidadActual() const noexcept {

		return actual;
	}

	string getId() const noexcept {

		return id;
	}

	void alimentar(const size_t comida) {

		actual = min(actual + comida, maximo);
	}

	virtual void explotar(const size_t cantidad) = 0;

	virtual string getTipoAlimento() const noexcept = 0;

protected:

	string id;
	const size_t maximo;
	size_t actual;

};

class AnimalTieneHambre {

private:

	Animal* a;

public:

	AnimalTieneHambre() = delete;
	AnimalTieneHambre(const AnimalTieneHambre&) = delete;
	AnimalTieneHambre(AnimalTieneHambre&&) = default;
	AnimalTieneHambre& operator=(const AnimalTieneHambre&) = delete;
	AnimalTieneHambre& operator=(AnimalTieneHambre&&) = delete;
	~AnimalTieneHambre() = default;

	explicit AnimalTieneHambre(Animal* a) : a{ a } {
	}

	string getId() const noexcept {

		return a->getId();
	}

	string what() const noexcept {

		return a->getId() + " tiene hambre";
	}
};
