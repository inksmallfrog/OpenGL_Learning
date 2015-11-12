#include <GL/glew.h>
#include "../../includes/glut/IGlutApplication.hpp"
#include "../../includes/glut/Callback.hpp"
#include <GL/glut.h>
#include <iostream>

IGlutApplication::IGlutApplication(){}
IGlutApplication::~IGlutApplication(){}

void IGlutApplication::Run(){  
  if(!Init()){
    std::cout << "Can't init glut application!" << std::endl;
    exit(0);
  }

  SetCallback();
  
  glutMainLoop();
}

void IGlutApplication::SetCallback(){
  Callback::UseApplication(this);
  glutDisplayFunc(Callback::DisplayFunc);
  glutIdleFunc(Callback::IdleDisplayFunc);
  glutPassiveMotionFunc(Callback::MouseMoveFunc);
  glutMouseFunc(Callback::MouseButtonStateFunc);
  glutSpecialFunc(Callback::SpecialKeyStateFunc);
  glutKeyboardFunc(Callback::KeyStateFunc);  
}
