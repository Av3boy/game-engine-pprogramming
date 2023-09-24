/*
* Singleton for handling games
*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <memory>
#include <fstream>
#include <iterator>
#include <string_view>

#include "Timer.h"

#define KEY_ESC		VK_ESCAPE
#define KEY_LEFT	VK_LEFT
#define KEY_RIGHT	VK_RIGHT
#define KEY_UP		VK_UP
#define KEY_DOWN	VK_DOWN
#define KEY_SPACE	VK_SPACE

// Semi-Singleton
class IApplication
{
public:
	IApplication();
	~IApplication();

	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;

	virtual void OnUpdate(float frameTime) = 0;
	virtual void OnDraw() = 0;

	bool Create(int32_t resX, int32_t resY, const std::string& title);

	void Run();
	void Close();

	inline int32_t GetWindowWidth() const { return m_windowWidth; }
	inline int32_t GetWindowHeight() const { return m_windowHeight; }
	inline float GetAspectRatio() const { return (float)m_windowWidth / (float)m_windowHeight; }

	static void GetRandomSeed();
	static bool IsKeyDown(uint32_t keyCode);


	static void Debug(const wchar_t* msg);
	static void Debug(const std::string& msg);
	static void Debug(const char* msg);

	inline HWND GetWindow() { return window; }

	inline bool IsActive() const { return m_bActive; }
	void SetActive(bool isActive);

	static IApplication* GetApp() { return m_pApp; }

protected:
	virtual bool OnEvent(UINT message, WPARAM wParam, LPARAM lParam);

	virtual bool OnKeyDown(uint32_t keyCode) { return false; }

private:
	static long WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	static HWND MakeWindow(int32_t width, int32_t height, const std::string& title);

	static IApplication* m_pApp;
	HWND		window;

	Timer		m_Timer;

	int32_t		m_windowWidth;
	int32_t		m_windowHeight;

	bool		m_bActive;
};