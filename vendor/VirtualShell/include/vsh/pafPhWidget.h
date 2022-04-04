#ifndef __PAF_PHWIDGET_H__
#define __PAF_PHWIDGET_H__
#include "vshtypes.h"
#include "pafPhHandler.h"
#include "pafView.h"
#include "vshmath.h"
#include "paf.h"
#include "stdc.h"
#include <string>

_VSH_BEGIN
_PAF_BEGIN

struct opd_s
{
    uint32_t func;
    uint32_t toc;
};

struct Surface
{
    std::uint8_t __padding_0x0[0x68];
};

class PhWidget : public PhHandler
{
public:
    enum Style
    {
        Anchor = 0x12,
        TextAlignment = 0x31,
        TextShadow = 0x38 // true by default
    };

    enum TextAlignmentStyle
    {
        TextAlignCenter,
        TextAlignLeft = (1 << 0),
        TextAlignRight = (1 << 1)
    };

    enum AnchorStyle
    {
        AnchorCenter,
        AnchorLeft = (1 << 0),
        AnchorRight = (1 << 1),
        AnchorTop = (1 << 4),
        AnchorBottom = (1 << 5)
    };

public:
    PhWidget() {};

    PhWidget* FindChild(const char* childName)
    {
        return (PhWidget*)PhWidget_FindChild(this, childName, 0);
    }

    void RegistChild(PhWidget* child)
    {
        PhWidget_RegistChild(this, child);
    }

    void RemoveChild(PhWidget* child)
    {
        PhWidget_RemoveChild(this, child);
    }

    bool IsAttached()
    {
        if (!m_Data.name.empty() && m_Data.parent)
        {
            if (m_Data.parent->FindChild(m_Data.name.c_str()))
            {
                return true;
            }
        }

        return false;
    }

    void Attach(PhWidget* parent)
    {
        if (!parent || IsAttached())
            return;

        parent->RegistChild(this);
        m_Data.parent = parent;
    }

    void Detach()
    {
        if (!m_Data.parent || !IsAttached())
            return;

        m_Data.parent->RemoveChild(this);
        m_Data.parent = nullptr;
    }

    PhWidget& SetName(const std::string& name)
    {
        m_Data.name = name;
        return *this;
    }

    PhWidget& SetLayoutPos(int positionLayoutFactorX, int positionLayoutFactorY, int positionLayoutFactorZ, vec4 position)
    {
        position.w = 0.0;
        m_Data.positionLayoutFactorX = positionLayoutFactorX;
        m_Data.positionLayoutFactorY = positionLayoutFactorY;
        m_Data.positionLayoutFactorZ = positionLayoutFactorZ;
        m_Data.positionLayout = position;
        return UpdateLayoutPos();
    }

    PhWidget& SetLayoutSize(int sizeLayoutFactorX, int sizeLayoutFactorY, int sizeLayoutFactorZ, vec4 size)
    {
        size.w = 0.0;
        m_Data.sizeLayoutFactorX = sizeLayoutFactorX;
        m_Data.sizeLayoutFactorY = sizeLayoutFactorY;
        m_Data.sizeLayoutFactorZ = sizeLayoutFactorZ;
        m_Data.sizeLayout = size;
        return UpdateLayoutSize();
    }

    PhWidget& SetLayoutStyle(int r4, int r5, float f1)
    {
        if (!m_Data.sRender)
            return *this;
        // sub_3F1164 calls paf::PhSText::SetLayoutStyle(int, int, float)
        // 006D6918 PhSText vtable
        m_Data.sRender->CallVirtualMethod<void>(29, m_Data.sRender, r4, r5, f1);
        return *this;
    }

    PhWidget& SetPosition(vec2 position)
    {
        ViewportScale(position);
        return SetLayoutPos(6, 5, 0, vec4(position.x, position.y, 0.0, 0.0));
    }

    PhWidget& SetSize(vec2 size)
    {
        ViewportScale(size);
        return SetLayoutSize(6, 5, 0, vec4(size.x, size.y, 0.0, 0.0));
    }

