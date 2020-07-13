
#include <HGenx.h>
//#include "HGenX/Application.h"
#include <imgui/imgui.h>


class ExampleLayer :public HGenx::Layer
{
public:
    ExampleLayer(): Layer{"Example"} 
    {
    }

    virtual void OnUpdate() override
    {
       // HG_INFO("ExampleLayer::Update");

        if (HGenx::Input::IsKeyPressed(HG_KEY_TAB))
        {
            HG_TRACE("Tab Key is Pressed!");
        }
            
    }

    virtual void OnImGuiRender() override
    {
        // HomeWork Question : How to get rid of the linking error if below is included; compiles ok but cannot link
        // Solution FOR DDL; Add IMGUI_API=__declspec(dllexport); in Hazel Preprocessor definition also in ImGui 
        // Also add to SandBox to import IMGUI_API=__declspec(dllimport); Doing this enables Hazel to get 
        // this loaded from ImGui since Hazel is a DLL library and Sandbox will get it thru Hazel
        // Not NEEDED FOR STATIC LIBRARY Version of Hazel
        ImGui::Begin("Test");
        ImGui::Text("Hello HGenx World of Wonders");
        ImGui::End();
    }

    virtual void OnEvent(HGenx::Event& event) override
    {
        if (event.GetEventType() == HGenx::EventType::KeyPressed)
        {
            HGenx::KeyPressedEvent& e = (HGenx::KeyPressedEvent&)event;
            HG_TRACE("Keypressed is {0}", (char)e.GetKeyCode());
        }
   
        //HG_TRACE("{0}", event);
    }

};

class Sandbox : public HGenx::Application
{
public:
    Sandbox() 
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}
};


HGenx::Application* HGenx::CreateApplication()
{
    return new Sandbox();
}