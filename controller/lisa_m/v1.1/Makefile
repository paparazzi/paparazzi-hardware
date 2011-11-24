#
# Lisa/M part of the Paparazzi project
# Copyright (c) 2011 Piotr Esden-Tempski <piotr@esden.net>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

BRD_SRCS = ./lisa_m.brd

DIRS =

##### This substitutions work only with EXACTLY ONE level of subdirectory !!!!!
SCHEMATICS=$(subst /,/printable/,$(BRD_SRCS:%.brd=%.schematics.ps))
TOP_LAYER=$(subst /,/printable/,$(BRD_SRCS:%.brd=%.top_layer.ps))
TOP_COMP=$(subst /,/printable/,$(BRD_SRCS:%.brd=%.top_comp.ps))
BOTTOM_LAYER=$(subst /,/printable/,$(BRD_SRCS:%.brd=%.bottom_layer.ps))
BOTTOM_COMP=$(subst /,/printable/,$(BRD_SRCS:%.brd=%.bottom_comp.ps))
POSTSCRIPTS= $(SCHEMATICS) $(TOP_LAYER) $(TOP_COMP) $(BOTTOM_LAYER) $(BOTTOM_COMP)
PDF=$(POSTSCRIPTS:%.ps=%.pdf)


GERB_O = $(BRD_SRCS:.brd=.all)

all: gerber

gerber: $(GERB_O)

printable: dirs $(POSTSCRIPTS) $(PDF)

dirs :
	mkdir -p $(DIRS:%=%/printable)


### GERBER GENERATION

.PRECIOUS : %.cmp %.sol %.stc %.sts %.tplc %.bplc %.bor %.xln %.l02 %.l15 %.tcr %.bcr

%.all: %.cmp %.sol %.stc %.sts %.tplc %.bplc %.xln %.bor %.l02 %.l15 %.tcr %.bcr
	touch $@

# Component side
%.cmp : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< Top Pads Vias
# Solder side
%.sol : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< Bottom Pads Vias
# Solder stop mask comp. side
%.stc : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< tStop
# Solder stop mask sold. side
%.sts : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< bStop
# Silkscreen comp. side
%.tplc : %.brd
	#eagle -X -N -d GERBER_RS274X -o $@ $< Dimension tPlace tDocu
	eagle -X -N -d GERBER_RS274X -o $@ $< Dimension tPlace
# Silkscreen sold. side
%.bplc : %.brd
	#eagle -X -N -d GERBER_RS274X -o $@ $< Dimension bPlace bDocu
	eagle -X -N -d GERBER_RS274X -o $@ $< Dimension bPlace
# Cream comp. side
%.tcr: %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< tCream
# Cream sold. side
%.bcr: %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< bCream
# Drill data for NC drill st.
# warning : eagle takes path of -R option from input file directory.
%.xln : %.brd
	eagle -X -N -d EXCELLON -E -0.02 -E 0.1 -R fab/eurocircuits.drl -o $@ $< Drills Holes
# Outline
%.bor : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< Dimension
# Inner layer top
%.l02 : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< Route2 Pads Vias
# Inner layer bot
%.l15 : %.brd
	eagle -X -N -d GERBER_RS274X -o $@ $< Route15 Pads Vias


### POSTSCRIPT AND PDF GENERATION


%.pdf : %.ps
	ps2pdf $< $@

%.schematics.ps : ../%.sch
	eagle -X -N -d PS -x.4 -y.2 -o $@ $< Nets Busses Symbols Names Values

%.top_layer.ps : ../%.brd
	eagle -X -N -f- -m+ -d PS -h2 -w3 -o $@ $< Top Pad Via Dimension

%.top_comp.ps : ../%.brd
	eagle -X -N -f- -d PS -h2 -w2 -o $@ $< Pad Via Dimension tPlace tNames tDocu

%.bottom_layer.ps : ../%.brd
	eagle -X -N -f- -d PS -h2 -w3 -o $@ $< Bottom Pad Via Dimension

%.bottom_comp.ps : ../%.brd
	eagle -X -N -f- -m+ -c -d PS -h2 -w2 -o $@ $< Pad Via Dimension bPlace bNames bDocu


clean:
	@# gerber and excellon
	find .. -name '*.cmp' -exec rm -f {} \;
	find .. -name '*.sol' -exec rm -f {} \;
	find .. -name '*.stc' -exec rm -f {} \;
	find .. -name '*.sts' -exec rm -f {} \;
	find .. -name '*.tplc' -exec rm -f {} \;
	find .. -name '*.bplc' -exec rm -f {} \;
	find .. -name '*.bor' -exec rm -f {} \;
	find .. -name '*.xln' -exec rm -f {} \;
	find .. -name '*.dri' -exec rm -f {} \;
	find .. -name '*.gpi' -exec rm -f {} \;
	find .. -name '*.l02' -exec rm -f {} \;
	find .. -name '*.l15' -exec rm -f {} \;
	find .. -name '*.all' -exec rm -f {} \;
	find .. -name '*.tcr' -exec rm -f {} \;
	find .. -name '*.bcr' -exec rm -f {} \;
	@# printable
	find . -name '*.schematics.ps' -exec rm -f {} \;
	find . -name '*.schematics.pdf' -exec rm -f {} \;
	find . -name '*.top_layer.ps' -exec rm -f {} \;
	find . -name '*.top_layer.pdf' -exec rm -f {} \;
	find . -name '*.top_comp.ps' -exec rm -f {} \;
	find . -name '*.top_comp.pdf' -exec rm -f {} \;
	find . -name '*.bottom_layer.ps' -exec rm -f {} \;
	find . -name '*.bottom_layer.pdf' -exec rm -f {} \;
	find . -name '*.bottom_comp.ps' -exec rm -f {} \;
	find . -name '*.bottom_comp.pdf' -exec rm -f {} \;
	@# eagle error log
	find .. -name '*.erc' -exec rm -f {} \;
	@# eagle autorouter log
	find .. -name '*.pro' -exec rm -f {} \;
	@# eagle backups	
	find .. -name '*#*' -exec rm -f {} \;
	@# emacs backups
	find .. -name '*~' -exec rm -f {} \;
