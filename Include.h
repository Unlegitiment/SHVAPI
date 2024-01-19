#pragma once

//defines for files.
#ifdef USE_NATIVE
#include "ScriptHookV/natives.h"
#endif
#ifdef USE_TYPES
#include "ScriptHookV/types.h"
#endif
#ifdef USE_SHV
#include "ScriptHookV/natives.h"
#include "ScriptHookV/types.h"
#include "ScriptHookV/enums.h"
#include "ScriptHookV/nativeCaller.h"
#endif
#ifdef USE_OLD_NATIVE
#include "ScriptHookV/OGnatives.h"
#endif
//macros
#define BIT(x) 1<<x
//types
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef u64 _DWORD_;
