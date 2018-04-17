# Spécifications

Ce fichier contient les spécifications techniques pour le projet ClipEdit.

## Internationalisation

###  Arborescence et fichiers

La documentation de ClipEdit se trouve dans le répertoire `Docs`. Dans ce répertoire figurent des sous-dossiers pour chaque langue actuellement pris en charge par ClipEdit.

Liste des langues et des sous-répertoires associés :

| Langue       	| 	Sous-répertoire	|
| ----------------	| ---------------------------- 	|
| Français     	| fr      				|
| Anglais 		| en					|

Chaque sous-répertoire comporte les fichiers au format Markdown écrit dans la langue associée à l'arborescence courante. La documentation pour la langue en question peut-être générée via le Makefile par la commande `make`en ligne de commande.

### Code / Github

Tous les fichiers (.cpp / .h et autres) auront un nom en anglais. Les règles de nommage seront détaillées dans la partie suivante.

De la même façon, les commentaires de code et les messages des commits devront être rédigés en anglais.

## Nommage

Dans cette partie nous nous intéresserons aux règles de nommage des fichiers afin de conserver une unicité entre les différents modules développés et documents rédigés.

### Fichiers de création des composants

Ces fichiers détaillant chaque composant se trouvent dans les répertoires `Docs/<langue>`et devront respecter la convention de nommage suivante :

`Spec<composant avec une majuscule et un s>.md`

Ex: *SpecCharts.md*

### Formulaire de création des composants

Il s'agit des formulaires utilisés pour la création des composants graphiques de ClipEdit qui se trouvent dans `ClipEdit/sources`.

Ces fichiers devront respecter la règle de nommage suivante :

`form<composant en minuscule, attaché, avec un s>.ui`

Ex: *formcharts.md*
