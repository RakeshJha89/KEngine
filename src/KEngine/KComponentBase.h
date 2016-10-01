#pragma once
#include <string>

namespace Karma
{
	class ComponentBase
	{
	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Terminate() = 0;

		virtual std::string GetName() { return "ComponentBase"; }
	};
}
