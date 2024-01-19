#pragma once
#include "THREAD.h"
#include "../ScriptHookV/types.h"
/*File Includes Definition for Mouse Components and various smaller tasks.*/

/*
@author Unlegitiment
@brief CMouse IS a Singleton because you can only have one mouse active on a screen at a time. 
@brief This is as well a wrapper for the native functions in the game. 
*/
class CMouse : public IThreadMethod {
public:
	enum Activation {
		ACT_FRONTEND = 0,
		ACT_SCALEFORM = 1, 
		ACT_FRAME = 2,
		ACT_MAX = 3
	};
	enum CursorType {
		CT_None = 0,
		CT_Normal = 1,
		CT_TransparentNormal = 2,
		CT_PreGrab = 3,
		CT_Grab = 4,
		CT_MiddleFinger = 5,
		CT_LeftArrow = 6,
		CT_RightArrow = 7,
		CT_UpArrow = 8,
		CT_DownArrow = 9,
		CT_HorizontalExpand = 10,
		CT_Add = 11,
		CT_Remove = 12,
		CT_MAX = 13
	};
	/*
	* Defaults to Frame's 
	*/
	void Activate(Activation activation);
	void Tick(Activation activation);
	void Tick();
	void Update();
	
	void SetIsActive(bool active);
	bool IsActive();
	static CMouse& GetInstance();
	void SetCursorType(CursorType type );

	CVector2& GetMousePos();
private:
	void TickMouseMovements();
	static bool			m_isActive	 ;
	static int			m_cursorType ;
	static CVector2		m_position	 ;
	static Activation	m_activeType ;
	static CMouse		m_Instance	 ;
	CMouse() {};
};