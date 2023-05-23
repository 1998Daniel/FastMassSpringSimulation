#pragma once
#include "core.h"

class Solver {
private:
	IntegrationMethod m_integration_method;


public:
	Solver();
	void SolveSystem(IntegrationMethod);
};