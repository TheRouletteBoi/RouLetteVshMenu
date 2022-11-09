#include "Renderer.hpp"

Renderer g_Renderer;

Renderer::~Renderer()
{
    DestroyWidgets();
}

void Renderer::OnUpdate()
{
    m_CanDraw = false;
    m_CurrentText = 0;
    m_CurrentPlane = 0;

    if (!g_Helpers.m_SystemPlugin)
        return;

    if (!g_Helpers.m_PageAutoOffGuide)
    {
        DestroyWidgets();
        return;
    }

    // check if our widgets are still allocated
    if (m_PlaneOnTop)
    {
        if (!m_PlaneOnTop->IsAttached())
        {
            DestroyWidgets();
            return;
        }
    }
    else
        CreateGroups();

    DestroyUnusedWidgets();
    HideWidgets();
    m_CanDraw = true;
}

void Renderer::DestroyWidgets()
{
    m_CanDraw = false;

    // idk if the childs of a widget are automatically destroyed or not
    for (auto text : m_TextNodeChilds)
        delete text;
    m_TextNodeChilds.clear();

    for (auto plane : m_PlaneNodeChilds)
        delete plane;
    m_PlaneNodeChilds.clear();


    if (m_TextNode)
    {
        delete m_TextNode;
        m_TextNode = nullptr;
    }

    if (m_PlaneNode)
    {
        delete m_PlaneNode;
        m_PlaneNode = nullptr;
    }

    if (m_PlaneOnTop)
    {
        delete m_PlaneOnTop;
        m_PlaneOnTop = nullptr;
    }
}

void Renderer::DestroyUnusedWidgets()
{
    for (int i = 0; i < m_TextNodeChilds.size(); i++)
        if (m_TextNodeChilds[i]->GetColor().a == 0.0)
            m_TextNodeChilds.erase(m_TextNodeChilds.begin() + i);

    for (int i = 0; i < m_PlaneNodeChilds.size(); i++)
        if (m_PlaneNodeChilds[i]->GetColor().a == 0.0)
            m_PlaneNodeChilds.erase(m_PlaneNodeChilds.begin() + i);
}

void Renderer::HideWidgets()
{
    for (auto text : m_TextNodeChilds)
        text->ClearColor();

    for (auto plane : m_PlaneNodeChilds)
        plane->ClearColor();

    m_PlaneOnTop->ClearColor();
}

void Renderer::CreateGroups()
{
    DestroyWidgets();

    m_PlaneNode = CreatePlane();

    if (!m_PlaneNode)
        return;

    m_TextNode = CreatePlane();
    m_PlaneOnTop = CreatePlane();
}

paf::PhText* Renderer::CreateText(paf::PhWidget* parent)
{
    paf::PhText* phText = new paf::PhText(parent);

    phText->SetName(vsh::va("text_%p", phText)) // using the ptr to be sure the name is unique
        .SetColor(paf::vec4())
        .SetStyle(0x13, int(0x70)); // dunno what this is but its needed

    return phText;
}

paf::PhPlane* Renderer::CreatePlane(paf::PhWidget* parent)
{
    paf::PhPlane* phPlane = new paf::PhPlane(parent);

    phPlane->SetName(vsh::va("plane_%p", phPlane)) // using the ptr to be sure the name is unique
        .SetColor(paf::vec4());

    return phPlane;
}

paf::PhText* Renderer::GetCurrentText()
{
    if (m_TextNodeChilds.size() <= m_CurrentText)
    {
        paf::PhText* text = CreateText(m_TextNode);
        if (!text)
            return nullptr;

        m_TextNodeChilds.push_back(text);
    }

    paf::PhText* currentText = m_TextNodeChilds[m_CurrentText];

    if (m_CurrentText) // not first element
    {
        paf::PhText* previousText = m_TextNodeChilds[m_CurrentText - 1];
        m_TextNode->ReorderChildren(previousText, currentText, 0x100);
    }

    m_CurrentText++;
    return currentText;
}

paf::PhPlane* Renderer::GetCurrentPlane()
{
    if (m_PlaneNodeChilds.size() <= m_CurrentPlane)
    {
        paf::PhPlane* plane = CreatePlane(m_PlaneNode);
        if (!plane)
            return nullptr;

        m_PlaneNodeChilds.push_back(plane);
    }

    paf::PhPlane* currentPlane = m_PlaneNodeChilds[m_CurrentPlane];

    if (m_CurrentPlane) // not first element
    {
        paf::PhPlane* previousPlane = m_PlaneNodeChilds[m_CurrentPlane - 1];
        m_PlaneNode->ReorderChildren(previousPlane, currentPlane, 0x100);
    }

    m_CurrentPlane++;
    return currentPlane;
}

