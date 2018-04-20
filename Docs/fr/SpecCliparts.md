# Bibliothèques de *clip arts*

## Définition

Une bibliothèque de *clip arts*, c'est

* Une image.
* Un fichier de descriptions des *clip arts*

Son nom c'est le nom de cette image et du nom du fichier de description qui
doivent être identiques.


## Les fichiers

L'image est une [texture atlas](https://en.wikipedia.org/wiki/Texture_atlas),
au format :

* *png*
* *jpeg*

Le fichier de descriptions est un fichier *json*.
Un exemple :
```json
  [
      {
          "name": "mouse",
          "x": 0,
          "y": 0,
          "height": 100,
          "width": 100
      }, {
          "name": "computer",
          "x": 100,
          "y": 0,
          "height": 100,
          "width": 100
      }
  ]
```


# Dans l'application ClipEdit

## Gestion et fonctionnalités

Un clip art est une image [1](#ref-1) avec une taille fixe.

C'est au démarrage que l'application chargera toutes les bibliothèques de
*clip arts*. Peut-être que l'application peut détecter :

* Les bibliothèques incomplètes (manquement de l'image ou du fichier de descriptions)
* Des *clip arts* qui se supersposent dans une même bibliothèque.


## Intégration

* Une boite à outils qui :
    * Liste toutes les bibliothèques
    * Affiche toutes les *clip arts* de la collection sélectionnée
    * Permet de déposer/ glisser un *clip art*
* Un bouton **Recharger** pour mettre à jour la liste des bibliothèques de
*clip arts* pendant l'exécution.


## Stockage

Gérer un dossier qui va contenir toutes les bibliothèques de *clip arts*.
Les sous-dossiers sont ignorés.


# Référence

# ref-1
[SpecPictures.md](SpecPictures.md)
