#include "SortElem.h"

Elem::Elem() {

	active = false;

}

Elem::Elem(int x, int y, int height, int width) : QRect(x, y, height, width) {

	active = false;

}

bool Elem::isActive() const noexcept {

	return active;

}

void Elem::setActive() noexcept {

	active = true;

}

void Elem::setInactive() noexcept {

	active = false;

}

Elem& Elem::operator=(const Elem& el) {
	
	if (&el == this) 
		return *this;
	
	setTop(el.top());

	return *this;

}

bool operator < (const Elem& el1, const Elem& el2) noexcept {

	return el1.height() < el2.height();

}

bool operator <= (const Elem& el1, const Elem& el2) noexcept {

	return el1.height() <= el2.height();

}

bool operator > (const Elem& el1, const Elem& el2) noexcept {
	
	return !(el1 < el2);

}

bool operator >= (const Elem& el1, const Elem& el2) noexcept {

	return !(el1 <= el2);

}
