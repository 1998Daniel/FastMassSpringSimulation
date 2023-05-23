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