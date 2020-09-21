SRC += muse.c

COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no     # Console for debug(+400)
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality

LINK_TIME_OPTIMIZATION_ENABLE = yes
EXTRAFLAGS += -flto
