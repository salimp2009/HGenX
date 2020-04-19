#pragma once

#ifdef HG_PLATFORM_WINDOWS
extern HGenx::Application* HGenx::CreateApplication();

int main(int argc, char** argv)
{
    auto app = HGenx::CreateApplication();
    app->Run();
    delete app;
}

#endif // HG_PLATFORM_WINDOWS
