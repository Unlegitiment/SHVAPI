#pragma once
#include "../GenericList/CList.h"
#include <vector>
#include <functional>
/*
* What I'm thinking for this is we have a LUT of Apartments that corrilate to functions.
* These functions are then able to callback to a apartment and then we're able to just have that be easy.
*/
typedef void(*ApartRemoveFunc)();
/*
* This class does not modify game files however it activates the Culls for the apartments using an LUT because it's more efficient.
*/
class ApartmentDeleter {
public:
	enum ApartmentDeletion {
		ECLIPSE,
		ALTA, 
		TINSEL,
		DEL_PERRO,
		RICHARD,
		WHEAZEL,
		PILLBOX_HILL,
		AP_MAX
	};
	ApartmentDeleter(); 
	void Init(); 
	static ApartmentDeleter& GetInstance();
	ApartRemoveFunc GetAtIndex(int index);
	void Call(int index);
	void Call(ApartRemoveFunc cl_Func);
	void Destroy(); 
	void AddToList(ApartRemoveFunc function); //Appends to End of List for now just does the regular apartment types as specified by the enum;
	

private:
	bool BoundsCheck(int index); 

	std::vector<void(*)()>		func_Remove;
	static ApartmentDeleter*	m_Instance;
};
