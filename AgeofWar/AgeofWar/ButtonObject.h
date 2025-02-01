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

    // ButtonObject �ʱ�ȭ �Լ�, Color �� �� ��ġ(Vector2f) �� ����
    virtual void Init(Color color, Vector2f location);

    // ButtonObject ����
    virtual void Destroy();

    // Button Click Event
    virtual bool isClicked(Vector2f mousePoint);


protected:
    
private: 
    // Object�� Global Bounds ����
    FloatRect GB;
};

