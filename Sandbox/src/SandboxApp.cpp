
#include <HGenx.h>
//#include "HGenX/EntryPoint.h"
// 

class ExampleLayer :public HGenx::Layer
{
public:
    ExampleLayer(): Layer{"Example"} {}

    void OnUpdate() override
    {
        HG_INFO("ExampleLayer::Update");
    }

    void OnEvent(HGenx::Event& event) override
    {
        HG_TRACE("{0}", event);
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