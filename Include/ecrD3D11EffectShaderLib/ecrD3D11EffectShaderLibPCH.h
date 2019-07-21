// EMERGENT GAME TECHNOLOGIES PROPRIETARY INFORMATION
//
// This software is supplied under the terms of a license agreement or
// nondisclosure agreement with Emergent Game Technologies and may not
// be copied or disclosed except in accordance with the terms of that
// agreement.
//
//      Copyright (c) 1996-2009 Emergent Game Technologies.
//      All Rights Reserved.
//
// Emergent Game Technologies, Calabasas, CA 91302
// http://www.emergent.net

#pragma once
#ifndef EE_D3D11EFFECTSHADERLIBPCH_H
#define EE_D3D11EFFECTSHADERLIBPCH_H

/** @file ecrD3D11RendererPCH.h
    This header file is used as the Precompiled Header for building ecrD3D11EffectShaderLib. 
    It should only include ecrD3D11EffectShaderLib headers that are commonly used and not expected 
    to change frequently. In addition it should include various external headers such as OS or 
    CRT headers.
*/
#if defined(NI_USE_PCH)

#include <NiMainPCH.h>

#include <ecrD3D11Renderer/D3D11Headers.h>
#include <ecrD3D11Renderer/D3D11ShaderCore.h>
#include <ecrD3D11Renderer/D3D11ShaderLibrary.h>
#include <ecrD3D11EffectShaderLib/Effects11Headers.h>

#endif //#if defined(NI_USE_PCH)

#endif // EE_D3D11EFFECTSHADERLIBPCH_H