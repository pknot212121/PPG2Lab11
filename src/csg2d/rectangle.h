#pragma once
#include"shape.h"

namespace CSG2D
{
	class Rectangle : public Shape
	{
	private:
		sf::Vector2f size_;
	public:
		Rectangle(const sf::Vector2f& position, double angle_rad, const sf::Vector2f& size) : Shape(position, angle_rad), size_(size) {}
		bool isIn(const sf::Vector2f& position2) const override;
	};
}



