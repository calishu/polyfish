#include <cstdint>
#include <cstdlib>
#include <format>
#include <string>

namespace colors::ansi
{
constexpr std::string_view reset = "\033[0m";
}

namespace colors
{

static inline auto color_state(const bool state = true) -> bool
{
    static bool enabled = state;
    return enabled;
}

inline auto enable_colors() -> void
{
    color_state(true);
}
inline auto disable_colors() -> void
{
    color_state(false);
}

inline auto is_color_enabled() -> bool
{
    if (std::getenv("NO_COLOR")) return false;
    if (!color_state()) return false;
    return true;
}

#define ANSI_GEN(name, code)                                                               \
    namespace colors                                                                       \
    {                                                                                      \
    namespace ansi                                                                         \
    {                                                                                      \
    constexpr std::string_view name = code;                                                \
    }                                                                                      \
    inline auto name(std::string_view text) -> std::string                                 \
    {                                                                                      \
        if (!is_color_enabled()) return std::string(text);                                 \
        std::string out;                                                                   \
        out.reserve(colors::ansi::name.size() + text.size() + colors::ansi::reset.size()); \
        out += colors::ansi::name;                                                         \
        out += text;                                                                       \
        out += colors::ansi::reset;                                                        \
        return out;                                                                        \
    }                                                                                      \
    inline auto name(std::ostream &os) -> std::ostream &                                   \
    {                                                                                      \
        if (is_color_enabled()) os << colors::ansi::name;                                  \
        return os;                                                                         \
    }                                                                                      \
    }

struct RGB
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    [[nodiscard]] auto to_ansi() const -> std::string { return std::format("\033[38;2;{};{};{}m", red, green, blue); }
};

#define RGB_ANSI_GEN(name, red, green, blue)                           \
    namespace colors                                                   \
    {                                                                  \
    inline auto name(std::string_view text) -> std::string             \
    {                                                                  \
        return rgb_color(text, RGB{red, green, blue});                 \
    }                                                                  \
    inline auto name(std::ostream &os) -> std::ostream &               \
    {                                                                  \
        if (is_color_enabled()) os << RGB{red, green, blue}.to_ansi(); \
        return os;                                                     \
    }                                                                  \
    }

inline auto rgb_color(std::string_view text, const RGB &color) -> std::string
{
    if (!is_color_enabled()) return std::string(text);
    auto ansi = color.to_ansi();

    std::string out;
    out.reserve(ansi.size() + text.size() + colors::ansi::reset.size());
    out += ansi;
    out += text;
    out += colors::ansi::reset;
    return out;
}

} // namespace colors

// Foreground colors
ANSI_GEN(black, "\033[30m");
ANSI_GEN(red, "\033[31m");
ANSI_GEN(green, "\033[32m");
ANSI_GEN(yellow, "\033[33m");
ANSI_GEN(blue, "\033[34m");
ANSI_GEN(magenta, "\033[35m");
ANSI_GEN(cyan, "\033[36m");
ANSI_GEN(white, "\033[37m");

// Bright foreground colors
ANSI_GEN(bright_black, "\033[90m");
ANSI_GEN(bright_red, "\033[91m");
ANSI_GEN(bright_green, "\033[92m");
ANSI_GEN(bright_yellow, "\033[93m");
ANSI_GEN(bright_blue, "\033[94m");
ANSI_GEN(bright_magenta, "\033[95m");
ANSI_GEN(bright_cyan, "\033[96m");
ANSI_GEN(bright_white, "\033[97m");

// Background colors
ANSI_GEN(bg_black, "\033[40m");
ANSI_GEN(bg_red, "\033[41m");
ANSI_GEN(bg_green, "\033[42m");
ANSI_GEN(bg_yellow, "\033[43m");
ANSI_GEN(bg_blue, "\033[44m");
ANSI_GEN(bg_magenta, "\033[45m");
ANSI_GEN(bg_cyan, "\033[46m");
ANSI_GEN(bg_white, "\033[47m");

// Bright background colors
ANSI_GEN(bg_bright_black, "\033[100m");
ANSI_GEN(bg_bright_red, "\033[101m");
ANSI_GEN(bg_bright_green, "\033[102m");
ANSI_GEN(bg_bright_yellow, "\033[103m");
ANSI_GEN(bg_bright_blue, "\033[104m");
ANSI_GEN(bg_bright_magenta, "\033[105m");
ANSI_GEN(bg_bright_cyan, "\033[106m");
ANSI_GEN(bg_bright_white, "\033[107m");

// Text styles
ANSI_GEN(bold, "\033[1m");
ANSI_GEN(dim, "\033[2m");
ANSI_GEN(italic, "\033[3m");
ANSI_GEN(underline, "\033[4m");
ANSI_GEN(blink, "\033[5m");
ANSI_GEN(reverse, "\033[7m");
ANSI_GEN(hidden, "\033[8m");
ANSI_GEN(strikethrough, "\033[9m");

// Reset styles
ANSI_GEN(reset_bold, "\033[21m");
ANSI_GEN(reset_dim, "\033[22m");
ANSI_GEN(reset_italic, "\033[23m");
ANSI_GEN(reset_underline, "\033[24m");
ANSI_GEN(reset_blink, "\033[25m");
ANSI_GEN(reset_reverse, "\033[27m");
ANSI_GEN(reset_hidden, "\033[28m");
ANSI_GEN(reset_strike, "\033[29m");
