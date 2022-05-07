#include "SortElem.h"

Elem::Elem() {

	rect = QRect(0, 0, -1, -1);
	active = false;

}

Elem::Elem(int x, int y, int height, int width) {

	rect = QRect(x, y, height, width);
	active = false;

}

QRect Elem::getRect() const noexcept {

	return rect;

}

int Elem::getTop() const noexcept {

	return rect.top();

}

int Elem::getHeight() const noexcept {

	return rect.height();

}

bool Elem::isActive() const noexcept {

	return active;

}

void Elem::setTop(int h) noexcept {

	rect.setTop(h);

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
	
	this->setTop(el.getTop());

	return *this;

}

bool operator < (const Elem& el1, const Elem& el2) noexcept {

	return el1.getHeight() < el2.getHeight();

}

bool operator <= (const Elem& el1, const Elem& el2) noexcept {

	return el1.getHeight() <= el2.getHeight();

}

bool operator > (const Elem& el1, const Elem& el2) noexcept {
	
	return !(el1 < el2);

}

bool operator >= (const Elem& el1, const Elem& el2) noexcept {

	return !(el1 <= el2);

}
