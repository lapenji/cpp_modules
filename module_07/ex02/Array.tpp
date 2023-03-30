
template <typename T>
Array<T>::Array() : length(0), elements(NULL) {

}

template <typename T>
Array<T>::Array(size_t length) : length(length), elements(NULL) {
	this->elements = new T[length]();
}

template <typename T>

Array<T>::Array(const Array<T> &toCopy) : length(0), elements(NULL) {
	if (toCopy.length > 0) {
		this->elements = new T[toCopy.length]();
		for (size_t i = 0; i < toCopy.length; i++) {
			this->elements[i] = toCopy.elements[i];
		}
	}
	this->length = toCopy.length;
}

template <typename T>

Array<T>::~Array() {
	if (this->length > 0) {
		delete[] this->elements;
	}
}

template <typename T>

Array<T>	&Array<T>::operator=(const Array<T> &rhs) {
	if (this->length > 0) {
		delete[] this->elements;
	}
	this->elements = NULL;
	if (rhs.length > 0) {
		this->elements = new T[rhs.length]();
		for (size_t i = 0; i < rhs.length; i++) {
			this->elements[i] = rhs.elements[i];
		}
	}
	this->length = rhs.length;
	return (*this);
}

template <typename T>

T	&Array<T>::operator[](size_t idx) {
	if (idx >= this->length) {
		throw Array::OobExc();
	}
	else
		return (this->elements[idx]);
}

template <typename T>

T const &Array<T>::operator[](size_t index) const
{
	return (operator[](index));
}

template <typename T>

size_t	Array<T>::size() const {
	return (this->length);
}

template <typename T>
const char	*Array<T>::OobExc::what() const throw() {
	return ("Array exception, index out of bounds");
}
