# UJoy++ - C++ wrapper for [UJoy](https://github.com/mcindrich/UJoy) library

# Docs - the code is under the `ujoy` namespace

## Include

```c++
#include <UJoy++.hpp>
```

## API

```c++
// Joystick button enum
enum class Button
{
    DPadUp,
    DPadDown,
    DPadLeft,
    DPadRight,
    Start,
    Back,
    LS,
    RS,
    LB,
    RB,
    A,
    B,
    X,
    Y,
    Menu,
};
// Joystick axis enum
enum class Axis
{
    DPadX,
    DPadY,
    LT,
    RT,
    LSX,
    LSY,
    RSX,
    RSY,
};
// Main API class
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
};
```