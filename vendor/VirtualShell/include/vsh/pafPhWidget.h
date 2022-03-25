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
   char __padding_0x0[0x68];
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
      TextAlignLeft,
      TextAlignRight
   };

   enum AnchorStyle
   {
      AnchorCenter,
      AnchorLeft = (1 << 0),
      AnchorRight = (1 << 1),
      AnchorTop = (1 << 4),
      AnchorBottom = (1 << 5)

      /*
      0x11 | 0x10 | 0x12
      -----+------+-----
      0x01 | 0x00 | 0x02
      -----+------+-----
      0x21 | 0x20 | 0x22
      */
   };

public:
   PhWidget() {}

   PhWidget* FindChild(const char* childName, int r5)
   {
      return (PhWidget*)PhWidget_FindChild(this, childName, r5);
   }

   bool HasChild(const char* childName)
   {
      return this->FindChild(childName, 0) != nullptr;
   }

   void RegistChild(PhWidget* child)
   {
      PhWidget_RegistChild(this, child);
   }

   void RemoveChild(PhWidget const* child)
   {
      PhWidget_RemoveChild(this, child);
   }

   bool IsAttached()
   {
      return (this->parent) ? ((this->name.data()[0]) ? this->parent->HasChild(this->name.data()) : false) : false;
   }

   void SetName(const std::string& name)
   {
      this->name = name;
   }

   void SetLayoutPos(int positionLayoutFactorX, int positionLayoutFactorY, int positionLayoutFactorZ, vec4 position)
   {
      position.w = 0.0f;
      this->positionLayoutFactorX = positionLayoutFactorX;
      this->positionLayoutFactorY = positionLayoutFactorY;
      this->positionLayoutFactorZ = positionLayoutFactorZ;
      this->positionLayout = position;
      this->UpdateLayoutPos();
   }

   void SetLayoutSize(int sizeLayoutFactorX, int sizeLayoutFactorY, int sizeLayoutFactorZ, vec4 size)
   {
      size.w = 0.0f;
      this->sizeLayoutFactorX = sizeLayoutFactorX;
      this->sizeLayoutFactorY = sizeLayoutFactorY;
      this->sizeLayoutFactorZ = sizeLayoutFactorZ;
      this->sizeLayout = size;
      this->UpdateLayoutSize();
   }

   void SetLayoutStyle(int r4, int r5, float f1)
   {
      if (!this->sRender)
         return;

      this->sRender->CallMethod<void>(29, this->sRender, r4, r5, f1);
   }

   void SetPosition(vec2 pos)
   {
      float screenWidth = static_cast<float>(pafGuGetDrawSurfW());
      float screenHeight = static_cast<float>(pafGuGetDrawSurfH());
      this->SetLayoutPos(6, 5, 0, vec4((screenWidth / 1280.0f) * pos.x, (screenHeight / 1080.0f) * pos.y, 0.0f, 0.0f));
   }

   void SetSize(vec2 size)
   {
      float screenWidth = static_cast<float>(pafGuGetDrawSurfW());
      float screenHeight = static_cast<float>(pafGuGetDrawSurfH());
      this->SetLayoutSize(6, 5, 0, vec4((screenWidth / 1280.0f) * size.x, (screenHeight / 1080.0f) * size.y, 0.0f, 0.0f));
   }

   void SetRotation(vec4 rotation, PhWidget* widget, bool useRadian)
   {
      if (!useRadian)
         rotation *= (M_PI / 180.0f);

      PhWidget_SetRot_ontimer(this, rotation, widget, 0);
      this->KillTimerCB(PhHandler::RotationHandler);
   }

   void SetRotation(float angle, bool useRadian)
   {
      this->SetRotation(vec4(0.0f, 0.0f, angle, 0.0f), nullptr, useRadian);
   }

   void SetColor(vec4 rgba)
   {
      this->colorScaleRGBA = rgba.clamp(0.0f, 1.0f);
      this->KillTimerCB(PhHandler::ColorHandler);
   }

   void SetColor32(uint32_t rgba)
   {
      vec4 color = vec4(static_cast<float>((rgba & 0xFF000000) >> 24) / 255,
         static_cast<float>((rgba & 0x00FF0000) >> 16) / 255,
         static_cast<float>((rgba & 0x0000FF00) >> 8) / 255,
         static_cast<float>((rgba & 0x000000FF)) / 255);
      this->SetColor(color);
   }

   void SetTexture(Surface* texture)
   {
      if (!this->sRender || !texture)
         return;

      //SurfaceRCPtr* surface = &texture;
      this->sRender->CallMethod<void>(40, this->sRender, &texture, 0);
      this->UpdatePrepare();
   }

   void SetSystemTexture(const char* textureName)
   {
      View* system_plugin = View::Find("system_plugin");
      if (!system_plugin)
         return;

      this->SetTexture(system_plugin->GetTexture(textureName));
   }

   void SetStyle(int style, bool value)
   {
      if (!this->sRender)
         return;

      this->sRender->CallMethod<void>(11, this->sRender, style, value);
      this->UpdatePrepare();
   }

   void SetStyle(int style, int value)
   {
      if (!this->sRender)
         return;

      this->sRender->CallMethod<void>(12, this->sRender, style, value);
      this->UpdatePrepare();
   }

   void SetStyle(int style, float value)
   {
      if (!this->sRender)
         return;

      this->sRender->CallMethod<void>(13, this->sRender, style, value);
      this->UpdatePrepare();
   }

   void SetStyle(int style, vec4 const& value)
   {
      if (!this->sRender)
         return;

      this->sRender->CallMethod<void>(14, this->sRender, style, &value);
      this->UpdatePrepare();
   }

   void UpdateLayoutPos()
   {
      PhWidget_UpdateLayoutPos(this);
   }

   void UpdateLayoutSize()
   {
      PhWidget_UpdateLayoutSize(this);
   }

   void UpdatePrepare()
   {
      PhWidget_UpdatePrepare(this);
   }


   template <typename Result, typename... TArgs>
   Result CallMethod(int methodIndex, TArgs... args)
   {
      volatile Result(*method)(TArgs...) = nullptr;
      method = decltype(method)(this->vtable[methodIndex]);
      return method(args...);
   }

