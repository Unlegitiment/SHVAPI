#include "Mouse.h"
#include "../ScriptHookV/natives.h"
bool		        CMouse::m_isActive              = false;
int		            CMouse::m_cursorType            = 1;
CVector2            CMouse::m_position              = {0.5F,0.5F};
CMouse::Activation  CMouse::m_activeType            = CMouse::Activation::ACT_FRAME;
CMouse CMouse::m_Instance;
void CMouse::Activate(Activation activation)
{
    this->m_activeType = activation;
    this->m_isActive = true;
    switch (activation) {
    case ACT_FRAME:
    default:
        HUD::SET_MOUSE_CURSOR_THIS_FRAME();
        HUD::SET_MOUSE_CURSOR_STYLE(this->m_cursorType);
        break;
    case ACT_FRONTEND:
        HUD::SET_MOUSE_CURSOR_VISIBLE(this->m_isActive);
        break;
    case ACT_SCALEFORM:
        break;
    }
}

void CMouse::Tick(Activation activation)
{
    Activate(activation);
    TickMouseMovements();
}
void CMouse::Tick() {
    Activate(CMouse::Activation::ACT_FRAME);
    TickMouseMovements();
}

void CMouse::Update()
{
    Tick(this->m_activeType);
}

void CMouse::SetIsActive(bool active)
{
    this->m_isActive = active;
}

bool CMouse::IsActive()
{
    return m_isActive;
}

CMouse& CMouse::GetInstance()
{
    return m_Instance;
}
void CMouse::SetCursorType(CursorType type)
{
    this->m_cursorType = type;
}
void CMouse::TickMouseMovements()
{
    this->m_position = { PAD::GET_CONTROL_NORMAL(0,239),PAD::GET_CONTROL_NORMAL(0,240) };
}
CVector2& CMouse::GetMousePos()
{
    return this->m_position;
}