#include "Motor.h"

namespace project
{

    Motor::Motor()
        : last_capture_time_(0)
        , capture_interval_(0)
        , rpm_(0)
    {
    }

    uint32_t Motor::GetRPM() const
    {
        return rpm_;
    }

    void Motor::UpdateRPM(uint32_t current_time)
    {
        if (last_capture_time_ == 0)
        {
            // This is the first capture event, so we can't calculate the RPM yet
            last_capture_time_ = current_time;
        }
        else
        {
            // Calculate the time interval between this capture event and the previous one
            capture_interval_ = current_time - last_capture_time_;
            last_capture_time_ = current_time;

            // Calculate the RPM based on the capture interval and the number of Hall sensors
            rpm_ = (60'000'000 / 3) / capture_interval_;
        }
    }

} // namespace project