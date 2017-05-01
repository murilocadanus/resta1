#include "AppDelegate.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

typedef struct tagResource
{
	cocos2d::Size size;
	std::string directory;
}Resource;

static Resource smallResource       = { cocos2d::Size(640, 1136), "small" };
static Resource mediumResource      = { cocos2d::Size(750, 1334), "medium" };
static Resource mediumLargeResource	= { cocos2d::Size(1242, 2208), "medium-large" };
static Resource largeResource       = { cocos2d::Size(1536, 2048), "large" };
static Resource largeLargeResource  = { cocos2d::Size(2048, 2732), "large-large" };

static cocos2d::Size designResolutionSize = smallResource.size;
											//mediumResource.size;
											//largeResource.size;
AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("Resta1", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Resta1");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Get screen size
    auto frameSize = glview->getFrameSize();

	// Set paths to search for resources
	std::vector<std::string> searchPaths;
	
	// Set the design resolution
	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::EXACT_FIT);

    // if the frame's height is larger than the height of large size.
    if (frameSize.height > largeResource.size.height)
    {
        // Set content scale
        director->setContentScaleFactor(MIN(largeLargeResource.size.height/designResolutionSize.height, largeLargeResource.size.width/designResolutionSize.width));
        
        // Set resource assets
        searchPaths.push_back(largeLargeResource.directory);
    }
    // if the frame's height is larger than the height of medium large size.
    else if (frameSize.height > mediumLargeResource.size.height)
    {
		// Set content scale
        director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));

		// Set resource assets 
		searchPaths.push_back(largeResource.directory);
    }
    // if the frame's height is larger than the height of medium size.
    else if (frameSize.height > mediumResource.size.height)
    {
        // Set content scale
        director->setContentScaleFactor(MIN(mediumLargeResource.size.height/designResolutionSize.height, mediumLargeResource.size.width/designResolutionSize.width));
        
        // Set resource assets
        searchPaths.push_back(mediumLargeResource.directory);
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResource.size.height)
    {
		// Set content scale
        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));

		// Set resource assets
		searchPaths.push_back(mediumResource.directory);
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {
		// Set content scale
        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));

		// Set resource assets
		searchPaths.push_back(smallResource.directory);
    }

	auto fileUtils = FileUtils::getInstance();
	fileUtils->setSearchPaths(searchPaths);

    register_all_packages();

	// Load backgrond music
	auto audioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
	audioEngine->preloadBackgroundMusic(fileUtils->fullPathForFilename("background.wav").c_str());
	audioEngine->preloadEffect(fileUtils->fullPathForFilename("tick.aiff").c_str());

	// Lower playback volume for effects
	audioEngine->setBackgroundMusicVolume(0.5);
	audioEngine->setEffectsVolume(1.0);

    // create a scene. it's an autorelease object
	auto scene = MenuScene::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
