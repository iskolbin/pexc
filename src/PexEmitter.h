#ifndef PEX_EMITTER_H_
#define PEX_EMITTER_H_

typedef enum {
	PEX_PARTICLE_TIME_TO_LIVE = 0;
	PEX_PARTICLE_START_POS_X = 1;
	PEX_PARTICLE_START_POS_Y = 2;
	PEX_PARTICLE_RED = 3;
	PEX_PARTICLE_GREEN = 4;
	PEX_PARTICLE_BLUE = 5;
	PEX_PARTICLE_ALPHA = 6;
	PEX_PARTICLE_RED_DELTA = 7;
	PEX_PARTICLE_GREEN_DELTA = 8;
	PEX_PARTICLE_BLUE_DELTA = 9;
	PEX_PARTICLE_ALPHA_DELTA = 10;
	PEX_PARTICLE_SIZE = 11;
	PEX_PARTICLE_SIZE_DELTA = 12;
	PEX_PARTICLE_ROTATION = 13;	
	PEX_PARTICLE_ROTATION_DELTA = 14
                          
	PEX_PARTICLE_POSITION_X = 15;
	PEX_PARTICLE_POSITION_Y = 16;
	PEX_PARTICLE_DIRECTION_X = 17;
	PEX_PARTICLE_DIRECTION_Y = 18;
	PEX_PARTICLE_RADIAL_ACCELERATION = 19;
	PEX_PARTICLE_TANGENTIAL_ACCELERATION = 20;

	PEX_PARTICLE_ANGLE = 15;
	PEX_PARTICLE_ANGLE_DELTA = 16;
	PEX_PARTICLE_RADIUS = 17;
	PEX_PARTICLE_RADIUS_DELTA = 18;

} Pex_ParticleAttribute;

#define PEX_PARTICLE_PARAMETERS (21)

typedef float Pex_AttributeType;

typedef enum {
	PEX_GRAVITY_EMITTER = 0;
	PEX_RADIAL_EMITTER;
} Pex_EmitterType;

typedef enum {
	PEX_EMITTER_ACTIVE = 1 << 0;
	PEX_EMITTER_RESTART = 1 << 1;
	PEX_EMITTER_ALPHA = 1 << 2;
	PEX_EMITTER_TINT = 1 << 3;
	PEX_EMITTER_SCALE = 1 << 4;
	PEX_EMITTER_ROTATE = 1 << 5;
	PEX_EMITTER_Y_FLIPPED = 1 << 6;
} Pex_EmitterFlag;

typedef enum {
	PEX_BLEND_ZERO = 0;
	PEX_BLEND_ONE = 1;
	PEX_BLEND_SRC = 2;
	PEX_BLEND_ONE_MINUS_SRC = 3;
	PEX_BLEND_SRC_ALPHA = 4;
	PEX_BLEND_ONE_MINUS_SRC_ALHPA = 5;
	PEX_BLEND_DST_ALPHA = 6;
	PEX_BLEND_ONE_MINUS_DST_ALPHA = 7;
	PEX_BLEND_DST_COLOR = 8;
	PEX_BLEND_ONE_MINUS_DST_COLOR = 9;
} Pex_BlendFunction;

