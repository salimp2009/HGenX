#pragma once

#include "HGenX/Layer.h"

namespace HGenx {

	class HGenX_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time{ 0.0f };
	};




}
