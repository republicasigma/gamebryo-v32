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
#ifndef NIBSPLINEFLOATEVALUATOR_H
#define NIBSPLINEFLOATEVALUATOR_H

#include "NiBSplineEvaluator.h"

class NIANIMATION_ENTRY NiBSplineFloatEvaluator :
    public NiBSplineEvaluator
{
    NiDeclareRTTI;
    NiDeclareClone(NiBSplineFloatEvaluator);
    NiDeclareStream;
    NiDeclareViewerStrings;

public:
    enum Channel
    {
        FLOAT = EVALBASEINDEX
    };

    NiBSplineFloatEvaluator();
    NiBSplineFloatEvaluator(NiBSplineData* pkData,
        NiBSplineData::Handle kFloatCPHandle,
        NiBSplineBasisData* pkBasisData);

    // Implemented from NiBSplineEvaluator
    virtual unsigned short GetChannelCount() const;
    virtual unsigned int GetDimension(unsigned short usChannel) const;
    virtual unsigned int GetDegree(unsigned short usChannel) const;

    virtual NiBSplineData::Handle GetControlHandle(
        unsigned short usChannel) const;
    virtual void SetControlHandle(NiBSplineData::Handle kControlHandle,
        unsigned short usChannel);

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

    static bool BSplineFloatFillFunction(float fTime,
        NiEvaluatorSPData* pkEvalSPData);

    // *** end Emergent internal use only ***

protected:
    // Only derived compact classes should call this constructor.
    NiBSplineFloatEvaluator(NiBSplineData* pkData,
        NiBSplineData::Handle kFloatCPHandle,
        NiBSplineBasisData* pkBasisData, bool bCompactCPs);

    void SetEvalChannelTypes();

    // Handle into the NiBSplineData for access to control points.
    NiBSplineData::Handle m_kFloatCPHandle;
};

NiSmartPointer(NiBSplineFloatEvaluator);

#endif  // #ifndef NIBSPLINEFLOATEVALUATOR_H
