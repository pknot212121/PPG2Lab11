#include "rectangle.h"
#include "functions.h"


bool CSG2D::Rectangle::isIn(const sf::Vector2f& position2) const
{
	sf::Vector2f delta_position = position2 - position_;
	sf::Vector2f rotated = rotate(delta_position, static_cast<float>(-angle_rad_));
	return std::abs(rotated.x) <= size_.x / 2 && std::abs(rotated.y) <= size_.y / 2;
}
