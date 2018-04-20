# ClipEdit Makefile
# -----------------

# Language directories
DIR_FR=fr
DIR_EN=en

# Output files
PDF=$(patsubst %.md, %.pdf, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))
ODT=$(patsubst %.md, %.odt, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))
DOCX=$(patsubst %.md, %.docx, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))
EPUB=$(patsubst %.md, %.epub, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))
HTML=$(patsubst %.md, %.html, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))
MAN=$(patsubst %.md, %, $(wildcard $(DIR_EN)/*.md $(DIR_FR)/*.md))

all: $(PDF) $(ODT) $(DOCX) $(EPUB) $(HTML) $(MAN)

%.pdf: %.md
	# Create dir if necessary
	@mkdir -p $(DIR_FR)/pdf $(DIR_EN)/pdf

	# Generate docs
	pandoc $< -V fontsize:11pt --toc -o $@
	@mv $@ $(dir $@)/pdf

%.odt: %.md
	# Create dir if neccessary
	@mkdir -p $(DIR_FR)/odt $(DIR_EN)/odt
	
	# Generate docs
	pandoc -f markdown -t odt $< -o $@
	@mv $@ $(dir $@)/odt
	
%.docx: %.md
	# Create dir if necessary
	@mkdir -p $(DIR_FR)/docx $(DIR_EN)/docx

	# Generate docs
	pandoc --toc -f markdown -t docx $< -o $@
	@mv $@ $(dir $@)/docx

%.epub: %.md
	# Create dir if necessary
	@mkdir -p $(DIR_FR)/epub $(DIR_EN)/epub 

	# Generate docs
	pandoc -s --toc  -t EPUB $< -o $@
	@mv $@ $(dir $@)/epub

%.html: %.md
	# Create dir if necessary
	@mkdir -p $(DIR_FR)/html $(DIR_EN)/html 

	# Generate docs
	pandoc --ascii --from=markdown --to=html $< -o $@
	@mv $@ $(dir $@)/html

%: %.md
	# Create dir if necessary
	@mkdir -p $(DIR_FR)/man $(DIR_EN)/man
	
	# Generate docs
	pandoc -s -t man $< -o $@
	@mv $@ $(dir $@)/man

clean:
	@rm -f *.o
	@rm -rf $(DIR_FR)/*/ $(DIR_EN)/*/ 
