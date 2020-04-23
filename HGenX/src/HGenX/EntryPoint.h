#pragma once

#ifdef HG_PLATFORM_WINDOWS
extern HGenx::Application* HGenx::CreateApplication();

int main(int argc, char** argv)
{
    HGenx::Log::Init();
    HG_CORE_WARN("Initialized Log!");
    int a{ 5 };
    HG_INFO("HELLO! Var={0}",a);
    //HGenx::Log::GetCoreLogger()->warn("Initialized Log!");
    //HGenx::Log::GetClientLogger()->info("Hello Log!");
    
    auto app = HGenx::CreateApplication();
    app->Run();
    delete app;
}

#endif // HG_PLATFORM_WINDOWS
