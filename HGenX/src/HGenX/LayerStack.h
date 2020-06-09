#pragma once

#include "HGenX/Core.h"
#include "HGenX/Layer.h"

#include <vector>


namespace HGenx {

	class HGenX_API LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverLay(Layer* overlay);

		std::vector<Layer*>::iterator begin()	{ return m_Layers.begin(); }
		std::vector<Layer*>::iterator end()		{ return m_Layers.end(); }
		std::vector<Layer*>::reverse_iterator rbegin()	{ return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend()	{ return m_Layers.rend(); }

		std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
		std::vector<Layer*>::const_iterator end()   const { return m_Layers.end(); }
		std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }
		std::vector<Layer*>::const_reverse_iterator rend() const { return m_Layers.rend(); }

	private:
		std::vector<Layer*> m_Layers;
		//std::vector<Layer*>::iterator m_LayerInsert;	// TODO : DELETE; replaced by m_LayerInsertIndex in current version
		unsigned int m_LayerInsertIndex{0};				// TODO : to be included instead of m_LayerInsert in current version
	};

}