private: // Data - size: 0x290
   opd_s** vtable;				// 0x000
   std::string name;			// 0x004
   char __padding_0x20[0xC0];	// 0x020
   // 0x024 constructor does: this->__0x24 |= (1 << 8);
   PhWidget* parent;			// 0x0E0
   char __padding_0xE4[0xC];
   struct {					// 0x0F0
      opd_s** vtable;				// 0x000 | off_6D2400
      char __padding_0x4[0x24];	// 0x004

      template <typename Result, typename... TArgs>
      Result CallMethod(int methodIndex, TArgs... args)
      {
         volatile Result(*method)(TArgs...) = nullptr;
         method = decltype(method)(this->vtable[methodIndex]);
         return method(args...);
      }
   } *sRender; // size: 0x28
   char __padding_0xF4[0x18];	// 0x0F4
   float metaAlpha;			// 0x10C
   char __padding_0x110[0x10];	// 0x110
   vec4 colorScaleRGBA;		// 0x120
   vec4 positionOnTimer;		// 0x130
   vec4 scaleOnTimer;			// 0x140
   vec4 rotationOnTimer;		// 0x150
   char __padding_0x160[0x4C];	// 0x160
   float verticalItalicAmount;	// 0x1AC
   float scaleY;				// 0x1B0
   char __padding_0x1B4[0xC];	// 0x1B4
   float horizontalItalicAmount; // 0x1C0
   float scaleX;				// 0x1C4
   char __padding_0x1C8[0x18];	// 0x1C8
   vec4 position;				// 0x1E0
   char __padding_0x1F0[0x40];	// 0x1F0
   vec4 sizeOnTimer;			// 0x230
   char __padding_0x240[0x10];	// 0x240
   int positionLayoutFactorX;	// 0x250
   int positionLayoutFactorY;	// 0x254
   int positionLayoutFactorZ;	// 0x258
   vec4 positionLayout;		// 0x25C
   int sizeLayoutFactorX;		// 0x26C
   int sizeLayoutFactorY;		// 0x270
   int sizeLayoutFactorZ;		// 0x274
   vec4 sizeLayout;			// 0x278
   char __padding_0x288[0x8];	// 0x288
};

_PAF_END
_VSH_END

#endif // __PAF_PHWIDGET_H__