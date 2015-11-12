#ifndef _INKSMALLFROG_SINGLETON_
#define _INKSMALLFROG_SINGLETON_

#ifndef NULL
#define NULL 0
#endif

template<class T>
class Singleton{
 public:
  static T* GetInstance();

 private:
  static T* sm_instance;
  Singleton();
};

template<class T>
T* Singleton<T>::sm_instance = NULL;

template<class T>
T* Singleton<T>::GetInstance(){
  if(NULL == sm_instance){
    sm_instance = new T;
  }
  return sm_instance;
}

template<class T>
Singleton<T>::Singleton(){
}

#endif
