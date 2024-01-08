#include "OnlineLoad.h"
#include "../ScriptHookV/natives.h"
#include "../UI.h"
CBaseScaleform::CBaseScaleform(std::string scaleform)
	:
	m_ScfReq(scaleform)
{
	this->m_Scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE(scaleform.c_str());
	while (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(m_Scaleform)) {
		WAIT(0);
	}
}

void CBaseScaleform::LitStrPush(std::string literalString)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(literalString.c_str());
}

void CBaseScaleform::GXTStrPush(std::string gxtTablesStr)
{
	GRAPHICS::BEGIN_TEXT_COMMAND_SCALEFORM_STRING(gxtTablesStr.c_str());
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CBaseScaleform::IntegerPush(int i)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(i);
}

void CBaseScaleform::FloatPush(float f)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_FLOAT(f);
}

void CBaseScaleform::TextureStrPush(std::string str)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_TEXTURE_NAME_STRING(str.c_str());
}

void CBaseScaleform::PlayerStrPush(std::string str)
{
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING(str.c_str());
}

void CBaseScaleform::BeginFunction(std::string funcName)
{
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(this->m_Scaleform, funcName.c_str());
}

void CBaseScaleform::EndFunction()
{
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}

void CBaseScaleform::RequestTXD(std::string txd)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(txd.c_str(), 1);
	while (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(txd.c_str())) {
		WAIT(0);
	}
}

CGTAVScaleform::CGTAVScaleform():
	CBaseScaleform("GTAV_ONLINE"),
	m_Visible(FALSE)
{
}
CGTAVScaleform::CGTAVScaleform(std::string title, std::string subTitle, std::string body, std::string txd, std::string txn)
	:
	CBaseScaleform	("GTAV_ONLINE"),
	m_Visible		(FALSE),
	m_Title			(title),
	m_Subtitle		(subTitle),
	m_Body			(body),
	m_Txd			(txd),
	m_Txn			(txn)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(m_Txd.c_str(), 1);
	while (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(m_Txd.c_str()))WAIT(0); //Loading from these files fucking suck. (so Slow) Also causes weird bug with layers.
	BeginFunction("SETUP_BIGFEED");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(TRUE);
	EndFunction();
	BeginFunction("HIDE_ONLINE_LOGO");
	EndFunction();
	//BeginFunction("SET_BIGFEED_IMAGE");
	//PlayerStrPush(m_Txd.c_str());
	//PlayerStrPush(m_Txn.c_str());
	//EndFunction();
	BeginFunction("SET_BIGFEED_INFO");
	PlayerStrPush("Footer"); // Footer?
	PlayerStrPush(m_Body.c_str());
	IntegerPush(500); // page
	PlayerStrPush(m_Txd.c_str());
	PlayerStrPush(m_Txn.c_str());
	PlayerStrPush(m_Subtitle.c_str());
	PlayerStrPush("URL"); //depricated
	PlayerStrPush(m_Title);
	// Set to "622774931" below to make it RDR styled text !
	IntegerPush(0);
	EndFunction();

	BeginFunction("SET_NEWS_CONTEXT");
	IntegerPush(0);
	EndFunction();
}
CGTAVScaleform::~CGTAVScaleform()
{
	m_Title = "";
	m_Body = "";
	m_Subtitle = "";
	m_Txd = "";
	m_Txn = "";
	return;
}
const char* text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Eget nullam non nisi est sit amet facilisis magna. Eu facilisis sed odio morbi quis. Euismod nisi porta lorem mollis aliquam ut. Ornare quam viverra orci sagittis. Semper risus in hendrerit gravida rutrum quisque non tellus. Elit ut aliquam purus sit. Ornare arcu dui vivamus arcu felis bibendum. Augue eget arcu dictum varius duis. Nunc sed blandit libero volutpat sed cras ornare. Aliquet bibendum enim facilisis gravida neque convallis a. Convallis convallis tellus id interdum velit laoreet id donec ultrices. Lorem donec massa sapien faucibus. Feugiat pretium nibh ipsum consequat nisl. Egestas dui id ornare arcu odio ut sem nulla. Elit scelerisque mauris pellentesque pulvinar. Rhoncus est pellentesque elit ullamcorper dignissim. Volutpat commodo sed egestas egestas fringilla phasellus faucibus scelerisque eleifend. Elit scelerisque mauris pellentesque pulvinar pellentesque habitant morbi tristique.";
#include "../keyboard.h"
void CGTAVScaleform::DrawFrame()
{
	BeginFunction("FADE_IN_BIGFEED");
	EndFunction();
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(m_Scaleform,255, 255, 255, 255, 0);
}

void CGTAVScaleform::Draw()
{

	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(m_Scaleform, 255, 255, 255, 255, 0);
}

void CGTAVScaleform::CancelDraw(BOOL* active)
{
	
}

void CGTAVScaleform::Cleanup()
{
//	GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&m_Scaleform);
//	GRAPHICS::SET_STREAMED_TEXTURE_DICT_AS_NO_LONGER_NEEDED(m_Txd.c_str());
//	this->~CGTAVScaleform();
	return;
}
