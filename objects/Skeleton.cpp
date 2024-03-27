#include "Skeleton.hpp"
#include "../Resource.hpp"

Skeleton::Skeleton() :
	Threat(
        Resource::TX_SKELETON_ATTACK,//hien thi anh quai vat
        Resource::TX_SKELETON_DEATH,
        Resource::TX_SKELETON_WALK,
        20, 5, 200) //máu max, độ sát thương , tốc độ
{
}
