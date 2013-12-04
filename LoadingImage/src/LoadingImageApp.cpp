#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LoadingImageApp : public AppNative {
public:
    void setup();
    void update();
    void draw();
    
    gl::Texture imageTexture;
};

void LoadingImageApp::setup()
{
    string url = "https://dl.dropboxusercontent.com/s/fq8y69br9w7bl9b/IMG_2759.jpeg";
    
    try {
        //imageTexture = gl::Texture( loadImage( loadUrl( Url( url ) ) ) );
        
        // load from asset
        imageTexture = gl::Texture( loadImage( loadAsset("IMG_2759.jpeg") ) );
    } catch ( Exception e ) {
        cout << e.what() << endl;
    }
    
    // ウィンドウを画像サイズにする
    setWindowSize( imageTexture.getSize() );
}

void LoadingImageApp::update()
{
}

void LoadingImageApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    if( imageTexture ) {
        gl::draw( imageTexture, getWindowBounds() );
    }
}

CINDER_APP_NATIVE( LoadingImageApp, RendererGl )
