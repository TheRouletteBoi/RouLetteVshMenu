#ifndef __PNGDEC_PPUONLY_HPP__
#define __PNGDEC_PPUONLY_HPP__

#include <cell/codec/pngdec.h>

namespace pngdec
{
    CDECL_BEGIN

    int pngdec_ppuonly_0C515302(CellPngDecMainHandle m, CellPngDecSubHandle *s, const CellPngDecSrc *src, CellPngDecOpnInfo *openInfo, const CellPngDecCbCtrlStrm *cbCtrlStrm, const CellPngDecOpnParam *opnParam);
    static int cellPngDecExtOpen(CellPngDecMainHandle m, CellPngDecSubHandle *s, const CellPngDecSrc *src, CellPngDecOpnInfo *openInfo, const CellPngDecCbCtrlStrm *cbCtrlStrm, const CellPngDecOpnParam *opnParam) {
        return pngdec_ppuonly_0C515302(m, s, src, openInfo, cbCtrlStrm, opnParam);
    }

    int pngdec_ppuonly_157D30C5(CellPngDecMainHandle *m, const CellPngDecThreadInParam *in, CellPngDecThreadOutParam *out);
    static int cellPngDecCreate(CellPngDecMainHandle *m, const CellPngDecThreadInParam *in, CellPngDecThreadOutParam *out) {
        return pngdec_ppuonly_157D30C5(m, in, out);
    }

    int pngdec_ppuonly_2310F155(CellPngDecMainHandle m, CellPngDecSubHandle s, uint8_t *buf, const CellPngDecDataCtrlParam *ctl, CellPngDecDataOutInfo *out);
    static int cellPngDecDecodeData(CellPngDecMainHandle m, CellPngDecSubHandle s, uint8_t *buf, const CellPngDecDataCtrlParam *ctl, CellPngDecDataOutInfo *out) {
        return pngdec_ppuonly_2310F155(m, s, buf, ctl, out);
    }

    int pngdec_ppuonly_48436B2D(CellPngDecMainHandle *m, const CellPngDecThreadInParam *threadInParam, CellPngDecThreadOutParam *threadOutParam, const CellPngDecExtThreadInParam *extThreadInParam, CellPngDecExtThreadOutParam *extThreadOutParam);
    static int cellPngDecExtCreate(CellPngDecMainHandle *m, const CellPngDecThreadInParam *threadInParam, CellPngDecThreadOutParam *threadOutParam, const CellPngDecExtThreadInParam *extThreadInParam, CellPngDecExtThreadOutParam *extThreadOutParam) {
        return pngdec_ppuonly_48436B2D(m, threadInParam, threadOutParam, extThreadInParam, extThreadOutParam);
    }

    int pngdec_ppuonly_5B3D1FF1(CellPngDecMainHandle m, CellPngDecSubHandle s);
    static int cellPngDecClose(CellPngDecMainHandle m, CellPngDecSubHandle s) {
        return pngdec_ppuonly_5B3D1FF1(m, s);
    }

    int pngdec_ppuonly_726FC1D0(CellPngDecMainHandle m, CellPngDecSubHandle s, uint8_t *data, const CellPngDecDataCtrlParam *dataCtrlParam, CellPngDecDataOutInfo *dataOutInfo, const CellPngDecCbCtrlDisp *cbCtrlDisp, CellPngDecDispParam *dispParam);
    static int cellPngDecExtDecodeData(CellPngDecMainHandle m, CellPngDecSubHandle s, uint8_t *data, const CellPngDecDataCtrlParam *dataCtrlParam, CellPngDecDataOutInfo *dataOutInfo, const CellPngDecCbCtrlDisp *cbCtrlDisp, CellPngDecDispParam *dispParam) {
        return pngdec_ppuonly_726FC1D0(m, s, data, dataCtrlParam, dataOutInfo, cbCtrlDisp, dispParam);
    }

    int pngdec_ppuonly_820DAE1A(CellPngDecMainHandle m);
    static int cellPngDecDestroy(CellPngDecMainHandle m) {
        return pngdec_ppuonly_820DAE1A(m);
    }

    int pngdec_ppuonly_8B33F863(CellPngDecMainHandle m, CellPngDecSubHandle s, CellPngDecInfo *info, CellPngDecExtInfo *extInfo);
    static int cellPngDecExtReadHeader(CellPngDecMainHandle m, CellPngDecSubHandle s, CellPngDecInfo *info, CellPngDecExtInfo *extInfo) {
        return pngdec_ppuonly_8B33F863(m, s, info, extInfo);
    }

    int pngdec_ppuonly_9CCDCC95(CellPngDecMainHandle m, CellPngDecSubHandle s, CellPngDecInfo *info);
    static int cellPngDecReadHeader(CellPngDecMainHandle m, CellPngDecSubHandle s, CellPngDecInfo *info) {
        return pngdec_ppuonly_9CCDCC95(m, s, info);
    }

    int pngdec_ppuonly_9E9D7D42(CellPngDecMainHandle m, CellPngDecSubHandle s, const CellPngDecInParam *inParam, CellPngDecOutParam *outParam, const CellPngDecExtInParam *extInParam, CellPngDecExtOutParam *extOutParam);
    static int cellPngDecExtSetParameter(CellPngDecMainHandle m, CellPngDecSubHandle s, const CellPngDecInParam *inParam, CellPngDecOutParam *outParam, const CellPngDecExtInParam *extInParam, CellPngDecExtOutParam *extOutParam) {
        return pngdec_ppuonly_9E9D7D42(m, s, inParam, outParam, extInParam, extOutParam);
    }

    int pngdec_ppuonly_D2BC5BFD(CellPngDecMainHandle m, CellPngDecSubHandle *s, const CellPngDecSrc *src, CellPngDecOpnInfo *info);
    static int cellPngDecOpen(CellPngDecMainHandle m, CellPngDecSubHandle *s, const CellPngDecSrc *src, CellPngDecOpnInfo *info) {
        return pngdec_ppuonly_D2BC5BFD(m, s, src, info);
    }

    int pngdec_ppuonly_E97C9BD4(CellPngDecMainHandle m, CellPngDecSubHandle s, const CellPngDecInParam *in, CellPngDecOutParam *out);
    static int cellPngDecSetParameter(CellPngDecMainHandle m, CellPngDecSubHandle s, const CellPngDecInParam *in, CellPngDecOutParam *out) {
        return pngdec_ppuonly_E97C9BD4(m, s, in, out);
    }

    CDECL_END
}

#endif // __PNGDEC_PPUONLY_HPP__