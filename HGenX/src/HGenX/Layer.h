#pragma once

#include "HGenX/Core.h"
#include "HGenX/Events/Event.h"

namespace HGenx {

	class HGenX_API Layer
	{
	public:
		Layer(std::string name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const& { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
