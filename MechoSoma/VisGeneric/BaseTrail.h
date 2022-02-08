#ifndef __BASETRAIL_H__
#define __BASETRAIL_H__

#include "BaseObject.h"
#include "Material.h"
#include "Timers.h"

class cTileMap;

class cBaseTrail : public cBaseObject, public cBaseDrawObject
{
public:
	Vect3f			Point[4];			// 4-точки текстуры 
	Vect3f			Pos;				// место положение центра
	sColor4f		Diffuse1;			// освещенность объекта в начале
	sColor4f		Diffuse2;			// освещенность объекта в конце
	MeasurementTimer Timer;
	float			   Duration;		   
//	float			CurrentTime;		// текущее время, CurrentTime+StartTime==GlobalTime
//	float			StartTime;			// время начала жизни 
//	float			FinishTime;			// время жизни 
	float			AnimTime;			// время анимации

	cBaseTrail(unsigned int type,unsigned int kind) : cBaseObject(type,kind)			{ /*StartTime=0;*/ }
};

class cTangentTrail : public cBaseTrail
{
public:
	cTileMap		*tMap;

	cTangentTrail(	unsigned int type=BASEOBJECT_TYPE_BASETRAIL_TANGENT,
					unsigned int kind=BASEOBJECT_KIND_DRAW_EFFECT) : cBaseTrail(type,kind)	{ BaseDrawObject()->SetAttribute(BASEOBJECT_ATTRIBUTE_DRAW_CYCL); tMap=0; }
	inline void Set(const Vect3f &pos,const Vect3f &dpos,float width)
	{
		Vect3f tangent(dpos.y,-dpos.x,0);
		tangent.normalize();
		tangent*=width;
		Pos.set(Cycl(pos.x,XSIZE_CYCL_FLT),Cycl(pos.y,XSIZE_CYCL_FLT),pos.z);
		Point[0]=tangent;
		Point[1]=dpos+tangent;
		Point[2]=dpos-tangent;
		Point[3]=-tangent;
	}
};

enum TrailType {
	OrdinaryTrail,
	RedSlimeTrail,
	GreenSlimeTrail,
	YellowSlimeTrail,
	BlueSlimeTrail,
	RedTrackTrail,
	TrailTypeMax
};

#endif // __BASETRAIL_H__
