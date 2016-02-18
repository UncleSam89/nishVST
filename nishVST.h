#ifndef __NISHVST__
#define __NISHVST__

#include "IPlug_include_in_plug_hdr.h"

class nishVST : public IPlug
{
public:
  nishVST(IPlugInstanceInfo instanceInfo);
  ~nishVST();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
  double var;
};

#endif
