typedef enum
{
    false,
    true
} bool;
typedef enum
{
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGrey,
    DarkGrey,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LigthMagenta,
    Yellow,
    White
} biosColor;
void print(const char *string, biosColor fg, biosColor bg);
void setTitle(const char *string, biosColor fg, biosColor bg);
void printCenter(const char *string, biosColor fg, biosColor bg);
void initMem();
int strlen(const char *string);