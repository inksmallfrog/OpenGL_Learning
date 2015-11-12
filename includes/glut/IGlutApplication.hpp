#ifndef _INKSMALLFROG_INTERFACE_GLUTAPPLICATION_
#define _INKSMALLFROG_INTERFACE_GLUTAPPLICATION_

class Callback;

class IGlutApplication{
 public:
  IGlutApplication();
  virtual ~IGlutApplication();
  virtual void Run();

  friend class Callback;
  
 protected:
  virtual bool Init() = 0;
  virtual void Display() = 0;
  virtual void IdleDisplay() = 0;
  virtual void GetMouseMove(int x, int y) = 0;
  virtual void GetMouseButtonState(int button, int state, int x, int y) = 0;
  virtual void GetSpecialKeyState(int key, int x, int y) = 0;
  virtual void GetKeyState(unsigned char key, int x, int y) = 0;

 private:
  virtual void SetCallback();
};

#endif
