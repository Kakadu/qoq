OCAMLOPT=ocamlfind opt
OCAMLC=ocamlfind c
OCAMLLIBDIR=$(shell ocamlfind c -where)

OUT=kamlo


.PHONY: all clean

all: $(OUT).a

$(warning $(OCAMLLIBDIR) )

libasmrun.a: $(OCAMLLIBDIR)/libasmrun.a
	cp $< $@

$(OUT).a: camlcode.a libasmrun.a
	#libtool --mode=link cc -static -o kamlo.a camlcode.a libasmrun.a
	ar -M < kamlo.mri

camlcode.a:
	$(OCAMLOPT) -c camlmain.ml
	ocamlmklib -o camlcode -I `ocamlc -where` -cclib `ocamlc -where`/libasmrun.a camlmain.cmx

clean:
	rm -fr $(OUT).a *.cm[ioxa] *.cmxa *.o
