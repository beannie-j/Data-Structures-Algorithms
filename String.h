#pragma once
#include <iostream>

class String {
private:
	char* m_buffer = nullptr;
	uint32_t m_size{};
public:
	String() = default;
	String(const char* string);
	String(const String& other);
	String(String&& other) noexcept;

	~String();

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	String& operator=(const String& rhs);
	String& operator=(String&& rhs) noexcept;


	String& operator+=(const String& rhs);
	String& operator+=(const char* string);

	friend String operator+ (const String& lhs, const String& rhs);


	char& operator[](uint32_t i);
	char& operator[](uint32_t i) const;

	uint32_t GetSize() const { return m_size; }

	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;
	bool operator< (const String& rhs) const;
	bool operator> (const String& rhs) const;

	void Print();



};






