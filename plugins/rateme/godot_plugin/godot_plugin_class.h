#pragma once

#include "core/object.h"

class RateMe : public Object {
    GDCLASS(RateMe, Object);
    
    static void _bind_methods();
    
public:
    void showRateMe ();
    
    RateMe();
    ~RateMe();
};


