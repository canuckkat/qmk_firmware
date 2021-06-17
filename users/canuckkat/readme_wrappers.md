## Keyboard Layout Templates

This will allow you to maintain blocks of commonly used keymaps in the userspace that can be reused in different layouts.

How this works is that you'll need declare
`#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)`

This is because we'll be using the wrapper in place of the default `LAYOUT` call in the `keymaps` declaration.

You'll also need to declare a base that you'll be working with to swap blocks as well as the default layout, which will be used the default keymap template. For example:
```
#define LAYOUT_lily58_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
) \
LAYOUT_wrapper( \
    KC_ESC,  K01, K02, K03, K04, K05,                    K06, K07, K08, K09, K0A, KC_BSPC,  \
    KC_TAB,  K11, K12, K13, K14, K15,                    K16, K17, K18, K19, K1A, KC_BSLS, \
    KC_LCTL, K21, K22, K23, K24, K25,                    K26, K27, K28, K29, K2A, KC_QUOT, \
    KC_LSFT, K31, K32, K33, K34, K35, KC_LBRC,  KC_RBRC, K36, K37, K38, K39, K3A, KC_RSFT, \
         KC_LEAD, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT,  MO(_RAISE), KC_BSPC, KC_RGUI           \
)
```

As you can see, `K01` in the `base` corresponds to the matching `K01` in the `LAYOUT_wrapper`, which will be part of the "block" of keys that will be replaced with our macro blocks.

If you just want to swap in your defined blocks into your base, use `base_wrapper()` function you defined for your keyboard.

If you want to re-defined the whole layout, use the general `LAYOUT_wrapper()`.
