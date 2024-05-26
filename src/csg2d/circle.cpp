#include "circle.h"

bool CSG2D::Circle::isIn(const sf::Vector2f& test_position) const
{
	return (test_position - position_).x * (test_position - position_).x + (test_position - position_).y * (test_position - position_).y <= radius_ * radius_;
}

