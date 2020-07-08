
#include <HGenx.h>

class ExampleLayer :public HGenx::Layer
{
public:
    ExampleLayer(): Layer{"Example"} 
    {
    }

    void OnUpdate() override
    {
       // HG_INFO("ExampleLayer::Update");

        if (HGenx::Input::IsKeyPressed(HG_KEY_TAB))
        {
            HG_TRACE("Tab Key is Pressed!");
        }
            
    }

    void OnEvent(HGenx::Event& event) override
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