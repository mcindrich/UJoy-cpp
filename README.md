# UJoy++ - C++ wrapper for [UJoy](https://github.com/mcindrich/UJoy) library

# Docs - the code is under the `ujoy` namespace
```c++
// Joystick button enum
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
// Joystick axis enum
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