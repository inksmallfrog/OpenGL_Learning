#include "../../includes/glut/Callback.hpp"
#include "../../includes/glut/IGlutApplication.hpp"

#ifndef NULL
#define NULL 0
#endif

IGlutApplication* Callback::app = NULL;

void Callback::UseApplication(IGlutApplication *app){
  Callback::app = app;
}

void Callback::DisplayFunc(){
  app->Display();
}

void Callback::IdleDisplayFunc(){
  app->IdleDisplay();
}

void Callback::MouseMoveFunc(int x, int y){
  app->GetMouseMove(x, y);
}

void Callback::MouseButtonStateFunc(int button, int state, int x, int y){
  app->GetMouseButtonState(button, state, x, y);
}

void Callback::SpecialKeyStateFunc(int key, int x, int y){
  app->GetSpecialKeyState(key, x, y);
}

void Callback::KeyStateFunc(unsigned char key, int x, int y){
  app->GetKeyState(key, x, y);
}
