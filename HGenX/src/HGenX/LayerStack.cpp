#include "hgpch.h"

#include "HGenx/LayerStack.h"

namespace HGenx {
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();								// TODO : check if causes an error; in current version not in video
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;								// TODO : check if ++m_LayerInsertIndex; is better
	}
	
	void LayerStack::PushOverLay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin()+m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDetach();								// TODO : check not to cause error; in current version; not in video 
			m_Layers.erase(it);
			m_LayerInsertIndex--;							// TODO : check if --m_LayerInsertIndex; is better
		}
	}

	void LayerStack::PopOverLay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex,m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();							// TODO : check not to cause error; in current version; not in video
			m_Layers.erase(it);
		}
	}

} // end of namespace

