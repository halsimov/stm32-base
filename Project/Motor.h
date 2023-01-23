#ifndef FIRMWARE_MOTOR_H
#define FIRMWARE_MOTOR_H

#include <cstdint>

namespace project
{
    class Motor
    {
    public:
        explicit Motor();

        uint32_t GetRPM() const;

        void UpdateRPM(uint32_t current_time);

    private:
        uint32_t last_capture_time_;
        uint32_t capture_interval_;
        uint32_t rpm_;
    };

} // namespace project

#endif // FIRMWARE_MOTOR_H
