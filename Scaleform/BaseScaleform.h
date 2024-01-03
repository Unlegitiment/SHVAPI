#pragma once
class IBaseScaleform {
public:
	enum class StereoFlags {
		SCRIPT_GFX_SCALEFORM_MOVIE_RETICULESTEREO = 1,
		SCRIPT_GFX_SCALEFORM_MOVIE_STEREO = 2,
		SCRIPT_GFX_SCALEFORM_MOVIE = 0
	};
	IBaseScaleform();
	virtual void Draw();
protected:
	int scaleform, scaleform_2, scaleform_3;
};