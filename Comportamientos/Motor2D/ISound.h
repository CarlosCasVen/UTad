#ifndef ___ISOUND___
#define ___ISOUND___

class ISound
{
public:
	static const int CONTINUE = -1;

	virtual void play	(int from = CONTINUE) = 0;
	virtual void stop	()										= 0;
	virtual void pause()										= 0;
};

#endif