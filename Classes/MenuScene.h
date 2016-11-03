#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();

  void start(cocos2d::Ref* pSender);
  void options(cocos2d::Ref* pSender);
  void help(cocos2d::Ref* pSender);
}