typedef struct {
	Pex_EmitterType type;
	Pex_AttributeType *particles;
	int maxParticles;
	int particleCount;
	double duration = 0.0;
	double elapsedTime = 0.0;
	double emitCounter = 0.0;

	char *texture;
	int flags;	

	Pex_BlendFunction blendFuncSource;
	Pex_BlendFunction blendFuncDestination;

	Pex_AttributeType angle;
	Pex_AttributeType angleVariance;
	
	Pex_AttributeType particleLifespan;
	Pex_AttributeType particleLifespanVariance;
	Pex_AttributeType startParticleSize;
	Pex_AttributeType startParticleSizeVariance;
	Pex_AttributeType finishParticleSize;
	Pex_AttributeType finishParticleSizeVariance;
	Pex_AttributeType rotationStart;
	Pex_AttributeType rotationStartVariance;
	Pex_AttributeType rotationEnd;
	Pex_AttributeType rotationEndVariance;

	Pex_AttributeType maxRadius;
	Pex_AttributeType maxRadiusVariance;
	Pex_AttributeType minRadius;
	Pex_AttributeType minRadiusVariance;
	Pex_AttributeType rotatePerSecond;
	Pex_AttributeType rotatePerSecondVariance;

	Pex_AttributeType startColorRed;
	Pex_AttributeType startColorRedVariance;
	Pex_AttributeType finishColorRed;
	Pex_AttributeType finishColorRedVariance;
	Pex_AttributeType startColorGreen;
	Pex_AttributeType startColorGreenVariance;
	Pex_AttributeType finishColorGreen;
	Pex_AttributeType finishColorGreenVariance;
	Pex_AttributeType startColorBlue;
	Pex_AttributeType startColorBlueVariance;
	Pex_AttributeType finishColorBlue;
	Pex_AttributeType finishColorBlueVariance;
	Pex_AttributeType startColorAlpha;
	Pex_AttributeType startColorAlphaVariance;
	Pex_AttributeType finishColorAlpha;
	Pex_AttributeType finishColorAlphaVariance;

	Pex_AttributeType sourcePositionX;
	Pex_AttributeType sourcePositionXVariance;
	Pex_AttributeType sourcePositionY;
	Pex_AttributeType sourcePositionYVariance;
	Pex_AttributeType radialAcceleration;
	Pex_AttributeType radialAccelerationVariance;
	Pex_AttributeType tangentialAcceleration;
	Pex_AttributeType tangentialAccelerationVariance;
	Pex_AttributeType gravityX;
	Pex_AttributeType gravityY;
	Pex_AttributeType speed;
	Pex_AttributeType speedVariance;
} Pex_Emitter;

#define Pex_ParticleGetIndex(e,i)       ((i)*PARTICLE_PARAMETERS)
#define Pex_ParticleNextIndex(e,si)     ((si)+PARTICLE_PARAMETERS)
#define Pex_ParticleGetTimeToLive(e,si) ((e)->particles[(si)+PEX_PARTICLE_TIME_TO_LIVE])
#define Pex_ParticleGetX(e,si)          ((e)->particles[(si)+PEX_PARTICLE_POSITION_X])
#define Pex_ParticleGetY(e,si)          ((e)->particles[(si)+PEX_PARTICLE_POSITION_Y])
#define Pex_ParticleGetRed(e,si)        ((e)->particles[(si)+PEX_PARTICLE_RED])
#define Pex_ParticleGetGreen(e,si)      ((e)->particles[(si)+PEX_PARTICLE_GREEN])
#define Pex_ParticleGetBlue(e,si)       ((e)->particles[(si)+PEX_PARTICLE_BLUE])
#define Pex_ParticleGetAlpha(e,si)      ((e)->particles[(si)+PEX_PARTICLE_ALPHA])
#define Pex_ParticleGetRotation(e,si)   ((e)->particles[(si)+PEX_PARTICLE_ROTATION])
#define Pex_ParticleGetSize(e,si)       ((e)->particles[(si)+PEX_PARTICLE_SIZE])

#define Pex_ParticleGetARGB(e,si) \
	(((int)(Pex_ParticleGetAlpha((e),(si))*0xff))<<0x18) + \
	(((int)(Pex_ParticleGetRed  ((e),(si))*0xff))<<0x10) + \
	(((int)(Pex_ParticleGetGreen((e),(si))*0xff))<<0x08) + \
	 ((int)(Pex_ParticleGetBlue ((e),(si))*0xff))


#define Pex_EmitterIsActive(e)      ((e)->flags&PEX_EMITTER_ACTIVE)
#define Pex_EmitterIsRestart(e)     ((e)->flags&PEX_EMITTER_RESTART)
#define Pex_EmitterIsUsingTint(e)   ((e)->flags&PEX_EMITTER_TINT)
#define Pex_EmitterIsUsingAlpha(e)  ((e)->flags&PEX_EMITTER_ALPHA)
#define Pex_EmitterIsUsingScale(e)  ((e)->flags&PEX_EMITTER_SCALE)
#define Pex_EmitterIsUsingRotate(e) ((e)->flags&PEX_EMITTER_ROTATE)
#define Pex_EmitterIsYFlipped(e)    ((e)->flags&PEX_EMITTER_Y_FLIPPED)

Pex_Emitter *Pex_CreateEmitter(void);
void Pex_DestroyEmitter( Pex_Emitter *self );
void Pex_EmitterInitFromXml( Pex_Emitter *self, const char *xml );
void Pex_EmitterStart( Pex_Emitter *self, double duration );
void Pex_EmitterStop( Pex_Emitter *self );
void Pex_EmitterReset( Pex_Emitter *self );
void Pex_EmitterUpdate( Pex_Emitter *self, double dt );

#endif
