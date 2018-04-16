# Collections clipart

## Définition

Une collection clipart, c'est

* une [texture atlas](https://en.wikipedia.org/wiki/Texture_atlas).
* un fichier de descriptions des images

Son nom c'est le nom de cette image et du nom du fichier de description qui
doivent être identiques.


## Les fichiers

Les formats gérés pour l'image sont :

* *png*
* *jpeg*

Le fichier de description est un fichier *json*.
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


# L'application

## Gestion et fonctionnalités

Dans l'application, un clipart est une <cite>[image][1]</cite> avec une taille
fixe.

C'est au démarrage que l'application va charger toutes les collections clipart.
Ainsi, peut-être que l'application peut détecter :

* les collections incomplètes (manquement de l'image ou du fichier de descriptions)
* des images qui se supersposent dans une même collection.


## Intégration 

* Une boite outil qui :
    * liste toutes les collections
    * affiche toutes les images de la collection sélectionnée
    * permet de déposer/ glisser une image
* Un bouton **Recharger** pour mettre à jour la liste des collections clipart
pendant l'exécution.


## Stockage

Gérer un dossier qui va contenir toutes les collections clipart.
Les sous-dossiers sont ignorés.


[1]: voire images_XX.md

