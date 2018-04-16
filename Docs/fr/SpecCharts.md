% Graphiques 
% M2I Team
% \today

# Généralités

Les graphiques (ou diagrammes) sont des objets figurant dans l'interface graphique chargés de la représentation visuelle d'un ou plusieurs ensembles de données.

Il existe différents types de graphiques (camemberts, histogrammes, nuage de points,...) dont l'utilisation dépend du type de données et de la représentation de l'information souhaitée (à la discrétion de l'utilisateur).

# Caractéristiques

Les graphiques possèdent quelques caractéristiques et propriétés qui seront modifiables par l'utilisateur:
	
### Principales :

- Le type de graphique (Camemberts, nuages de points, diagramme à barres, lignes)
- Le set de données
- Le titre du graphique
- Le nom des axes (ainsi que les unités utilisées si existantes)
- Une échelle

### Secondaires :

- Couleur de fond
- Couleur des points / données
- Zoom in / Zoom out
- Panning / Scaling / Rotation (à l'instar d'autres composants comme les textes ou les bulles numérotées)

# En Qt

Dans la librairie Qt, il existe déjà une classe permettant de générer des graphiques: la classe **QChart**.

**Les QChart sont des QGraphicsWidget qui peuvent être affichés dans un objet QGraphicsScene.**

Chaque graphique est représenté par une classe dérivée de QAbstractSeries. Les graphiques sont alors crées en ajoutant des valeurs dans une classe série héritée puis en ajoutant cette série dans un QChart ou un QChartView. Chaque type de graphique utilise un type de série spécifique (voir doc).

Exemple de création basique:

```cpp
QLineSeries* series = new QLineSeries();
series->add(0, 6);
series->add(2, 4);
...
chartView->chart()->addSeries(series);
chartView->chart()->createDefaultAxes();
```
Il existe des accesseurs et des mutateurs pour les axes et les couleurs (thème). Des méthodes existent également pour le zoom-in / zoom-out.

Plus d'info sur les QChart [ici](https://doc.qt.io/qt-5.10/qtcharts-overview.html)

# Dans ClipEdit

### Création

On peut imaginer un bouton dans l'interface (toolbar et/ou via menu contextuel) pour insérer un graphe.

Un dialog s'ouvrirait alors pour demander à l'utilisateur de choisir un type de graphe (*combobox*) puis d'entrer les données. L'entrée des données pourrait se faire via le chargement d'un fichier ou en mode manuel, en définissant un séparateur pour le parsing.

Le dialog comprendrait également des champs (*line edit*) pour le titre du graphique et des axes. (+ l'unité éventuellement).

Boutons radio pour choisir entre une échelle manuelle auto ou une échelle manuelle.

On peut aussi imaginer des boutons pour sélectionner les couleurs à utiliser ou bien une liste déroulante proposant les thèmes déjà intégrés à Qt (ou créer un thème personnalisé et l'enregistrer).

### Post-création

Via un double-clic ou un clic droit -> Editer, ouverture d'une fenêtre d'édition identique à celle de création mais avec les champs pré-remplis.

Possibilité de déplacer, changer la taille, tourner ou supprimer les graphiques à l'instar des autres composants de ClipEdit.
