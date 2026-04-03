/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:01:42 by dkolarov          #+#    #+#             */
/*   Updated: 2026/04/03 12:09:58 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	if (n == 0)
		_data = NULL;
	else
		_data = new T[n]();
}
/* 
	-> Allocate memory for n elements
	-> () ensures values are initialized (e.g., 0 for int)
 */

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		if (_size == 0)
		{
			_data = NULL;
		}
		else
		{
			_data = new T[_size];						// allocate the new memory
			for (unsigned int i = 0; i < _size; i++)	// copy each elemnt 
				_data[i] = other._data[i];
		}
	}
	return *this;
}

/*
Prevent invalid access
Return reference -> allows modification 
 */
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

// taking the size
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

//message
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}