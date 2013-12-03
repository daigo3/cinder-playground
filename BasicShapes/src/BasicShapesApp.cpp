#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicShapesApp : public AppNative {
public:
    void setup();
    void mouseDown( MouseEvent event );	
    void update();
    void draw();
};

void BasicShapesApp::setup()
{
}

void BasicShapesApp::mouseDown( MouseEvent event )
{
}

void BasicShapesApp::update()
{
}

void BasicShapesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    // Draw Lines
    glLineWidth( 2.0f );
    
    gl::color( Color( 0, 1, 1 ) );
    gl::drawLine( Vec2f( 0, 0 ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    
    gl::color( Color( 1, 0, 0 ) );
    gl::drawLine( Vec2f( 0, getWindowHeight() ), Vec2f( getWindowWidth(), 0 ) );
    
    // Draw Circles
    gl::drawSolidCircle( getWindowCenter(), 20.0f );
    gl::drawStrokedCircle( getWindowCenter(), 40.0f );
    
    // Draw Rectangles
    gl::drawStrokedRect( Rectf(getWindowWidth()/2 - 20.0f,
                             getWindowHeight()/2 - 20.0f,
                             getWindowWidth()/2 + 20.0f,
                             getWindowHeight()/2 + 20.0f ));
}

CINDER_APP_NATIVE( BasicShapesApp, RendererGl )
