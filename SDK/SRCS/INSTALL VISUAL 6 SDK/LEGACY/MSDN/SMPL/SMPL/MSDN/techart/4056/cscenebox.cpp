#include "stdafx.h"
#include <gl\gl.h>
#include <gl\glu.h>
#include "GLlib.h"
#include "CSceneBox.h"

#include "shapes.h"

//
// OnResize - Set up projection from 3-D to 2-D. 
//
BOOL CSceneBox::OnResize(int cx, int cy)
{
   GLdouble gldAspect = (GLdouble) cx/ (GLdouble) cy;
   OutputGlError("Clear") ;
   glMatrixMode(GL_PROJECTION); OutputGlError("MatrixMode") ;
   glLoadIdentity();
   gluPerspective(30.0, gldAspect, 1.0, 10.0);
   glViewport(0, 0, cx, cy);

	return TRUE ;
}

//
// OnInit - Initialize OpenGL.
//
BOOL CSceneBox::OnInit()
{
	// Faster than using glScale.
	GLdouble size = 0.5 ;

	// Enable depth calculations
   glEnable(GL_DEPTH_TEST);  		OutputGlError("glEnable (GL_DEPTH_TEST);") ;

	// Set the material color to follow the current color
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE) ;
	glEnable(GL_COLOR_MATERIAL) ;

	// Enable lighting calculations
	glEnable(GL_LIGHTING) ; 		OutputGlError("glEnable (GL_LIGHTING) ;") ;
	glEnable(GL_LIGHT0) ;			OutputGlError("glEnable (GL_LIGHT0) ;") ;
	
	// Set the color to clear the screen
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f) ;

	//
	// Build display list for Box. See shapes.cpp for BoxList function.
	//
	BoxList(1, size) ;

	return TRUE ;
}

//
// OnRender - Render the image.
//
BOOL CSceneBox::OnRender()
{
   // Set up some colors
   static GLdouble red[3] = {0.8, 0.0, 0.0 } ; 
   static GLdouble green[3] = {0.0, 0.75, 0.0} ;
   static GLdouble purple[3] = {1.0, 0.14, 0.6667} ; 

   // Clear the color and depth buffers
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);

   //
   // Draw the box.
   //		
   // Translate and rotate the axis.
   glLoadIdentity();
   glTranslated(0.0, 0.0, -4.5 ); 
   glRotated(30/*m_angle[Box].cx*/, 1.0, 0.0, 0.0);
   glRotated(70/*m_angle[Box].cy*/, 0.0, 1.0, 0.0);

   // Change the current color to green.
   glColor3dv(green) ;

   // Draw the box.
   glCallList(1) ;

   //
   // Flush the drawing pipeline.
   //
   glFlush();	

  	return TRUE ;
}
