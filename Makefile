# ClipEdit Makefile
# -----------------

#TO DO : 	- Package checking ?
#			- Sub makefile for doc		

all: docx doc-pdf doc-man doc-html odt


doc-man:
	# Create dir if necessary
	mkdir -p Docs/fr/man
	mkdir -p Docs/en/man
	
	# Generate international docs
	pandoc -s -t man Docs/fr/presentation.md -o Docs/fr/man/ClipEdit-man-fr
	pandoc -s -t man Docs/en/presentation.md -o Docs/en/man/ClipEdit-man-en

odt:
	# Create dir if neccessary
	mkdir -p Docs/fr/odt
	mkdir -p Docs/en/odt
	
	# Generate international docs
	pandoc -f markdown -t odt Docs/fr/presentation.md -o Docs/fr/odt/ClipEdit-fr.odt
	pandoc -f markdown -t odt Docs/fr/pandocInstallationFedora.md -o Docs/fr/odt/pandocInstallationFedora.odt
	pandoc -f markdown -t odt Docs/en/presentation.md -o Docs/en/odt/ClipEdit-en.odt
	pandoc -f markdown -t odt Docs/en/pandocInstallFedora.md -o Docs/en/odt/pandocInstallFedora.odt
	

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
	pandoc	Docs/fr/presentation.md	-V	fontsize:11pt --toc	-o	Docs/fr/pdf/ClipEdit-doc-fr.pdf
	pandoc	Docs/en/presentation.md	-V	fontsize:11pt --toc	-o	Docs/en/pdf/ClipEdit-doc-en.pdf
	
doc-html:
	# TO DO
docx:
	# Create dir if necessary
	mkdir -p Docs/fr/docx
	mkdir -p Docs/en/docx
	pandoc --toc -f markdown -t docx Docs/fr/presentation.md -o Docs/fr/docx/presentation.docx
	pandoc --toc -f markdown -t docx Docs/fr/pandocInstallationFedora.md -o Docs/fr/docx/pandocInstallFedora.docx
	pandoc --toc -f markdown -t docx Docs/en/presentation.md -o Docs/en/docx/presentation.docx
	pandoc --toc -f markdown -t docx Docs/en/pandocInstallFedora.md -o Docs/en/docx/pandocInstallFedora.docx

doc-epub:
	# Create dir if necessary
	mkdir -p Docs/fr/epub
	mkdir -p Docs/en/epub 

	# Generate international docs
	pandoc -s --toc  -t EPUB Docs/fr/presentation.md -o Docs/fr/epub/ClipEdit-doc-fr.epub
	pandoc -s --toc  -t EPUB Docs/en/presentation.md -o Docs/en/epub/ClipEdit-doc-en.epub


clean:
	rm -f *.o
