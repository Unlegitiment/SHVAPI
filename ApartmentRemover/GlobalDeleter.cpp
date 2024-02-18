#include "GlobalDeleter.h"
#include "../ScriptHookV/natives.h"
#define APART_REMOVE_PREQ() \
DLC::ON_ENTER_MP();\
GRAPHICS::SET_DISABLE_DECAL_RENDERING_THIS_FRAME();\
GRAPHICS::DISABLE_OCCLUSION_THIS_FRAME();

void __REMOVE_ECLIPSE()
{
    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_11_flats"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_ss1_emissive_a"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_detail01b"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_11_Flats_LOD"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_LOD_01_02_08_09_10_11"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_SLOD1"));
}
void __REMOVE_DELPERRO() {
    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_sm_14_bld2"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("sm_14_emissive"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("prop_wall_light_12a"));
}
void __REMOVE_ALTA()
{
    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_20_build2"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_20_dt1_emissive_dt1_20"));
}

void __REMOVE_TINSEL()
{
    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_Emissive_SS1_02a_LOD"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("ss1_02_ss1_emissive_ss1_02"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("apa_ss1_02_building01"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("SS1_02_Building01_LOD"));

}

void __REMOVE_RICHARD()
{
    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_emissive_bh1_08"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_bld2_LOD"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_08_bld2"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_08_em"));
}

void __REMOVE_WHEAZEL()
{

    APART_REMOVE_PREQ();
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("bh1_09_ema"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_bh1_09_bld_01"));
}
void __REMOVE_PILLBOX_HILL() {
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("hei_dt1_03_build1x"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("DT1_Emissive_DT1_03_b1"));
    INTERIOR::ENABLE_EXTERIOR_CULL_MODEL_THIS_FRAME(MISC::GET_HASH_KEY("dt1_03_dt1_Emissive_b1"));
}



ApartmentDeleter* ApartmentDeleter::m_Instance = new ApartmentDeleter();
ApartmentDeleter::ApartmentDeleter() :
    func_Remove{}
{
    Init();
}

ApartmentDeleter& ApartmentDeleter::GetInstance()
{
    if (m_Instance == nullptr) {
        m_Instance = new ApartmentDeleter();
        GetInstance();
    }
    return *m_Instance;
}

ApartRemoveFunc ApartmentDeleter::GetAtIndex(int index)
{
    return BoundsCheck(index) ? func_Remove[index] : nullptr;
}

void ApartmentDeleter::Call(int index)
{
    if (BoundsCheck(index)) {
        func_Remove[index]();
    }
}

void ApartmentDeleter::Call(ApartRemoveFunc cl_Func)
{
    cl_Func();
}

void ApartmentDeleter::Destroy()
{
    func_Remove.clear();
}

void ApartmentDeleter::AddToList(ApartRemoveFunc function)
{
    func_Remove.push_back(function);
}
void ApartmentDeleter::Init()
{
    AddToList(__REMOVE_ECLIPSE);
    AddToList(__REMOVE_ALTA);
    AddToList(__REMOVE_TINSEL);
    AddToList(__REMOVE_DELPERRO);
    AddToList(__REMOVE_RICHARD);
    AddToList(__REMOVE_WHEAZEL);
    AddToList(__REMOVE_PILLBOX_HILL);
}

bool ApartmentDeleter::BoundsCheck(int index)
{
    if (index < func_Remove.size()) {
        return true;
    }
    return false;
}

