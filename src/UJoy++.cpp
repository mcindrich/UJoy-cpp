#include <UJoy++.hpp>

namespace ujoy
{
////////////////////////////////////

Joystick::Joystick()
{
    UJoyInit(&mJoy);
}

////////////////////////////////////

void Joystick::open(std::optional<int> index)
{
    if (index.has_value())
    {
        UJoyOpenIndex(&mJoy, index.value());
    }
    else
    {
        UJoyOpen(&mJoy);
    }
}

////////////////////////////////////

bool Joystick::isConnected() const
{
    return mJoy.Connected == 1;
}

////////////////////////////////////

uint8_t Joystick::getButtonState(Button button)
{
    return UJoyGetButtonState(&mJoy, (UJoyButton)button);
}

////////////////////////////////////

int16_t Joystick::getAxisState(Axis axis)
{
    return UJoyGetAxisState(&mJoy, (UJoyAxis)axis);
}

////////////////////////////////////

void Joystick::refresh()
{
    UJoyRefresh(&mJoy);
}

////////////////////////////////////

Joystick::~Joystick()
{
    UJoyFree(&mJoy);
}

////////////////////////////////////
} // namespace ujoy