#pragma once
#include "shape.h"
#include "operation.h"
#include<memory>


namespace CSG2D
{
	class Complexshape : public Shape
	{
	public:
		Complexshape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, OPERATION operation);
		bool isIn(const sf::Vector2f& position2) const override;
	private:
		std::shared_ptr<Shape> shape1_;
		std::shared_ptr<Shape> shape2_;
		OPERATION operation_;
	};
}

