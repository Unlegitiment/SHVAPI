#include "..\Utils.h"
typedef unsigned long long DWORD;
Vector3_t vec3_Create(float x, float y, float z) {
	return Vector3_t{ x,0,y,0,z,0 };
}
Vector3_t vec3_Create_EX(float x, DWORD_t _paddingX_, float y, DWORD_t _paddingY_, float z, DWORD_t _paddingZ_) {
	return Vector3_t{ x, (unsigned long long)_paddingX_, y, (unsigned long long)_paddingY_, z, (unsigned long long)_paddingZ_ };
}
/*
* @return 1 = TRUE 0 = FALSE
*/
bool vec3_Comp(Vector3_t* vec, Vector3_t* vec2) {
	if (vec->x == vec2->x &&
		vec->y == vec2->y &&
		vec->z == vec2->z) {
		return true;
	}
	else { return false; }
}
/*
* Does NOT call free() on the vec. As typically we won't be accessing the malloc during operations involving Vector3(s)
*/
void vec3_Destroy(Vector3_t* vec) {
	vec->x			= 0		;
	vec->y			= 0		;
	vec->z			= 0		;
	vec->_paddingX_ = 0UL	;
	vec->_paddingY_ = 0UL	;
	vec->_paddingZ_ = 0UL	;
	return;
}
void vec3_Change(Vector3_t* ptr, float newNum, Vector3Type toChange) {
	switch (toChange) {
	case 0:
		ptr->x = newNum;
		break;
	case 1:
		ptr->y = newNum;
		break;
	case 2:
		ptr->z = newNum;
		break;
	case 0x45:
		ptr->_paddingX_ = (unsigned long long)newNum;
		break;
	case 0x46:
		ptr->_paddingY_ = (unsigned long long)newNum;
		break;
	case 0x47:
		ptr->_paddingZ_ = (unsigned long long)newNum;
		break;
	}
}
void vec3_Add(Vector3_t* const dest, const Vector3_t* src) {
	dest->x = dest->x + src->x;
	dest->y = dest->y + src->y;
	dest->z = dest->z + src->z;
	return;
}
void vec3_Sub(Vector3_t* const dest, const Vector3_t* src) {
	dest->x = dest->x - src->x;
	dest->y = dest->y - src->y;
	dest->z = dest->z - src->z;
	return;
}
void vec3_Mult(Vector3_t* const dest, const Vector3_t* src) {
	dest->x = dest->x * src->x;
	dest->y = dest->y * src->y;
	dest->z = dest->z * src->z;
	return;
}
void vec3_Divide(Vector3_t* const dest, const Vector3_t* src) {
	dest->x = dest->x / src->x;
	dest->y = dest->y / src->y;
	dest->z = dest->z / src->z;
	return;
}

Vector2_t vec2_Create(float x, float y)
{
	return Vector2_t{x, 0UL, y, 0UL};
}

Vector2_t vec2_Create_Ex(float x, DWORD_t _paddingX_, float y, DWORD_t _paddingY_)
{
	return Vector2_t{x, _paddingX_, y, _paddingY_};
}
const char* vec2_ToStr(const Vector2_t vec, bool usePadding) {
	//char buff[64];
	//memset(buff, 0, sizeof(*buff));
	//	char* x = util_FloatToStr(vec.x);
	//	char* y = util_FloatToStr(vec.y);
	//if (usePadding) {
	//	char* _paddingX_ = util_IntToStr(vec._paddingX_);
	//	char* _paddingY_ = util_IntToStr(vec._paddingY_);
	//	strcat(buff, x);
	//	strcat(buff, y);
	//}
}
bool vec2_Comp(Vector2_t vec, Vector2_t vec2) {
	if (vec.x == vec2.x &&
		vec.y == vec2.y) {
		return true;
	}
	else { return false; }
}