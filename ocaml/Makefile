OCAMLOPT=ocamlfind opt
OUT=kamlo

.PHONY: all clean

all: $(OUT).a

$(OUT).a: camlcode.a
	

camlcode.a:
	$(OCAMLOPT) -c camlmain.ml 
	ocamlmklib -o $@ -I `ocamlc -where` -cclib `ocamlc -where`/libasmrun.a camlmain.cmx

clean:
	rm -fr $(OUT).a *.cm[ioxa]

