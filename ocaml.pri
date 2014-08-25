camltarget.target = caml/code.a
camltarget.commands = make -C caml/
camltarget.depends = echotarget

echotarget.commands = @echo Building camltarget


SOURCES += \


OTHER_FILES += \
    ocaml/camlmain.ml \
    ocaml/Makefile


