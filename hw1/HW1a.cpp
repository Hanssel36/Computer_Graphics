// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2019 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2019
// ===============================================================

#include "HW1a.h"
#include <iostream>


// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
	
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	// PUT YOUR CODE HERE
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
	// PUT YOUR CODE HERE

	//These two lines initialize width and height of window
	m_winW = w;  
	m_winH = h;

	///////////////////// Everything under here comes from the slides 
	//sets up the aspect ratio of the window 

	// compute aspect ratio
	float ar = (float)w / h;
	// set xmax, ymax
	float xmax, ymax;
	if (ar > 1.0) { // wide screen
		xmax = ar;
		ymax = 1.;
	}
	else { // tall screen
		xmax = 1.;
		ymax = 1 / ar;
	}

	// set the initial viewport to the whole screen
	glViewport(0, 0, w, h);
	// init viewing coordinates for orthographic projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
	// PUT YOUR CODE HERE

	
	//paint gl function draws P's in window

	glClear(GL_COLOR_BUFFER_BIT);
	
	//initializes variables containing the width and height of viewports 
	// in order to have 9 evenly sized viewports
	int w = m_winW/3;
	int h = m_winH/3;


	//for loop sets up smaller viewport and uses the appropriate drawing method each iteration
	for (int i = 0; i < 9; i++) {

		//viewport is set up here
		glViewport((i % 3) * w, (i / 3) * h, w, h);
		//drawing method is accesed via indexing of the array here

		glBegin(DrawModes[i]);
		for (size_t j = 0; j < 31; j++) {
			glVertex2f(Vertices[j], Vertices[j + 1]);
			j++;
		}
		glEnd();
		glFlush();

	}
	

	
	
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}
