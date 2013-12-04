#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Rand.h"

#include "cinder/Easing.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define CIRCLE_COUNT 50
#define TWEEN_SPEED 1.0

class BasicAnimationApp : public AppNative {
public:
    void setup();
    void update();
    void draw();
    void prepareSettings( Settings* settings);
    
    Vec2f startPosition[CIRCLE_COUNT];
    Vec2f currentPosition[CIRCLE_COUNT];
    Vec2f targetPosoition[CIRCLE_COUNT];
    
    float circleRadius[CIRCLE_COUNT];
    
    float circleTimeBase[CIRCLE_COUNT];
};

void BasicAnimationApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60 );
}

void BasicAnimationApp::setup()
{
    for( int i = 0; i < CIRCLE_COUNT; i++ ) {
        startPosition[i] = Vec2f( Rand::randFloat( 0, getWindowWidth() ), Rand::randFloat( 0, getWindowHeight() ) );
        currentPosition[i] = Vec2f( Rand::randFloat( 0, getWindowWidth() ), Rand::randFloat( 0, getWindowHeight() ) );
        targetPosoition[i] = Vec2f( Rand::randFloat( 0, getWindowWidth() ), Rand::randFloat( 0, getWindowHeight() ) );
        
        circleRadius[i] = Rand::randFloat( 1, 10 );
        circleTimeBase[i] = 0;
    }
    
}

void BasicAnimationApp::update()
{
    Vec2f diff;
    
    for( int i = 0; i < CIRCLE_COUNT; i++ ) {
        diff = targetPosoition[i] - startPosition[i];
        currentPosition[i] = easeOutExpo( ( getElapsedSeconds() - circleTimeBase[i] * TWEEN_SPEED ) ) *
            diff + startPosition[i];
        
        if( currentPosition[i].distance( targetPosoition[i] ) < 1.0f ) {
            targetPosoition[i].x = Rand::randFloat( 0, getWindowWidth() );
            targetPosoition[i].y = Rand::randFloat( 0, getWindowHeight() );
            startPosition[i] = currentPosition[i];
            circleTimeBase[i] = getElapsedSeconds();
        }
    }
}

void BasicAnimationApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    for( int i = 0; i < CIRCLE_COUNT; i++ ) {
        gl::drawSolidCircle( currentPosition[i], circleRadius[i] );
    }
}

CINDER_APP_NATIVE( BasicAnimationApp, RendererGl )
