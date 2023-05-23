/*
This header contains aliases for easier to read code. 
*/

#pragma once

#include <iostream>
#include <vector>
#include "Eigen/Eigen"
#include "Eigen/Sparse"
#include <utility>
#include "particle.h"

typedef Eigen::VectorXf VectorXf;
typedef std::pair<Particle, Particle> Edge;

const float GRAVITY = 9.8f;
const float h = .1f/.30f;
const float DAMPING_FACTOR = 0.99f;

enum IntegrationMethod {
	ExplicitEuler,
	SemiImplicitEuler,
	ImplicitEuler,
	LocalGlobal,
	RungeKutta4,
	MidPoint
};