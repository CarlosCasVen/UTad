#include <stdio.h>


class BaseEntity
{
public:
	BaseEntity();
	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	float x, y, z;
};