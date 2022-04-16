#pragma once

extern "C"
{
#include <UJoy.h>
}

#include <string>
#include <optional>

namespace ujoy
{
enum class Button
{
    DPadUp = UJoyButtonDPadUp,
    DPadDown = UJoyButtonDPadDown,
    DPadLeft = UJoyButtonDPadLeft,
    DPadRight = UJoyButtonDPadRight,
    Start = UJoyButtonStart,
    Back = UJoyButtonBack,
    LS = UJoyButtonLS,
    RS = UJoyButtonRS,
    LB = UJoyButtonLB,
    RB = UJoyButtonRB,
    A = UJoyButtonA,
    B = UJoyButtonB,
    X = UJoyButtonX,
    Y = UJoyButtonY,
    Menu = UJoyButtonMenu,
};
enum class Axis
{
    DPadX = UJoyAxisDPadX,
    DPadY = UJoyAxisDPadY,
    LT = UJoyAxisLT,
    RT = UJoyAxisRT,
    LSX = UJoyAxisLSX,
    LSY = UJoyAxisLSY,
    RSX = UJoyAxisRSX,
    RSY = UJoyAxisRSY,
};
class Joystick
{
  public:
    // init UJoy struct
    Joystick();

    // try and open joystick device
    void open(std::optional<int> index = std::optional<int>());

    // check for connection
    bool isConnected() const;

    // button
    uint8_t getButtonState(Button button);

    // axis
    int16_t getAxisState(Axis axis);

    // check for changes
    void refresh();

    // free resources
    ~Joystick();

  private:
    UJoy mJoy;
};
} // namespace ujoy