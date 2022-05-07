#pragma once

#include <QtWidgets/QMainWindow>

class Elem {

	QRect rect;
	bool active;

public:

	Elem();
	Elem(int, int, int, int);

	QRect getRect() const noexcept;
	int getTop() const noexcept;
	int getHeight() const noexcept;
	bool isActive() const noexcept;

	void setTop(int) noexcept;
	void setActive() noexcept;
	void setInactive() noexcept;

	class Elem& operator = (const Elem&);

	friend bool operator < (const Elem&, const Elem&) noexcept;
	friend bool operator <= (const Elem&, const Elem&) noexcept;
	friend bool operator > (const Elem&, const Elem&) noexcept;
	friend bool operator >= (const Elem&, const Elem&) noexcept;

};

