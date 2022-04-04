#ifndef __PAF_PHPLANE_H__
#define __PAF_PHPLANE_H__
#include "vshtypes.h"
#include "pafPhWidget.h"
#include "paf.h"

_VSH_BEGIN
_PAF_BEGIN

class PhPlane : public PhWidget
{
public:
    PhPlane(PhWidget* parent, void* PhAppear = nullptr)
    {
        PhPlane_Constructor(this, parent, PhAppear);
    }

    ~PhPlane()
    {
        if (IsAttached())
            PhPlane_Destructor(this);
    }
};

_PAF_END
_VSH_END

#endif // __PAF_PHPLANE_H__