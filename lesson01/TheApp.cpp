/**
 * ============================================================================
 *  Name        : TheApp.cpp
 *  Part of     : Simple OpenGL graphics engine framework
 *  Description : the concrete application layer
 *  Version     : 1.00
 *	Author		: Jani Immonen, <realdashdev@gmail.com>
 * ============================================================================
**/

#include "TheApp.h"

void TheApp::AddBallToQueue()
{
	int ballType = GetRandomNumber(0, 6);
	m_queue.push(ballType);
}

bool TheApp::OnCreate()
{
	auto renderer = GetOpenGLRenderer();

	auto vertexShader = renderer->CreateVertexShader("shader.vert");
	auto fragmentShader = renderer->CreateFragmentShader("shader.frag");
	m_program = renderer->CreateProgram(vertexShader, fragmentShader);

	// Generate level


	for (size_t i = 0; i < gridWidth; i++)
	{
		for (size_t j = 0; j < gridHeight; j++)
		{
			// TODO: Generate grid cells
			// Bubbles are assigned numbers(empty cell = 0)

		}
	}

	// TODO: Generate starting ball

	// Generate ball queue
	for (size_t i = 0; i < 5; i++)
	{
		AddBallToQueue();
	}

	// return false to quit the app
	return true;
}


void TheApp::OnDestroy()
{
	// app is about to close, clear all resources
}

void TheApp::OnBubbleCollide()
{

	// Bubble hit a cell with a bubble in it->Check for adjency
	// At least tree bubbles need to be next to each other.
	// NOTE: The bubble shot is included in the adjency so actually two more are required.

	int numAdjecent = 0;
	bool shouldRemoveBubbles = numAdjecent > 3;
	if (shouldRemoveBubbles)
	{
		// Remove adjecent bubbles from grid.
		
		// If no more bubbles of the same type exist, remove it from possible types.
		auto position = std::find(m_possibleBallTypes.begin(), m_possibleBallTypes.end(), 8);
		if (position == m_possibleBallTypes.end()) // means the element was not found
			throw std::exception("Ball type not found!");
			
		m_possibleBallTypes.erase(position);
	}

	if (!shouldRemoveBubbles && IsGameLost())
	{
		// TODO: Indicate lose.
	}

	if (IsGameWon())
	{
		// TODO: Indicate win.
	}
}

void OnWallCollide(bool rightWallHit)
{
	float incidenceAngle = 0;
	auto reflectionAngle = rightWallHit ? 90 + incidenceAngle : 90 - incidenceAngle;
}

void TheApp::OnUpdate(float frametime)
{
	
	bool isBubbleMoving = false;
	if (isBubbleMoving)
	{
		// TODO: Check for wall collisions
		// TODO: Check for bubble collisions
	}
}


void TheApp::OnDraw(IRenderer& renderer)
{
	// clear color, depth and stencil buffers
	renderer.Clear(0.2f, 0.2f, 0.2f, 1.0f);

	glUseProgram(m_program);
}


bool TheApp::OnMouseBegin(int32_t buttonIndex, const glm::vec2& point)
{
	// TODO: calculate launch angle
	// Mouse position->Get angle where the bubble is shot

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

