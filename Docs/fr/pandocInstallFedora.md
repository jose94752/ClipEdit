# Pandoc installation rapide sur Linux Fedora
Utilisez votre gestionnaire de paquetage pour avoir Pandoc depuis les dépôts Fedora vous pouvez utiliser yum ou dnf comme commande.

~~~bash
$ su
$ yourroot_password
~~~

et

~~~bash
$ yum install pandoc
~~~

ou

~~~bash	
$ dnf install pandoc
~~~

# Linux depuis targz
[lien de téléchargement](https://github.com/jgm/pandoc/releases/latest)

Ils fournissent un paquetage binaire pour une architecture amd64 sur la page de téléchargement. Ceci est fourni à la fois pour pandoc et pandoc-citeproc. Les executables sont liés statiquement et n'ont pas de dépendances dynamiques ou dépendences sur des fichiers de données externe. Note: en raison de ce liage statique, le binaire pandoc de ce paquetage ne peut pas être utilisé avec les filtres lua ce qui requiert des modules lua externes écrits en C.

[Source depuis le site Pandoc un convertisseur universel de documents](https://pandoc.org/installing.html)