void Renderer::ViewportScale(paf::vec2& vec)
{
    paf::vec2 currentViewport{ paf::GetScreenWidth(), paf::GetScreenHeight() };
    paf::vec2 myViewport{ m_ViewportWidth, m_ViewportHeight };

    float currentAspectRatio = currentViewport.x / currentViewport.y;
    float myAspectRatio = myViewport.x / myViewport.y;

    vec *= currentViewport / myViewport;
    vec.y *= currentAspectRatio / myAspectRatio;
}

void Renderer::ViewportScaleHorizontal(float& value)
{
    paf::vec2 vec{ value, 0 };
    ViewportScale(vec);
    value = vec.x;
}

void Renderer::ViewportScaleVertical(float& value)
{
    paf::vec2 vec{ 0, value };
    ViewportScale(vec);
    value = vec.y;
}

void Renderer::Rectangle(paf::vec2 position, paf::vec2 size, paf::vec4 color, Align horizontalAlign, Align verticalAlign, const char* systemTexture, float angle, bool useRadian)
{
    if (!m_CanDraw || color.a <= 0.0)
        return;

    paf::PhPlane* plane = GetCurrentPlane();

    if (plane)
    {
        //color /= 255;

        ViewportScale(position);
        ViewportScale(size);

        plane->SetPosition(position)
            .SetSize(size)
            .SetColor(color)
            .SetRotation(angle, useRadian)
            .SetStyle(paf::PhWidget::Anchor, int(horizontalAlign | verticalAlign));

        paf::SurfacePtr pTexture = paf::SurfacePtr();
        if (systemTexture)
            pTexture = g_Helpers.m_SystemPlugin->GetTexture(systemTexture);

        plane->SetTexture(pTexture);
    }
}

void Renderer::Gradient(paf::vec2 position, paf::vec2 size, paf::vec4 colorLeft, paf::vec4 colorRight, Align horizontalAlign, Align verticalAlign)
{
    Rectangle(position, size, colorLeft, horizontalAlign, verticalAlign, "tex_optionmenu_game");
    Rectangle(position, size, colorRight, horizontalAlign, verticalAlign, "tex_optionmenu_game", 180);
}

void Renderer::Line(paf::vec2 from, paf::vec2 to, float thickness, paf::vec4 color)
{
    float width = to.x - from.x,
        height = to.y - from.y,
        hypotenuse = vsh::sqrtf(width * width + height * height),
        angle = vsh::atan2f(height, width);

    Rectangle(from, paf::vec2(hypotenuse + thickness / 2, thickness), color, Left, Top, nullptr, angle, true);
}

void Renderer::Text(std::wstring const& text, paf::vec2 position, float height, paf::vec4 color, Align horizontalAlign, Align verticalAlign, float angle, bool drawShadow)
{
    if (!m_CanDraw || color.a <= 0.0)
        return;

    paf::PhText* label = GetCurrentText();

    if (label)
    {
        //color /= 255;

        position.y -= (height * 0.125);
        height *= 0.75;

        ViewportScale(position);
        ViewportScaleVertical(height);

        label->SetTextHeight(height)
            .SetPosition(position)
            .SetColor(color)
            .SetRotation(angle, false)
            .SetStyle(paf::PhWidget::Anchor, int(horizontalAlign | verticalAlign));

        label->SetStyle(paf::PhWidget::DrawTextShadow, drawShadow);
        label->SetStyle(paf::PhWidget::TextAlignment, int(horizontalAlign));
        label->SetText(text);
        label->RefreshText();
    }
}

void Renderer::RectangleOverText(paf::vec2 position, paf::vec2 size, paf::vec4 color, Align horizontalAlign, Align verticalAlign, const char* systemTexture, float angle, bool useRadian)
{
    if (!m_CanDraw || color.a <= 0.0)
        return;

    paf::PhPlane* plane = m_PlaneOnTop;

    if (plane)
    {
        //color /= 255;

        ViewportScale(position);
        ViewportScale(size);

        plane->SetPosition(position)
            .SetSize(size)
            .SetColor(color)
            .SetRotation(angle, useRadian)
            .SetStyle(paf::PhWidget::Anchor, int(horizontalAlign | verticalAlign));

        paf::SurfacePtr pTexture = paf::SurfacePtr();
        if (systemTexture)
            pTexture = g_Helpers.m_SystemPlugin->GetTexture(systemTexture);

        plane->SetTexture(pTexture);
    }
}