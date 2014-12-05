/*
  Mollier.cpp - Library for absolute humidity sensing.
  Created by Golfredo Mendoza(golfredom) and Abraham Pineda(techboycr), 
  December 3, 2014.

  Golfredo was the one who create all the Mollier calculation magic, and Abraham just put it together in this library. 

  Released into the public domain.
*/
#include "Arduino.h"
#include "Mollier.h"

Mollier::Mollier(float t, float tw, float p)
{
	_t = t;
	_tw = tw;
	_p = p;

   //Chequeo en caso de error, temperatura bulbo humedo no puede ser mayor a bulbo seco
 #if (_tw > _t)
   _tw = _t;
 #endif

}


 double Mollier::PVA()
{
	//presion de vapor absoluta
  _pva = (6.112 * (exp((17.67 * _tw) / (_tw + 243.5))) - _p * (_t - _tw) * 0.00066 * (1 + (0.00115 * _tw)));
  return _pva;
}

 double Mollier::PVS()
{
	//presion de vapor saturada
  _pvs = (6.112 * exp((17.67 * _t) / (_t + 243.5)));

  return _pvs;
}
  
 double Mollier::DVT()
{
  //densidad de vapor total
  _dvt = ((0.00036 * (_t * _t * _t)) + 0.00543 * (sq(_t)) + 0.37067 * _t + 4.81865);

  return _dvt;
}

 float Mollier::HR()
{
  //humedad relativa
  _hr = PVA() * 100 / PVS();

  return _hr;
}
 
 float Mollier::HA()
{
  //humedad absoluta
  _ha = HR() * DVT() / 100;

  return _ha;
}

 double Mollier::DEW()
{
  //punto de rocio
  PVA();

  _dew = (243.5 * log(_pva / 6.112)) / (17.67 - log(_pva / 6.112));

  return _dew;
}

 double Mollier::DVA()
{
  //densidad de vapor absoluta
  _dva = HR() * DVT() / 100;

  return _dva;
}

 double Mollier::HE()
{
  //humedad especifica
  PVA();

  _he = (621.9907 * (_pva * 100)) / ((_p * 100) - (_pva * 100));

  return _he;
}
