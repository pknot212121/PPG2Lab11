#include "complexshape.h"

CSG2D::Complexshape::Complexshape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, OPERATION operation): Shape(sf::Vector2f(0.f,0.f),0.0)
{
	shape1_ = shape1;
	shape2_ = shape2;
	operation_ = operation;
}

bool CSG2D::Complexshape::isIn(const sf::Vector2f& position2) const
{
	bool inShape1 = shape1_->isIn(position2);
	bool inShape2 = shape2_->isIn(position2);

	switch (operation_)
	{
	case OPERATION::UNION:
		return inShape1 || inShape2;
	case OPERATION::INTERSECTION:
		return inShape1 && inShape2;
	case OPERATION::DIFFERENCE:
		return inShape1 && !inShape2;
	default:
		return false;
	}
}
