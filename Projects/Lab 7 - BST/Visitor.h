#pragma once

#include "City.h"

class Visitor {

public: 
	inline Visitor();
	inline ~Visitor();

	virtual void visit(City& city) = 0;
};

Visitor::Visitor() {}//end

Visitor::~Visitor() {}