#pragma once

#include <string>

namespace HGenx {
	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void UnBind() const;
	private:
		uint32_t m_RendererID;
	};



}
