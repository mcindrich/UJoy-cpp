#include <UJoy++.hpp>
#include <csignal>

static volatile bool exit_app = false;

void sigintHandler(int sigint)
{
    exit_app = true;
}

int main()
{
    ujoy::Joystick joy;

    signal(SIGINT, sigintHandler);

    joy.open();

    while (joy.isConnected() && !exit_app)
    {
        uint8_t A = joy.getButtonState(ujoy::Button::A);
        uint8_t B = joy.getButtonState(ujoy::Button::B);
        uint8_t X = joy.getButtonState(ujoy::Button::X);
        uint8_t Y = joy.getButtonState(ujoy::Button::Y);
        uint8_t Start = joy.getButtonState(ujoy::Button::Start);
        uint8_t Back = joy.getButtonState(ujoy::Button::Back);
        uint8_t Menu = joy.getButtonState(ujoy::Button::Menu);
        uint8_t LS = joy.getButtonState(ujoy::Button::LS);
        uint8_t RS = joy.getButtonState(ujoy::Button::RS);
        uint8_t LB = joy.getButtonState(ujoy::Button::LB);
        uint8_t RB = joy.getButtonState(ujoy::Button::RB);

        int16_t LT = joy.getAxisState(ujoy::Axis::LT);
        int16_t RT = joy.getAxisState(ujoy::Axis::RT);
        int16_t LS_X = joy.getAxisState(ujoy::Axis::LSX);
        int16_t LS_Y = joy.getAxisState(ujoy::Axis::LSY);
        int16_t RS_X = joy.getAxisState(ujoy::Axis::RSX);
        int16_t RS_Y = joy.getAxisState(ujoy::Axis::RSY);
        int16_t DPadX = joy.getAxisState(ujoy::Axis::DPadX);
        int16_t DPadY = joy.getAxisState(ujoy::Axis::DPadY);

        printf("(A, B, X, Y) = (%d, %d, %d, %d)\n", A, B, X, Y);
        printf("(Back, Start, Menu) = (%d, %d, %d)\n", Back, Start, Menu);
        printf("(LS, RS) = (%d, %d)\n", LS, RS);
        printf("(LB, RB) = (%d, %d)\n", LB, RB);
        printf("LS(X, Y) = LS(%d, %d)\n", LS_X, LS_Y);
        printf("RS(X, Y) = RS(%d, %d)\n", RS_X, RS_Y);
        printf("(LT, RT) = (%d, %d)\n", LT, RT);
        printf("DPAD(X, Y) = DPAD(%d, %d)\n", DPadX, DPadY);

        printf("\n");

        joy.refresh();
    }

    return 0;
}