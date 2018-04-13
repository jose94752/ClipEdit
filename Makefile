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
	
doc-pdf:
	# Create dir if necessary
	mkdir -p Docs/fr/pdf
	mkdir -p Docs/en/pdf
	
	# Generate international docs
	pandoc -st beamer -V theme:Warsaw Docs/fr/*.md -V fontsize:11pt -o Docs/fr/pdf/ClipEdit-doc-fr.pdf
	pandoc -st beamer -V theme:Warsaw Docs/en/*.md -V fontsize:11pt -o Docs/en/pdf/ClipEdit-doc-en.pdf
	
doc-html:
	# TO DO
docx:
	# Create dir if necessary
	mkdir -p Docs/fr/docx
	mkdir -p Docs/en/docx
	pandoc -f markdown -t docx Docs/fr/presentation.md -o Docs/fr/docx/presentation.docx
	pandoc -f markdown -t docx Docs/fr/pandocInstallationFedora.md -o Docs/fr/docx/pandocInstallFedora.docx
	pandoc -f markdown -t docx Docs/en/presentation.md -o Docs/en/docx/presentation.docx
	pandoc -f markdown -t docx Docs/en/pandocInstallFedora.md -o Docs/en/docx/pandocInstallFedora.docx
	

clean:
	rm -f *.o
	
distclean:
	rm -f *.o ClipEdit
