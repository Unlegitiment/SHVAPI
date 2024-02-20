#include "MenuContext.h"
#include "../MenuTextComponents/CWrappedText.h"
MenuContextMgr::MenuContextMgr() :
	m_Display(MenuContextDisplay())
{
	SHVInit();
	Update(); 
}

void MenuContextMgr::Update()
{
	Attach();
	m_Display.Draw(m_Text->GetText(), m_Text->GetBox(), m_Text->DoesInfo());
}

void MenuContextMgr::SetText(CTextUI* text)
{
	m_Text->SetMenuContext(*text);
}

void MenuContextMgr::SetBox(CBox* box)
{
	m_Text->SetNewBox(*box);
}

void MenuContextMgr::SetUsePadding(bool _newBool)
{
	useGTAPadding = _newBool;
}

void MenuContextMgr::SetUseInfo(bool useInfo)
{
	m_Text->SetInfo(useInfo);
}

void MenuContextMgr::Attach()
{
}

void MenuContextMgr::SHVInit()
{
	//Yes this method does store a static variable (not good) however its nessicary to avoid the ScriptHookV while(true) stuff else you wouldn't be able to get out of a while loop and the objects would be persistant.
	static int i = 0;
	if (i == 0) {
		m_Text = new MenuContext();
	}
	i++;
	return;
}

MenuContextDisplay::MenuContextDisplay()
{
}

void MenuContextDisplay::Draw(CTextUI& text, CBox& box, bool hasGTApadding)
{
	Attach(text, box);
	constexpr float HEIGHT = 0.003f;
	CBox* _box = new CBox(CVector2(box.GetDrawPos().x, (box.GetDrawPos().y - (box.GetHeight()/2))+0.001f), CRGBA(0,0,0,255),box.GetWidth(), HEIGHT);
	text.SetTextJustification(new CLeftTextWrapped(box.GetCornerPos(box.TOPLEFT).x, box.GetCornerPos(box.TOPRIGHT).x));
	text.size = text.size - 0.025f;
	if (!hasGTApadding) {
		constexpr float TEXT_PAD = 0.01f;
		text.pos = CVector2(text.pos.x - TEXT_PAD, text.pos.y);
	}
	_box->Draw();
	box.Draw();
	text.Draw();
	return;
}

void MenuContextDisplay::Attach(CTextUI& text, CBox& _box)
{
	constexpr float TEXT_PAD = 0.01f;
	text.pos = CVector2(_box.GetCornerPos(_box.TOPLEFT).x + 0.014f, _box.GetCornerPos(_box.TOPLEFT).y + TEXT_PAD);
}

MenuContext::MenuContext() :
	m_Text(new CTextUI(std::string(""), CVector2(0, 0), CRGBA(255, 255, 255, 255))),
	m_Box(new CBox(CVector2(0, 0), CRGBA(0, 0, 0, 180), 0.2, 0.1)),
	m_bHasInfoSymbol(false)
{
}

void MenuContext::SetMenuCtxStr(std::string& text)
{
	m_Text->text = text;
}

void MenuContext::SetMenuContext(CTextUI& text)
{
	m_Text = &text;

}

void MenuContext::SetNewBox(CBox& newBox)
{
	m_Box = &newBox;
}

void MenuContext::SetInfo(bool _newInstance)
{
	m_bHasInfoSymbol = _newInstance;
}

CBox& MenuContext::GetBox()
{
	return *m_Box;
}

CTextUI& MenuContext::GetText()
{
	return *m_Text;
}

std::string& MenuContext::GetString() const
{
	return std::string("");
}

bool MenuContext::DoesInfo()
{
	return m_bHasInfoSymbol;
}
