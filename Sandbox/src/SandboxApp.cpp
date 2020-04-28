
#include <HGenx.h>
#include "HGenX/EntryPoint.h"

class Sandbox : public HGenx::Application
{
public:
    Sandbox() {}

    ~Sandbox() {}
};


HGenx::Application* HGenx::CreateApplication()
{
    return new Sandbox();
}