/*
This header contains aliases for easier to read code. 
*/

#pragma once

#include <iostream>
#include <vector>
#include "Eigen/Eigen"
#include "Eigen/Sparse"
#include <utility>

//ALIASES

typedef Eigen::VectorXf VectorXf;

//SIMULATION CONSTANTS

const float GRAVITY = 9.8f;
const float h = .1f/.30f;
const float DAMPING_FACTOR = 0.99f;

//MISCELLANOUS

const int VBO_SIZE = 3;

const int POSITIONS_VBO_INDEX = 0;
const int NORMALS_VBO_INDEX = 1;
const int TEX_COORDS_VBO_INDEX = 2;

enum IntegrationMethod {
	ExplicitEuler,
	SemiImplicitEuler,
	ImplicitEuler,
	LocalGlobal,
	RungeKutta4,
	MidPoint
};

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;