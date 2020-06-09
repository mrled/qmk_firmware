# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

# The avr-gcc in pkgsrc on macos doesn't enable LTO, ugh
#LINK_TIME_OPTIMIZATION_ENABLE = yes

COMMAND_ENABLE = no
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
KEY_LOCK_ENABLE = yes

