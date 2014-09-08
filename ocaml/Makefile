OCAMLOPT=ocamlfind opt
OCAMLC=ocamlfind c
OCAMLLIBDIR=$(shell ocamlfind c -where)

OUT=kamlo.a


.PHONY: all clean

all: kamlo.a

libasmrun.a: $(OCAMLLIBDIR)/libasmrun.a
	cp $< $@

kamlo.a: libasmrun.a kamlocode.o
	ar q libasmrun.a kamlocode.o
	mv libasmrun.a kamlo.a

kamlocode.o: kamlomain.ml
	$(OCAMLOPT) -output-obj kamlomain.ml -o kamlocode.o

clean:
	rm -fr $(OUT) *.cm[ioxa] *.cmxa *.o
