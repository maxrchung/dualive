#ifndef DECOMPOSEDVALUE_HPP
#define DECOMPOSEDVALUE_HPP

#include "DecomposedValueType.hpp"
#include <freetype/ftoutln.h>
#include <vector>

class DecomposedValue {
public:
	DecomposedValue(DecomposedValueType type, FT_Vector point)
		: type(type), point(point) {}
	DecomposedValueType type;
	FT_Vector point;
};

typedef std::vector<DecomposedValue> Contour;
typedef std::vector<Contour> DecomposedOutline;

#endif//DECOMPOSEDVALUE_HPP