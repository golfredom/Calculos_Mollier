/*
  calculos_mollier.h - Library for absolute humidity sensing.
  Created by Golfredo Mendoza(golfredom) and Abraham Pineda(techboycr), 
  December 3, 2014.

  Golfredo was the one who create all the Mollier calculation magic, and Abraham just put it together in this library. 

  Released into the public domain.
*/
#ifndef Mollier_h
#define Mollier_h

#include "Arduino.h"

class Mollier
{
	public:
		Mollier(float t, float tw, float p);
		double PVA();
		double PVS();
		double DVT();
		float HR();
		float HA();
		double DEW();
		double DVA();
		double HE();

		double _pva;
		double _pvs;
		double _dvt;
		float _hr;
		float _ha;
		double _dew;
		double _dva;
		double _he;
	private:
		float _t;
		float _tw;
		float _p;
};

#endif
