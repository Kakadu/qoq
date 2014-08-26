camltarget.target = ocaml/code.a
camltarget.commands = make -C ocaml/
camltarget.depends = echotarget

echotarget.commands = @echo Building camltarget


SOURCES += \


OTHER_FILES += \
    ocaml/camlmain.ml \
    ocaml/Makefile


