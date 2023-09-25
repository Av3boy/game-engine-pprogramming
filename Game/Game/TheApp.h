#pragma once
#include "../../Core/include/IApplication.h"

class TheApp : public IApplication
{
public:
	// Inherited via IApplication
	bool OnCreate() override;
	void OnDestroy() override;
	void OnUpdate(float frameTime) override;
	void OnDraw() override;


	bool OnKeyDown(uint32_t keyCode);
};