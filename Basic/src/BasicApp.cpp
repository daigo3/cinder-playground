#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicApp : public AppNative {
public:
    void setup();
    void mouseDown( MouseEvent event );	
    void update();
    void draw();
};

void BasicApp::setup()
{
}

void BasicApp::mouseDown( MouseEvent event )
{
}

void BasicApp::update()
{
}

void BasicApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    // draw a X over the window
    gl::drawLine( Vec2f( 0.0f, 0.0f ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawLine( Vec2f( 0.0f, getWindowHeight() ), Vec2f( getWindowWidth(), 0.0f ) );
}

CINDER_APP_NATIVE( BasicApp, RendererGl )
