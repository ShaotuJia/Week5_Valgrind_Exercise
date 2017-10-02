#include <AnalogSensor.hpp>
#include <numeric>
#include <vector>
#include <memory>
AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    //std::vector<int> *readings = new std::vector<int>(mSamples, 10);
    // change the memory-leak code to following:
    auto readings = std::make_unique<std::vector<int>>(mSamples, 10); 
    double result = std::accumulate( readings->begin(), readings->end(), 0.0 ) / readings->size();
    return result;
}


