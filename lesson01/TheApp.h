/**
 * ============================================================================
 *  Name        : TheApp.h
 *  Part of     : Simple OpenGL graphics engine framework
 *  Description : the concrete application layer
 *  Version     : 1.00
 *	Author		: Jani Immonen, <realdashdev@gmail.com>
 * ============================================================================
**/

#pragma once

#include "../core/include/IApplication.h"
#include "../core/include/OpenGLRenderer.h"


class TheApp : public IApplication
{
public:
	TheApp();

	/**
	 * OnCreate
	 * app initializer, called by abstraction layer when engine initialization is complete
	 * @return true if successful, false otherwise.
	 */
	bool OnCreate() override;

	/**
	 * OnDestroy
	 * app destroyer, called by the abstraction layer when app is about to get destoyed
	 */
	void OnDestroy() override;

	/**
	 * OnUpdate
	 * app update loop
	 * @param frametime time since previous update, in seconds
	 */
	void OnUpdate(float frametime) override;

	/**
	 * OnDraw
	 * app drawing method
	 * @param pRenderer pointer to renderer object
	 */
	void OnDraw(IRenderer& renderer) override;

protected:
	/**
	 * OnMouseBegin
	 * event when mouse button is pressed down
	 * @param iButtonIndex index of the mouse button (0 based)
	 * @param vPoint event coordinate in pixels
	 * @return true if event was handled by the receiver
	 */
	bool OnMouseBegin(int32_t buttonIndex, const glm::vec2& point) override;

	/**
	 * OnMouseDrag
	 * event when mouse is dragged
	 * @param iButtonIndex index of the mouse button (0 based)
	 * @param vPoint event coordinate in pixels
	 * @return true if event was handled by the receiver
	 */
	bool OnMouseDrag(int32_t buttonIndex, const glm::vec2& point) override;

	/**
	 * OnMouseEnd
	 * event when mouse button is lifted up
	 * @param iButtonIndex index of the mouse button (0 based)
	 * @param vPoint event coordinate in pixels
	 * @return true if event was handled by the receiver
	 */
	bool OnMouseEnd(int32_t buttonIndex, const glm::vec2& point) override;

	/**
	 * OnKeyDown
	 * key down event
	 * @param keyCode key code
	 * @return true if event was handled by the receiver
	 */
	bool OnKeyDown(uint32_t keyCode) override;

private:
	/**
	 * GetOpenGLRenderer
	 * helper method to access the openGL renderer layer
	 * @return pointer to OpenGL renderer
	 */
	OpenGLRenderer* GetOpenGLRenderer() { return static_cast<OpenGLRenderer*>(GetRenderer()); }

private:
	// app data
};

