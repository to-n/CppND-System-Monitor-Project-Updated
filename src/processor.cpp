#include "processor.h"

#include <string>
#include <vector>

#include "linux_parser.h"

Processor::Processor() { utilization_ = 0.0; }
Processor::Processor(float utilization) : utilization_(utilization){};

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { return utilization_; }
