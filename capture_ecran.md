Spécification pour la capture écran
===========================

### Définition d'une zone d'écran

On peut  faire une capture d'écran d'un Widget, qui dispose d'une scène OpenGL, pour l'enregistrer sous forme d'une image. 

>. **Note**
>Ceci est une première approche  pour spécifier ce qu'on doit offrir au client et par la suite  l'améliorer pour qu'elle soit conforme au cahier de charge. 

### Première idée

Pour  l'application, l'utilisateur peut prendre une capture d'écran de son bureau. Ce dernier peut faire cette tâche avec les options suivantes:  
 
 - Retarder la capture d'écran, donner le temps de réorganiser le bureau.
 - Masquage de la fenêtre de l'application pendant la capture d'écran.  

En outre, l'application permet à l'utilisateur d' enregistrer sa capture d'écran s'il le souhaite.

>.**Note**
>On peut prendre une fenêtre à l'aide du id de la méthode **`grabWindow`** de la classe **[QPixmap](http://doc.qt.digia.com/qt/qpixmap.html)**

