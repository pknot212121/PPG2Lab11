#pragma once
#include <cstdint>
namespace CSG2D
{
enum class OPERATION : std::uint8_t
{
	UNION,
	DIFFERENCE,
	INTERSECTION
};
}
