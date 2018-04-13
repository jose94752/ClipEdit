# ClipEdit Makefile
# -----------------

#TO DO : 	- Package checking ?
#			- Sub makefile for doc		

all:
	#TO DO

doc-man:
	# Create dir if necessary
	mkdir -p Docs/fr/man
	mkdir -p Docs/en/man
	
	# Generate international docs
	pandoc -s -t man Docs/fr/presentation.md -o Docs/fr/man/ClipEdit-man-fr
	pandoc -s -t man Docs/en/presentation.md -o Docs/en/man/ClipEdit-man-en
	
doc-pdf:
	# Create dir if necessary
	mkdir -p Docs/fr/pdf
	mkdir -p Docs/en/pdf
	
	# Generate international docs
	pandoc -st beamer -V theme:Warsaw Docs/fr/presentation.md -V fontsize:11pt -o Docs/fr/pdf/ClipEdit-doc-fr.pdf
	pandoc -st beamer -V theme:Warsaw Docs/en/presentation.md -V fontsize:11pt -o Docs/en/pdf/ClipEdit-doc-en.pdf
	
doc-html:
	# TO DO
	
clean:
	rm -f *.o
	
distclean:
	rm -f *.o ClipEdit
