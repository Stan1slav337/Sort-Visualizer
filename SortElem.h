#pragma once

#include <QtWidgets/QMainWindow>

class Elem : public QRect {

	bool active;

public:

	Elem();
	Elem(int, int, int, int);

	bool isActive() const noexcept;

	void setActive() noexcept;
	void setInactive() noexcept;

	class Elem& operator = (const Elem&);

	friend bool operator < (const Elem&, const Elem&) noexcept;
	friend bool operator > (const Elem&, const Elem&) noexcept;
	friend bool operator <= (const Elem&, const Elem&) noexcept;
	friend bool operator >= (const Elem&, const Elem&) noexcept;

};

