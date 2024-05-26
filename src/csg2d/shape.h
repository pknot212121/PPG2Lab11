#pragma once
#include "libincludes.h"
#include<memory>



namespace CSG2D
{
class Shape : public std::enable_shared_from_this<Shape>
{
public:
	Shape(const sf::Vector2f &position, double angle_rad) : position_(position), angle_rad_(angle_rad) {}

protected:
	sf::Vector2f position_;
	double angle_rad_;

public:
	[[nodiscard]] virtual bool isIn(const sf::Vector2f &test_position) const = 0;
	std::shared_ptr<Shape> Union(const std::shared_ptr<Shape>& shape2) const;
	std::shared_ptr<Shape> Difference(const std::shared_ptr<Shape>& shape2) const;
	std::shared_ptr<Shape> Intersection(const std::shared_ptr<Shape>& shape2) const;

};
}
