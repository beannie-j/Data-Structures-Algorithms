#include <iostream>
#include "String.h"


String::String(const char* string)
{
	m_size = strlen(string);
	m_buffer = new char[m_size + 1];
	strcpy_s(m_buffer, m_size + 1, string);
	m_buffer[m_size] = 0;
}


String::String(const String& other)
{
	m_size = other.m_size;
	m_buffer = new char[m_size + 1];
	strcpy_s(m_buffer, m_size + 1, other.m_buffer);
	m_buffer[m_size] = 0;
}

String::String(String&& other) noexcept
{
	m_size = other.m_size;
	m_buffer = other.m_buffer;
	other.m_size = 0;
	other.m_buffer = nullptr;
}

String::~String()
{
	delete[] m_buffer;
}

void String::Print()
{
	for (uint32_t i = 0; i < m_size; i++)
	{
		printf("%c", m_buffer[i]);
	}
	printf("\n");
}

String& String::operator=(const String& rhs)
{

	if (*this != rhs)
	{
		if (m_size != rhs.m_size)
		{
			delete[] m_buffer;
			m_buffer = new char[rhs.m_size + 1];
		}
		m_size = rhs.m_size;
		strcpy_s(m_buffer, rhs.m_size + 1, rhs.m_buffer);
		m_buffer[m_size] = 0;
	}
	return *this;
}

String& String::operator=(String&& rhs) noexcept
{
	m_size = rhs.m_size;
	m_buffer = rhs.m_buffer;

	rhs.m_size = 0;
	rhs.m_buffer = nullptr;

	return *this;
}

String& String::operator+=(const String& rhs)
{
	uint32_t temp = m_size;
	m_size += rhs.m_size;
	char* temp_buf = new char[m_size + 1];
	strcpy_s(temp_buf, m_size + 1, m_buffer);
	for (int i = temp; i < m_size; i++)
	{
		temp_buf[i] = rhs.m_buffer[i - temp];
	}
	temp_buf[m_size] = 0;
	this->m_buffer = temp_buf;

	return *this;
}

String& String::operator+=(const char* string)
{
	uint32_t temp = m_size;
	m_size += strlen(string);
	char* temp_buf = new char[m_size + 1];
	strcpy_s(temp_buf, m_size + 1, m_buffer);
	for (int i = temp; i < m_size; i++)
	{
		temp_buf[i] = string[i - temp];
	}
	temp_buf[m_size] = 0;
	this->m_buffer = temp_buf;

	return *this;
}

String operator+ (const String& lhs, const String& rhs)
{
	return String(lhs) += rhs;
}

bool String::operator< (const String& rhs) const
{
	return strcmp(m_buffer, rhs.m_buffer) < 0;
}

bool String::operator> (const String& rhs) const
{
	return strcmp(m_buffer, rhs.m_buffer) > 0;
}

char& String::operator[](uint32_t i)
{
	if (i >= m_size)
		return m_buffer[0];
	return m_buffer[i];
}

char& String::operator[](uint32_t i) const
{
	return (*this)[i];
}

bool String::operator==(const String& other) const
{
	if (m_size != other.m_size)
		return false;

	return strcmp(m_buffer, other.m_buffer) == 0;
}

bool String::operator!=(const String& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_buffer;
	return stream;
}

