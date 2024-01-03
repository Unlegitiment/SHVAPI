#include "BaseScaleform.h"

IBaseScaleform::IBaseScaleform() :
	scaleform(0),
	scaleform_2(0),
	scaleform_3(0)
{
	return;
}
#include "../ScriptHookV/natives.h"
void IBaseScaleform::Draw()
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, 0.5,0.5, 1,1,255,255,255,255,0);
}
