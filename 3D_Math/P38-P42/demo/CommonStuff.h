#ifndef COMMONSTYFF_H
#define COMMONSTUFF_H

template <class Type>

inline const Type &min(const Type &a, const Type &b)
{
	return (a < b) ? a : b;
}


template <class Type>
inline const Type &max(const Type &a, const Type &b)
{
	return (a > b) ? a : b;
}

template <class Type>
inline void swap(Type &a, Type &b)
{
	Type temp(a);
	a = b;
	b = temp;
}


#endif 
