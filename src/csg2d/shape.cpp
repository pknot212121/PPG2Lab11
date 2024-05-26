#include "complexshape.h"
#include "operation.h"
#include<memory>
std::shared_ptr<CSG2D::Shape> CSG2D::Shape::Union(const std::shared_ptr<Shape>& shape2) const
{
	return std::make_shared<Complexshape>(std::const_pointer_cast<Shape>(shared_from_this()), shape2, OPERATION::UNION);
}

std::shared_ptr<CSG2D::Shape> CSG2D::Shape::Difference(const std::shared_ptr<Shape>& shape2) const
{
	return std::make_shared<Complexshape>(std::const_pointer_cast<Shape>(shared_from_this()), shape2, OPERATION::DIFFERENCE);
}

std::shared_ptr<CSG2D::Shape> CSG2D::Shape::Intersection(const std::shared_ptr<Shape>& shape2) const
{
	return std::make_shared<Complexshape>(std::const_pointer_cast<Shape>(shared_from_this()), shape2, OPERATION::INTERSECTION);
}
