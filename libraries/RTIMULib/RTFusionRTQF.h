////////////////////////////////////////////////////////////////////////////
//
//  This file is part of RTIMULib-Teensy
//
//  Copyright (c) 2014, richards-tech
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
//  Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#ifndef _RTFUSIONRTQF_H
#define	_RTFUSIONRTQF_H

#include "RTFusion.h"

class RTFusionRTQF : public RTFusion
{
public:
    RTFusionRTQF();
    ~RTFusionRTQF();

    //  fusionType returns the type code of the fusion algorithm

    virtual int fusionType() { return RTFUSION_TYPE_RTQF; }

    //  reset() resets the state but keeps any setting changes (such as enables)

    void reset();

    //  newIMUData() should be called for subsequent updates
    //  deltaTime is in units of seconds

    void newIMUData(RTIMU_DATA& data);

    //  the following two functions can be called to customize the noise covariance

    void setQ(RTFLOAT Q) {  m_Q = Q; reset();}
    void setR(RTFLOAT R) { if (R > 0) m_R = R; reset();}

private:
	void predict();
	void update();

    RTVector3 m_gyro;										// unbiased gyro data
    RTFLOAT m_timeDelta;                                    // time between predictions

    RTQuaternion m_stateQ;									// quaternion state vector
    RTQuaternion m_stateQError;                             // difference between stateQ and measuredQ

    RTFLOAT m_Q;                                            // process noise covariance
    RTMatrix4x4 m_Fk;                                       // the state transition matrix
    RTFLOAT m_R;                                            // the measurement noise covariance

    int m_sampleNumber;
};

#endif // _RTFUSIONRTQF_H
