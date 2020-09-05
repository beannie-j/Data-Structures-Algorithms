#pragma once
#include <iostream>
class Vector
{
private:
	int* m_arr = nullptr;
	uint32_t m_size{};
	uint32_t m_capacity{};

public:
	Vector();
	Vector(uint32_t size);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	~Vector();

	void push_back(const int& val);
	Vector& insert(int pos, int val);

	int& operator[](uint32_t i) const;
	bool operator==(const Vector& other);
	bool operator!=(const Vector& other);
	Vector& operator= (const Vector& rhs);
	Vector& operator= (Vector&& rhs) noexcept;
	uint32_t size() const;
	int& last();
	void check_size();
	void pop_back();
	int& first();

	friend std::ostream& operator<<(std::ostream& stream, const Vector& vec);

};