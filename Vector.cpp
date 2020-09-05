#include "Vector.h"

Vector::Vector()
	:m_size(0), m_capacity(0), m_arr(new int)
{

}

Vector::Vector(uint32_t size)
	: m_size(size), m_capacity(size), m_arr(new int[m_size])
{
}

Vector::Vector(const Vector& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_arr = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = other.m_arr[i];
	}
}

Vector::Vector(Vector&& other) noexcept
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_arr = other.m_arr;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_arr = nullptr;
}

Vector& Vector::operator= (Vector&& rhs) noexcept
{
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_arr = rhs.m_arr;

	rhs.m_size = 0;
	rhs.m_capacity = 0;
	rhs.m_arr = nullptr;

	return *this;
}

Vector::~Vector()
{
	delete[] m_arr;
}

void Vector::push_back(const int& val)
{
	check_size();
	int* new_arr = new int[m_capacity];
	memcpy(new_arr, m_arr, m_size * sizeof(int));
	delete[] m_arr;
	m_arr = new_arr;

	m_arr[m_size++] = val;
}

void Vector::check_size()
{
	if (m_size == m_capacity) m_capacity *= 2;

	if (m_capacity == 0) m_capacity++;
}

Vector& Vector::insert(int pos, int val)
{
	if (pos <= m_size)
	{
		check_size();

		int* new_arr = new int[m_capacity];

		int* lhs = &m_arr[0];
		int* rhs = &m_arr[pos];

		memcpy(new_arr, lhs, pos * sizeof(int));
		new_arr[pos] = val;
		memcpy(new_arr + pos + 1, rhs, (m_size - pos) * sizeof(int));
		m_size++;

		delete[] m_arr;
		m_arr = new_arr;
	}
	else printf("Insert position is out of bounds \n");

	return *this;
}

Vector& Vector::operator=(const Vector& rhs)
{
	m_size = rhs.m_size;
	delete[] m_arr;
	m_arr = new int[rhs.m_size];
	memcpy(m_arr, rhs.m_arr, m_size * sizeof(int));
	return *this;
}
int& Vector::operator[](uint32_t i) const
{
	if (i < m_size)
	{
		return *(m_arr + i);
	}
}

uint32_t Vector::size() const
{
	return m_size;
}

int& Vector::last()
{
	int* last = &m_arr[m_size - 1];
	return *last;
}

int& Vector::first()
{
	int* first = &m_arr[0];
	return *first;
}

std::ostream& operator<< (std::ostream& stream, const Vector& vec)
{
	for (uint32_t i = 0; i < vec.m_size; i++)
	{
		stream << vec.m_arr[i];
	}
	return stream;
}

void Vector::pop_back()
{
	--m_size;
}

bool Vector::operator==(const Vector& other)
{
	if (m_size != other.m_size) return false;
	for (int i = 0; i < m_size; i++)
	{
		if (m_arr[i] != other.m_arr[i]) return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& other)
{
	return !(*this == other);
}
