# ClipEdit Makefile
# -----------------

#TO DO : 	- Package checking ?
#			- Sub makefile for doc		

all: docx doc-pdf doc-man doc-html odt doc-epub


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
	pandoc -f markdown -t odt Docs/fr/pandocInstall.md -o Docs/fr/odt/pandocInstallation.odt
	pandoc -f markdown -t odt Docs/en/presentation.md -o Docs/en/odt/ClipEdit-en.odt
	pandoc -f markdown -t odt Docs/en/pandocInstall.md -o Docs/en/odt/pandocInstall.odt
	

doc-pdf:
	# Create dir if necessary
	mkdir -p Docs/fr/pdf
	mkdir -p Docs/en/pdf
	
	pandoc	Docs/fr/presentation.md	-V	fontsize:11pt --toc	-o	Docs/fr/pdf/ClipEdit-doc-fr.pdf
	pandoc	Docs/en/presentation.md	-V	fontsize:11pt --toc	-o	Docs/en/pdf/ClipEdit-doc-en.pdf
	pandoc	Docs/fr/pandocInstall.md	-V	fontsize:11pt --toc	-o	Docs/fr/pdf/pandocInstall.pdf
	pandoc	Docs/en/pandocInstall.md	-V	fontsize:11pt --toc	-o	Docs/en/pdf/pandocInstall.pdf
	
	
doc-html:
	# TO DO
	# Create dir if necessary
	mkdir -p Docs/fr/html
	mkdir -p Docs/en/html
	
	# Convert all files in this directory that have a .md suffix
	# From markdown to html:
	# Code fait
	pandoc	Docs/fr/presentation.md	 --toc	-o	Docs/fr/html/ClipEdit-doc-fr.html
	pandoc	Docs/en/presentation.md	 --toc	-o	Docs/en/html/ClipEdit-doc-en.html
	
	
	
	
        
docx:
	# Create dir if necessary
	mkdir -p Docs/fr/docx
	mkdir -p Docs/en/docx

	pandoc --toc -f markdown -t docx Docs/fr/presentation.md -o Docs/fr/docx/presentation.docx
	pandoc --toc -f markdown -t docx Docs/fr/pandocInstall.md -o Docs/fr/docx/pandocInstall.docx
	pandoc --toc -f markdown -t docx Docs/en/presentation.md -o Docs/en/docx/presentation.docx
	pandoc --toc -f markdown -t docx Docs/en/pandocInstall.md -o Docs/en/docx/pandocInstall.docx

doc-epub:
	# Create dir if necessary
	mkdir -p Docs/fr/epub
	mkdir -p Docs/en/epub 

	# Generate international docs
	pandoc -s --toc  -t EPUB Docs/fr/presentation.md -o Docs/fr/epub/ClipEdit-doc-fr.epub
	pandoc -s --toc  -t EPUB Docs/en/presentation.md -o Docs/en/epub/ClipEdit-doc-en.epub
	pandoc --toc -f markdown -t EPUB Docs/fr/pandocInstall.md -o Docs/fr/epub/pandocInstall.epub
	pandoc --toc -f markdown -t EPUB Docs/en/pandocInstall.md -o Docs/en/epub/pandocInstall.epub


clean:
	rm -f *.o
