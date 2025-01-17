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
#ifndef NICONSTFLOATEVALUATOR_H
#define NICONSTFLOATEVALUATOR_H

#include "NiEvaluator.h"

class NIANIMATION_ENTRY NiConstFloatEvaluator : public NiEvaluator
{
    NiDeclareRTTI;
    NiDeclareClone(NiConstFloatEvaluator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    enum Channel
    {
        FLOAT = EVALBASEINDEX
    };

    NiConstFloatEvaluator();
    NiConstFloatEvaluator(float fPoseValue);

    void SetPoseValue(float fValue);

    // *** begin Emergent internal use only ***

    // Virtual function overrides from NiEvaluator.
    virtual bool GetChannelPosedValue(unsigned int uiChannel,
        void* pvResult) const;
    virtual bool UpdateChannel(float fTime, unsigned int uiChannel,
        NiEvaluatorSPData* pkEvalSPData, void* pvResult) const;
    virtual bool GetChannelScratchPadInfo(unsigned int uiChannel,
        bool bForceAlwaysUpdate, NiAVObjectPalette* pkPalette,
        unsigned int& uiFillSize, bool& bSharedFillData,
        NiScratchPadBlock& eSPBSegmentData,
        NiBSplineBasisData*& pkBasisData) const;
    virtual bool InitChannelScratchPadData(unsigned int uiChannel,
        NiEvaluatorSPData* pkEvalSPData, NiBSplineBasisData* pkSPBasisData,
        bool bInitSharedData, NiAVObjectPalette* pkPalette,
        NiPoseBufferHandle kPBHandle) const;

    // *** end Emergent internal use only ***

protected:
    void SetEvalChannelTypes();

    float m_fFloatValue;
};

NiSmartPointer(NiConstFloatEvaluator);

#include "NiConstFloatEvaluator.inl"

#endif  // #ifndef NICONSTFLOATEVALUATOR_H
