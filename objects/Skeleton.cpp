#include "Skeleton.hpp"
#include "../Resource.hpp"

Skeleton::Skeleton() :
	Threat(
        Resource::TX_SKELETON_ATTACK,
        Resource::TX_SKELETON_DEATH,
        Resource::TX_SKELETON_WALK,
        20, 5, 200)
{
}
