#ifndef __H_AUDIOLISTENER__
#define __H_AUDIOLISTENER__

class Listener 
{ 
public: 
    static Listener& Instance(); 
    
    void SetPosition(float x, float y, float z); 
    void SetVelocity(float x, float y, float z); 
    void SetOrientation(float x, float y, float z); 

protected:
    Listener(); 
    ~Listener(){ delete listener; }

private: 
    static Listener* listener;
};


#endif