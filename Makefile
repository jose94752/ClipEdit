# ClipEdit Makefile
# -----------------

#TO DO : 	- Package checking ?
#			- Sub makefile for doc		

all:
	#TO DO
        #il manque l'implementation ...


doc-man:
	# Create dir if necessary
	mkdir -p Docs/fr/man
	mkdir -p Docs/en/man
	
	# Generate international docs
	pandoc -s -t man Docs/fr/presentation.md -o Docs/fr/man/ClipEdit-man-fr
	pandoc -s -t man Docs/en/presentation.md -o Docs/en/man/ClipEdit-man-en

doc-odt:
	# Create dir if neccessary
	mkdir -p Docs/fr/odt
	mkdir -p Docs/en/odt
	
	# Generate international docs
	# TO DO
	# En cours josé
	

doc-pdf:
	# Create dir if necessary
	mkdir -p Docs/fr/pdf
	mkdir -p Docs/en/pdf
	
	# Generate international docs
	# TO DO 
	# beamer c'est pour les présentations
	# From markdown to PDF:
	# pandoc MANUAL.txt --pdf-engine=xelatex -o example13.pdf
	# par contre cet exemple
	#	Code à refaire:
	# pandoc -st beamer -V theme:Warsaw Docs/fr/presentation.md -V fontsize:11pt -o Docs/fr/pdf/ClipEdit-doc-fr.pdf
	# pandoc -st beamer -V theme:Warsaw Docs/en/presentation.md -V fontsize:11pt -o Docs/en/pdf/ClipEdit-doc-en.pdf
	
doc-html:
	# TO DO
	
clean:
	# rm -f *.o
	
distclean:
	rm -f *.o ClipEdit
