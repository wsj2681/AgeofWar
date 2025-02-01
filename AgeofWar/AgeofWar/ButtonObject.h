#pragma once
#include "Object.h"
class ButtonObject : public Object
{
public:
    ButtonObject() = delete;
    ButtonObject(Color color, Vector2f location);
    
    ButtonObject(const ButtonObject&) = delete;
    ButtonObject& operator=(const ButtonObject&) = delete;
    ButtonObject(ButtonObject&&) = delete;
    ButtonObject& operator=(const ButtonObject&&) = delete;

    virtual ~ButtonObject();

    // ButtonObject 초기화 함수, Color 값 및 위치(Vector2f) 값 받음
    virtual void Init(Color color, Vector2f location);

    // ButtonObject 제거
    virtual void Destroy();

    // Button Click Event
    virtual bool isClicked(Vector2f mousePoint);


protected:
    
private: 
    // Object의 Global Bounds 변수
    FloatRect GB;
};

