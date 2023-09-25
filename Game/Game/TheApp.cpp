#include "TheApp.h"

void TheApp::OnDestroy()
{
}


void TheApp::OnUpdate(float frameTime)
{

}

void TheApp::OnDraw()
{

}

bool TheApp::OnCreate()
{
	return true;
}


bool TheApp::OnKeyDown(uint32_t keyCode)
{
	if (keyCode == KEY_ESC)
	{
		Close();
		return true;
	}

	return false;
}