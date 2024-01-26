#pragma once
class TextJustify {
public:
	virtual void SetupText() = 0;
	virtual void SetupText(float start, float end) = 0;
	virtual int GetType() = 0;
protected:
	virtual void NativeCaller() = 0;
};
class CLeftJustify : public TextJustify {
public:
	void SetupText() override;
	int GetType() { return 1; }
private:
	void NativeCaller() override;
	void SetupText(float start, float end) override;
};
//Should Justify call other functions in it's constructor?
class CRightJustify : public TextJustify {
public:
	//CRightJustify(float start, float end);
	void SetupText(float start, float end) override; 
	int GetType() override { return 2; }
private:
	void NativeCaller() override;
	void SetupText()override;
private: //
	float m_Start;
	float m_End;
};
class CMiddleJustify : public TextJustify {
public:
	void SetupText()override;
	int GetType()override { return 0; }
private:
	void NativeCaller() override;
	void SetupText(float start, float end)override;
};