# ClipEdit Makefile
# -----------------

# Markdown files
MD_DOC=presentation.md
MD_PANDOC=pandocInstall.md

# Language directories
DIR_FR=Docs/fr
DIR_EN=Docs/en

# Output bases
BASE_DOC=clipedit
BASE_PANDOC=pandocInstall

all: docx doc-pdf doc-man doc-html odt

doc-man:
	# Create dir if necessary
	mkdir -p $(DIR_FR)/man
	mkdir -p $(DIR_EN)/man
	
	# Generate international docs
	pandoc -s -t man $(DIR_FR)/$(MD_DOC) -o $(DIR_FR)/man/$(BASE_DOC)
	pandoc -s -t man $(DIR_EN)/$(MD_DOC) -o $(DIR_EN)/man/$(BASE_DOC)

odt:
	# Create dir if neccessary
	mkdir -p $(DIR_FR)/odt
	mkdir -p $(DIR_EN)/odt
	
	# Generate international docs
	pandoc -f markdown -t odt $(DIR_FR)/$(MD_DOC) -o $(DIR_FR)/odt/$(BASE_DOC).odt
	pandoc -f markdown -t odt $(DIR_FR)/$(MD_PANDOC) -o $(DIR_FR)/odt/$(BASE_PANDOC).odt
	pandoc -f markdown -t odt $(DIR_EN)/$(MD_DOC) -o $(DIR_EN)/odt/$(BASE_DOC).odt
	pandoc -f markdown -t odt $(DIR_EN)/$(MD_PANDOC) -o $(DIR_EN)/odt/$(BASE_PANDOC).odt
	

doc-pdf:
	# Create dir if necessary
	mkdir -p $(DIR_FR)/pdf
	mkdir -p $(DIR_EN)/pdf

	pandoc	$(DIR_FR)/$(MD_DOC) -V fontsize:11pt --toc -o $(DIR_FR)/pdf/$(BASE_DOC).pdf
	pandoc	$(DIR_FR)/$(MD_PANDOC) -V fontsize:11pt --toc -o $(DIR_FR)/pdf/$(BASE_PANDOC).pdf
	pandoc	$(DIR_EN)/$(MD_DOC) -V fontsize:11pt --toc -o $(DIR_EN)/pdf/$(BASE_DOC).pdf
	pandoc	$(DIR_EN)/$(MD_PANDOC) -V fontsize:11pt --toc -o $(DIR_EN)/pdf/$(BASE_PANDOC).pdf
doc-html:
	# TO DO
docx:
	# Create dir if necessary
	mkdir -p $(DIR_FR)/docx
	mkdir -p $(DIR_EN)/docx

	pandoc --toc -f markdown -t docx $(DIR_FR)/$(MD_DOC) -o $(DIR_FR)/docx/$(BASE_DOC).docx
	pandoc --toc -f markdown -t docx $(DIR_FR)/$(MD_PANDOC) -o $(DIR_FR)/docx/$(BASE_PANDOC).docx
	pandoc --toc -f markdown -t docx $(DIR_EN)/$(MD_DOC) -o $(DIR_EN)/docx/$(BASE_DOC).docx
	pandoc --toc -f markdown -t docx $(DIR_EN)/$(MD_PANDOC) -o $(DIR_EN)/docx/$(BASE_PANDOC).docx

doc-epub:
	# Create dir if necessary
	mkdir -p $(DIR_FR)/epub
	mkdir -p $(DIR_EN)/epub 

	# Generate international docs
	pandoc -s --toc  -t EPUB $(DIR_FR)/$(MD_DOC) -o $(DIR_FR)/epub/$(BASE_DOC).epub
	pandoc -s --toc  -t EPUB $(DIR_EN)/$(MD_DOC) -o $(DIR_EN)/epub/$(BASE_DOC).epub

clean:
	rm -f *.o
	rm -rf $(DIR_FR)/*/
	rm -rf $(DIR_EN)/*/
