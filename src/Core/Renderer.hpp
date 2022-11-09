#pragma once
#include <sys/process.h>
#undef vector
#include <vector>
#include <vsh/paf.hpp>
#include "Utils/Std.hpp"
#include "Helpers.hpp"

class Renderer
{
public:
    enum Align
    {
        Centered,
        Left = (1 << 0),
        Right = (1 << 1),
        Top = (1 << 4),
        Bottom = (1 << 5)
    };

public:
    Renderer() = default;
    Renderer(float viewportWidth, float viewportHeight)
        : m_ViewportWidth(viewportWidth), m_ViewportHeight(viewportHeight) {}
    ~Renderer();

    void OnUpdate();
    void DestroyWidgets();

    void Rectangle(paf::vec2 position, paf::vec2 size, paf::vec4 color, Align horizontalAlign = Left, Align verticalAlign = Top, const char* systemTexture = nullptr, float angle = 0.0, bool useRadian = false);
    void Gradient(paf::vec2 position, paf::vec2 size, paf::vec4 colorLeft, paf::vec4 colorRight, Align horizontalAlign = Left, Align verticalAlign = Top);
    void Line(paf::vec2 from, paf::vec2 to, float thickness, paf::vec4 color);

    void Text(std::wstring const& text, paf::vec2 position, float height, paf::vec4 color, Align horizontalAlign = Left, Align verticalAlign = Top, float angle = 0.0, bool drawShadow = true);

    void RectangleOverText(paf::vec2 position, paf::vec2 size, paf::vec4 color, Align horizontalAlign = Left, Align verticalAlign = Top, const char* systemTexture = nullptr, float angle = 0.0, bool useRadian = false);

private:
    void DestroyUnusedWidgets();
    void HideWidgets();

    void CreateGroups();
    paf::PhText* CreateText(paf::PhWidget* parent = g_Helpers.m_PageAutoOffGuide);
    paf::PhPlane* CreatePlane(paf::PhWidget* parent = g_Helpers.m_PageAutoOffGuide);

    paf::PhText* GetCurrentText();
    paf::PhPlane* GetCurrentPlane();

    void ViewportScale(paf::vec2& vec);
    void ViewportScaleHorizontal(float& value);
    void ViewportScaleVertical(float& value);

public:
    bool m_CanDraw{};

    float m_ViewportWidth{ 1280.0f };
    float m_ViewportHeight{ 720.0f };

    int m_CurrentText{};
    int m_CurrentPlane{};

    std::vector<paf::PhText*> m_TextNodeChilds{};
    std::vector<paf::PhPlane*> m_PlaneNodeChilds{};

    paf::PhPlane* m_TextNode{};
    paf::PhPlane* m_PlaneNode{};

    paf::PhPlane* m_PlaneOnTop{};
};

extern Renderer g_Renderer;