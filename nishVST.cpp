#include "nishVST.h"
#include "IPlug_include_in_plug_src.h"
#include "IControl.h"
#include "resource.h"

const int kNumPrograms = 1;

enum EParams
{
  kNumParams
};

enum ELayout
{
  kWidth = GUI_WIDTH,
  kHeight = GUI_HEIGHT,
};

nishVST::nishVST(IPlugInstanceInfo instanceInfo)
  :	IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), var(1.)
{
  TRACE;

  IGraphics* pGraphics = MakeGraphics(this, kWidth, kHeight);
  pGraphics->AttachPanelBackground(&COLOR_WHITE);

  AttachGraphics(pGraphics);

  MakeDefaultPreset((char *) "-", kNumPrograms);
}

nishVST::~nishVST() {}

void nishVST::ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames)
{

  double* in1 = inputs[0];
  double* in2 = inputs[1];
  double* out1 = outputs[0];
  double* out2 = outputs[1];

  for (int s = 0; s < nFrames; ++s, ++in1, ++in2, ++out1, ++out2)
  {
    *out1 = *in1;
    *out2 = *in2;
  }
}

void nishVST::Reset()
{
  TRACE;
  IMutexLock lock(this);
}

void nishVST::OnParamChange(int paramIdx)
{
  IMutexLock lock(this);

}
