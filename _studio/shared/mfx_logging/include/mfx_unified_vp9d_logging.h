// Copyright (c) 2022 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _MFX_UNIFIED_LOGGING_H_
#define _MFX_UNIFIED_LOGGING_H_

#include "mfx_config.h"
#ifdef MFX_EVENT_TRACE_DUMP_SUPPORTED

#include "umc_va_base.h"
#include "umc_vp9_ddi.h"
#include "umc_vp9_frame.h"
#include "mfx_unified_decode_logging.h"

typedef struct _DECODE_EVENTDATA_SURFACEOUT_VP9
{
    uint32_t  CropH;
    uint32_t  CropW;
    uint32_t  CropX;
    uint32_t  CropY;
    uint32_t  ChromaFormat;
    uint32_t  AspectRatioH;
    uint32_t  AspectRatioW;
    uint32_t  FrameRateExtD;
    uint32_t  FrameRateExtN;
    uint32_t  PicStruct;
    uint32_t  DataFlag;
    uint32_t  FrameOrder;
    uint32_t  TimeStamp;
} DECODE_EVENTDATA_SURFACEOUT_VP9;

typedef struct _DECODE_EVENTDATA_SYNC_VP9
{
    int32_t currFrameId;
    int32_t copyFromFrame;
    uint32_t index;
    uint32_t showFrame;
} DECODE_EVENTDATA_SYNC_VP9;

typedef struct _DECODE_EVENTDATA_PICTUREPARAM_VP9
{
    uint32_t  m_FrameHeightMinus1;
    uint32_t  m_FrameWidthMinus1;
    uint32_t  m_frame_type;
    uint32_t  m_show_frame;
    uint32_t  m_error_resilient_mode;
    uint32_t  m_intra_only;
    uint32_t  m_LastRefIdx;
    uint32_t  m_LastRefSignBias;
    uint32_t  m_GoldenRefIdx;
    uint32_t  m_GoldenRefSignBias;
    uint32_t  m_AltRefIdx;
    uint32_t  m_AltRefSignBias;
    uint32_t  m_allow_high_precision_mv;
    uint32_t  m_mcomp_filter_type;
    uint32_t  m_frame_parallel_decoding_mode;
    uint32_t  m_segmentation_enabled;
    uint32_t  m_segmentation_temporal_update;
    uint32_t  m_segmentation_update_map;
    uint32_t  m_reset_frame_context;
    uint32_t  m_refresh_frame_context;
    uint32_t  m_frame_context_idx;
    uint32_t  m_LosslessFlag;
    uint32_t  m_ReservedField;
    uint32_t  m_RefFrameList[8];
    uint32_t  m_CurrPic;
    uint32_t  m_filter_level;
    uint32_t  m_sharpness_level;
    uint32_t  m_log2_tile_rows;
    uint32_t  m_log2_tile_columns;
    uint32_t  m_UncompressedHeaderLengthInBytes;
    uint32_t  m_FirstPartitionSize;
    uint32_t  m_mb_segment_tree_probs[7];
    uint32_t  m_segment_pred_probs[3];
    uint32_t  m_BSBytesInBuffer;
    uint32_t  m_StatusReportFeedbackNumber;
    uint32_t  m_profile;
    uint32_t  m_BitDepthMinus8;
    uint32_t  m_subsampling_x;
    uint32_t  m_subsampling_y;
} DECODE_EVENTDATA_PICTUREPARAM_VP9;

typedef struct _EVENT_Intel_Seg_VP9
{
    uint32_t    m_SegmentReferenceEnabled;
    uint32_t    m_SegmentReference;
    uint32_t    m_SegmentReferenceSkipped;
    uint32_t    m_ReservedField3;
    uint32_t    m_FilterLevel[4][2];
    uint32_t    m_LumaACQuantScale;
    uint32_t    m_LumaDCQuantScale;
    uint32_t    m_ChromaACQuantScale;
    uint32_t    m_ChromaDCQuantScale;
} EVENT__Intel_Seg_VP9;

typedef struct _DECODE_EVENTDATA_SEGMENT_VP9
{
    EVENT__Intel_Seg_VP9    m_SegData[8];
} DECODE_EVENTDATA_SEGMENT_VP9;

typedef struct _DECODE_EVENTDATA_OUTPUTFRAME_VP9
{
    uint32_t MemID;
    uint32_t wasDisplayed;
} DECODE_EVENTDATA_OUTPUTFRAME_VP9;

typedef struct _EVENTDATA_DPBINFO_VP9
{
    uint32_t FrameId;
    uint32_t isDecoded;
} EVENTDATA_DPBINFO_VP9;

typedef struct _DECODE_EVENTDATA_DPBINFO_VP9
{
    uint32_t eventCount;
    EVENTDATA_DPBINFO_VP9 DpbInfo[16];
} DECODE_EVENTDATA_DPBINFO_VP9;

void DecodeEventVP9DataSurfaceOutparam(DECODE_EVENTDATA_SURFACEOUT_VP9* pEventData, mfxFrameSurface1** surface_out);
void DecodeEventVP9DpbInfo(DECODE_EVENTDATA_DPBINFO_VP9* pEventData, std::vector<UMC_VP9_DECODER::VP9DecoderFrame> m_submittedFrames);

#endif
#endif

