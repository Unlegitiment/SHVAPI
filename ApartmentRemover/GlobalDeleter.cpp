#include "GlobalDeleter.h"
ApartmentDeleter* ApartmentDeleter::m_Instance = new ApartmentDeleter();
ApartmentDeleter::ApartmentDeleter():
    
{
}

ApartmentDeleter& ApartmentDeleter::GetInstance()
{
    return *m_Instance;
}

ApartRemoveFunc ApartmentDeleter::GetAtIndex(int index)
{
    return ApartRemoveFunc();
}

void ApartmentDeleter::Call(int index)
{
}

void ApartmentDeleter::Call(ApartRemoveFunc cl_Func)
{
}

void ApartmentDeleter::Destroy()
{
}

bool ApartmentDeleter::BoundsCheck(int index)
{
    
}
