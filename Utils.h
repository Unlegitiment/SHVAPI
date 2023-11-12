#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Utils/internal_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void ListHandle;
typedef int Entity;
/*
  ~~~~~~RGB Functions~~~~~~~~
  TODO: Likely create mathematical functions that compare basically all the comparatives or something similar to that?
*/

extern RGBA_t rgb_Create(float r, float g, float b, float a);
extern BOOL_t rgb_Equal(RGBA_t rgb1, RGBA_t rgb2);
extern void rgb_Destroy(RGBA_t* rgb);

/*
   ~~~~~ VEC FUNCS ~~~~~~ TODO: create func: vec_Mult, vec_Add, vec_Sub, vec Devide
*/

extern Vector3_t vec3_Create(float x, float y, float z); 
extern Vector3_t vec3_Create_EX(float x, DWORD_t _paddingX_, float y, DWORD_t _paddingY_, float z, DWORD_t _paddingZ_);
extern BOOL_t vec3_Comp(Vector3_t* vec, Vector3_t* vec2);
extern void vec3_Destroy(Vector3_t* vec);
extern void vec3_Add(Vector3_t* const dest, const Vector3_t* src);
extern void vec3_Sub(Vector3_t* const dest, const Vector3_t* src);
extern void vec3_Mult(Vector3_t* const dest, const Vector3_t* src);
extern void vec3_Divide(Vector3_t* const dest, const Vector3_t* src);
/*
* ~~~~~TXD Function & Headshot ~~~~~~
*/

/*
* @param char* dictionary. - This is the individual file that the TXD(s) are within.  
* @param char* name. - This is the actual name within that Dictionary.
* @brief Creates a TXD object. (Does NOT request it within the game's memory just setups the TXD definitions.
* See txd_Init to see how it requests the thing. Also sets an internal variable to TRUE
*/
extern TXD* txd_Create(char* dictionary, char* name);
extern void txd_Destroy(TXD* tPtr);
extern BOOL_t txd_Comp(TXD* one, TXD* two);
extern void txd_Init(TXD* tPtr);
extern BOOL_t txd_isRequested(const TXD* tPtr);
extern TXD* GetHeadShot(Entity e);

inline char* util_IntToStr(int i = 0) {
    char* zzzz = (char*)malloc(sizeof(char)*64);
    if (zzzz == NULL) return NULL;
    sprintf(zzzz, "%d", i);
    return zzzz;
}
/*
* Basically the same as std::vector Just wanted to create it in C style.
*/

extern ListHandle* lh_CreateList(size_t element_size, void(*free_fn)(void*));
extern void lh_pushback(ListHandle* handle, void* val);
extern void* lh_at(ListHandle* handle, size_t index);
extern void lh_Destroy(ListHandle* handle);