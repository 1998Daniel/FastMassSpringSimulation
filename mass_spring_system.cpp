#include "mass_spring_system.h"
#include "core.h"

MassSpringSystem::MassSpringSystem(int num_particles) : m_num_particles(num_particles), 
m_gravity(::GRAVITY), m_h(::h), m_damping_factor(::DAMPING_FACTOR) 
{
	//formula from https://cs.stackexchange.com/questions/62847/draw-a-5-%C3%97-5-grid-graph-how-many-edges-does-the-n-%C3%97-n-grid-graph-have
	m_num_springs = (2 * (m_num_particles * m_num_particles)) - (2 * m_num_particles);
	m_h_squared = m_h * m_h;


}