    PhWidget& SetRotation(vec4 rotation, PhWidget* widget, bool useRadian)
    {
        if (!useRadian)
            rotation *= (3.1415926535897 / 180.0);

        PhWidget_SetRot_ontimer(this, rotation, widget, 0);
        KillTimerCB(PhHandler::RotationHandler);
        return *this;
    }

    PhWidget& SetRotation(float rollAngle, bool useRadian)
    {
        return SetRotation(vec4(0.0, 0.0, rollAngle, 0.0), nullptr, useRadian);
    }

    PhWidget& SetColor(vec4 rgba)
    {
        m_Data.colorScaleRGBA = rgba.clamp(0.0, 1.0);
        KillTimerCB(PhHandler::ColorHandler);
        return *this;
    }

    PhWidget& SetColor32(uint32_t rgba)
    {
        vec4 color =
        {
           static_cast<float>((rgba & 0xFF000000) >> 24) / 255,
           static_cast<float>((rgba & 0x00FF0000) >> 16) / 255,
           static_cast<float>((rgba & 0x0000FF00) >> 8) / 255,
           static_cast<float>(rgba & 0x000000FF) / 255
        };

        return SetColor(color);
    }

    PhWidget& SetTexture(Surface* texture)
    {
        if (!m_Data.sRender || !texture)
            return *this;

        m_Data.sRender->CallVirtualMethod<void>(40, m_Data.sRender, &texture, 0);
        return UpdatePrepare();
    }

    PhWidget& SetSystemTexture(const char* textureName)
    {
        View* system_plugin = View::Find("system_plugin");
        if (!system_plugin)
            return *this;

        SetTexture(system_plugin->GetTexture(textureName));
        return *this;
    }

    PhWidget& SetStyle(int style, bool value)
    {
        if (!m_Data.sRender)
            return *this;

        m_Data.sRender->CallVirtualMethod<void>(11, m_Data.sRender, style, value);
        return UpdatePrepare();
    }

    PhWidget& SetStyle(int style, int value)
    {
        if (!m_Data.sRender)
            return *this;

        m_Data.sRender->CallVirtualMethod<void>(12, m_Data.sRender, style, value);
        return UpdatePrepare();
    }

    PhWidget& SetStyle(int style, float value)
    {
        if (!m_Data.sRender)
            return *this;

        m_Data.sRender->CallVirtualMethod<void>(13, m_Data.sRender, style, value);
        return UpdatePrepare();
    }

    PhWidget& SetStyle(int style, vec4 const& value)
    {
        if (!m_Data.sRender)
            return *this;

        m_Data.sRender->CallVirtualMethod<void>(14, m_Data.sRender, style, value);
        return UpdatePrepare();
    }

    PhWidget& UpdateLayoutPos()
    {
        PhWidget_UpdateLayoutPos(this);
        return *this;
    }

    PhWidget& UpdateLayoutSize()
    {
        PhWidget_UpdateLayoutSize(this);
        return *this;
    }

    PhWidget& UpdatePrepare()
    {
        PhWidget_UpdatePrepare(this);
        return *this;
    }

    static float GetViewportWidth()
    {
        return 1280.0f;
    }

    static float GetViewportHeight()
    {
        return 720.0;
    }

    static void ViewportScaleHorizontal(float& value)
    {
        vec2 vec = { value, 0 };
        ViewportScale(vec);
        value = vec.x;
    }

    static void ViewportScaleVertical(float& value)
    {
        vec2 vec = { 0, value };
        ViewportScale(vec);
        value = vec.y;
    }

    static void ViewportScale(vec2& vec)
    {
        float screenWidth = static_cast<float>(pafGuGetDrawSurfW());
        float screenHeight = static_cast<float>(pafGuGetDrawSurfH());

        // 720 / 480 = 1.5
        // 720 / 576 = 1.25
        // 1280 / 720 = 1.777777777777777
        // 1280 / 1080 = 1.185185185185
        // 1920 / 1080 = 1.77777777777777
        float aspectRatio = screenWidth / screenHeight;

        if (aspectRatio < 1.2)
            return;

        vec.x *= (screenWidth / GetViewportWidth());
        vec.y *= (screenHeight / GetViewportHeight());
    }

