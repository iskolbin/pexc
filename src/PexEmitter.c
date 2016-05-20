#include <stdlib.h>
#include <math.h>
#include "PexEmitter.h"

static Pex_AttributeType rnd1to1() {
	Pex_AttributeType r = (rand())/(RAND_MAX+1.0);
	return r + r - 1.0;
}

static Pex_AttributeType clamp( Pex_AttributeType v ) {
	return (v < 0.0 ? 0.0 : (v < 1.0 ? v : 1.0 )); 
}

static void initParticle() {
}

static void updateParticle() {
}

Pex_Emitter *Pex_CreateEmitter(void) {
	return NULL;	
}

void Pex_DestroyEmitter( Pex_Emitter *self ) {

}

void Pex_EmitterInitFromXml( Pex_Emitter *self, const char *xml ) {
	
}

void Pex_EmitterStart( Pex_Emitter *self, double duration ) {

}

void Pex_EmitterStop( Pex_Emitter *self ) {
	
}

void Pex_EmitterReset( Pex_Emitter *self ) {
	
}

void Pex_EmitterUpdate( Pex_Emitter *self, double dt ) {

}
