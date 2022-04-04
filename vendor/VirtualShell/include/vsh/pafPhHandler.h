#ifndef __PAF_PHHANDLER_H__
#define __PAF_PHHANDLER_H__
#include "vshtypes.h"
#include "paf.h"
#include <sys/sys_types.h>

_VSH_BEGIN
_PAF_BEGIN

class PhHandler
{
public:
    enum Handler
    {
        PositionHandler = 0x1000001,
        ColorHandler = 0x1000002,
        SizeHandler = 0x1000004,
        ScaleHandler = 0x1000005,
        RotationHandler = 0x1000006
    };

    int DoCallBack(int callbackId, void* PhEvent)
    {
        return PhHandler_DoCallback(this, callbackId, PhEvent);
    }

    int HandlerProc(void* PhEvent)
    {
        return PhHandler_HandlerProc(this, PhEvent);
    }

    int KillTimerCB(int callbackId)
    {
        return PhHandler_KillTimerCB(this, callbackId);
    }

    int SetCallBack(int callbackId, void(*callback)(PhWidget* widget, void* PhEvent, void* unknown), void* unknown)
    {
        return PhHandler_SetCallback(this, callbackId, (void(*)(void*, void*, void*))callback, unknown);
    }

    int SetDeleteCB(void(*callback)(PhWidget*, void* PhEvent, void* unknown), void* unknown)
    {
        return PhHandler_SetDeleteCB(this, (void(*)(void*, void*, void*))callback, unknown);
    }

    int HandleFocusEvent(void* PhEvent)
    {
        return PhHandler_HandleFocusEvent(this, PhEvent);
    }

    int HandlePointEvent(void* PhEvent)
    {
        return PhHandler_HandlePointEvent(this, PhEvent);
    }

    int HandleStateEvent(void* PhEvent)
    {
        return PhHandler_HandleStateEvent(this, PhEvent);
    }

    int HandleSystemEvent(void* PhEvent)
    {
        return PhHandler_HandleSystemEvent(this, PhEvent);
    }

    int HandleCommandEvent(void* PhEvent)
    {
        return PhHandler_HandleCommandEvent(this, PhEvent);
    }

    int HandleKeycodeEvent(void* PhEvent)
    {
        return PhHandler_HandleKeycodeEvent(this, PhEvent);
    }

    bool IsTimerCB(int callbackId)
    {
        return PhHandler_IsTimerCB(this, callbackId);
    }
};

_PAF_END
_VSH_END

#endif // __PAF_PHHANDLER_H__