    // I'm not even sure that these works
    static void RevertViewportScaleHorizontal(float& value)
    {
        vec2 vec = { value, 0 };
        RevertViewportScale(vec);
        value = vec.x;
    }

    static void RevertViewportScaleVertical(float& value)
    {
        vec2 vec = { 0, value };
        RevertViewportScale(vec);
        value = vec.y;
    }

    static void RevertViewportScale(vec2& vec)
    {
        float screenWidth = static_cast<float>(paf_F476E8AA());
        float screenHeight = static_cast<float>(paf_AC984A12());

        // 720 / 480 = 1.5
        // 720 / 576 = 1.25
        // 1280 / 720 = 1.777777777777777
        // 1280 / 1080 = 1.185185185185
        // 1920 / 1080 = 1.77777777777777
        float aspectRatio = screenWidth / screenHeight;

        if (aspectRatio < 1.2)
            return;

        vec.x *= (GetViewportWidth() / screenWidth);
        vec.y *= (GetViewportHeight() / screenHeight);
    }

    template <typename R, typename... Args>
    R CallVirtualMethod(int methodIndex, Args... args)
    {
        R(*method)(Args...) = (R(*)(Args...))(this->m_Data.vtable[methodIndex]);
        return method(args...);
    }

public:
    struct
    {
        opd_s** vtable;				// 0x000
        std::string name;					// 0x004
        std::uint8_t __padding_0x20[0xC0];	// 0x020
        PhWidget* parent;					// 0x0E0
        std::uint8_t __padding_0xE4[0xC];	// 0x0E4
        struct								// 0x0F0
        {
            opd_s** vtable;				// 0x000 | 0x006D9188
            std::uint8_t __padding_0x4[0x24];	// 0x004
            struct								// 0x028
            {
                opd_s** vtable;				// 0x000
                std::uint8_t __padding_0x4[0x28];	// 0x004
                std::wstring text;					// 0x02C
                std::uint8_t __padding_0x48[0x160];	// 0x048
                vec2 shadowPosition;				// 0x1A8
                vec2 scale;							// 0x1B0
                // ...
            } *PhSText; // Size: 0x200+

            template <typename R, typename... TArgs>
            R CallVirtualMethod(int methodIndex, TArgs... args)
            {
                R(*method)(TArgs...) = (R(*)(TArgs...))(this->vtable[methodIndex]);
                return method(args...);
            }
        } *sRender; // Size: ~0x40
        std::uint8_t __padding_0xF4[0x18];	// 0x0F4
        float metaAlpha;					// 0x10C
        std::uint8_t __padding_0x110[0x10];	// 0x110
        vec4 colorScaleRGBA;				// 0x120
        vec4 positionOnTimer;				// 0x130
        vec4 scaleOnTimer;					// 0x140
        vec4 rotationOnTimer;				// 0x150
        std::uint8_t __padding_0x160[0x4C];	// 0x160
        float verticalItalicAmount;			// 0x1AC
        float scaleY;						// 0x1B0
        std::uint8_t __padding_0x1B4[0xC];	// 0x1B4
        float horizontalItalicAmount;		// 0x1C0
        float scaleX;						// 0x1C4
        std::uint8_t __padding_0x1C8[0x18];	// 0x1C8
        vec4 position;						// 0x1E0
        std::uint8_t __padding_0x1F0[0x40];	// 0x1F0
        vec4 sizeOnTimer;					// 0x230
        std::uint8_t __padding_0x240[0x10];	// 0x240
        int positionLayoutFactorX;			// 0x250
        int positionLayoutFactorY;			// 0x254
        int positionLayoutFactorZ;			// 0x258
        vec4 positionLayout;				// 0x25C
        int sizeLayoutFactorX;				// 0x26C
        int sizeLayoutFactorY;				// 0x270
        int sizeLayoutFactorZ;				// 0x274
        vec4 sizeLayout;					// 0x278
        std::uint8_t __padding_0x288[0x8];	// 0x288

    } m_Data; // Size: 0x290
};

_PAF_END
_VSH_END

#endif // __PAF_PHWIDGET_H__