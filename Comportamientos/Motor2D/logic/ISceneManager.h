#ifndef __ISCENE_MANAGER__
#define __ISCENE_MANAGER__


enum TError;


class ISceneManager
{
public:
    static ISceneManager& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void Update( double elapsedTime ) = 0;
    virtual void Render()					  = 0;
    
    virtual void NextScene    () = 0;
    virtual void PreviousScene() = 0;
    virtual void SetScene     ( unsigned int index ) = 0;
};


#endif
