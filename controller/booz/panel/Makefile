GERBMERGE = gerbmerge
GERBV = gerbv

CFG=layout.cfg
DEF=layout.def

panel:
	cd ..; make gerber; make -f Makefile.mirror gerber
	$(GERBMERGE) $(CFG) $(DEF)

view: panel
	$(GERBV) merged.*.ger

zip: panel
	zip pcb.zip merged.*

clean:
	rm -f merged.* *~ pcb.zip
