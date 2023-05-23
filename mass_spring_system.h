#pragma once
#include "core.h"
class MassSpringSystem {
private:
	int m_num_particles;
	Edge m_edge;
	float m_h; //time step "h" in literature
	float m_damping_factor;
	const float m_gravity;
	int m_n; //nxn square lattice 
	int m_num_springs; 
	VectorXf m_positions;
	VectorXf m_velocities;

public:
	MassSpringSystem();
	void DrawMassSpringSystem();
	void AddPositionVector();
	void AddVelocityVector();

};