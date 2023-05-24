#pragma once
#include "core.h"

class MassSpringSystem {
private:

	//typedef Eigen::VectorXf VectorXf;
	int m_num_particles; //nxn square lattice
	float m_h; //time step "h" in literature
	float m_h_squared;//h^2
	float m_damping_factor;
	const float m_gravity;
	int m_num_springs; 
	VectorXf m_positions;
	VectorXf m_velocities;

public:
	MassSpringSystem(int num_particles);
	void AddPositionVector();
	void AddVelocityVector();

};