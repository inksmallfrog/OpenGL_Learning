#ifndef _INKSMALLFROG_CALLBACK_
#define _INKSMALLFROG_CALLBACK_

class IGlutApplication;

//交互函数接口，用于交互函数的注册
class Callback{
 public:
  static void UseApplication(IGlutApplication *app);    //注册应用程序
  static void DisplayFunc();                            //注册初始显示函数
  static void IdleDisplayFunc();                        //注册显示回调函数
  static void MouseMoveFunc(int x, int y);              //注册鼠标移动函数
  static void MouseButtonStateFunc(int button, int state, int x, int y);    //注册鼠标点击函数
  static void SpecialKeyStateFunc(int key, int x, int y);                   //注册特殊键函数
  static void KeyStateFunc(unsigned char key, int x, int y);                //注册文本键函数

 private:
  static IGlutApplication *app;
};

#endif
