#pragma once
#include"shape.h"
namespace CSG2D
{
	class Circle : public Shape
	{
	private:
		float radius_;
	public:
		Circle(const sf::Vector2f& position, double angle_rad, float radius) : Shape(position, angle_rad), radius_(radius) {}
		bool isIn(const sf::Vector2f& test_position) const override;
	};
}


