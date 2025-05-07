# SPDX-License-Identifier: CC0-1.0

libuvcgadget = dependency('uvcgadget')

cc = meson.get_compiler('c')
pigpio_lib = cc.find_library('pigpio', required : true)
pigpio = declare_dependency(dependencies : pigpio_lib)

gadget = executable('uvc-gadget', 'main.c',
                    dependencies : [
                        libuvcgadget,
                        pigpio,
                    ],
                    include_directories : [includes, config_includes],
                    install : true)
