#pragma once

#include "HGenX/Layer.h"

namespace HGenx {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnUpdate();
		void OnEvent(Event& event);
	private:


	};




}
