##Résumé.

The goal is to save, read user projects and exports them in an image.

##Common elements

We have a menu with 3 enters.

-One enter to save projects.

-One enter to read projects.

-One enter to export an image.

These 3 enters open a dialog box to choise a folder and a file name for writtind and reading.

##Save

L'enregistrement permet de stocker dans un fichier l'ensemble des données enregistrées par l'utilisateur pour un projet à savoir
Saving autorize to store in a file all the user data for a project. It's

-The layers list(bubble, clipart).

-It's position in a rectangle for a layer.

-The beginning and the ending position for eadges.

-The specifics properties of each element.

-The layers dependancies, with parent and childrn layers data.

##implemented methods
Graphics Item must implements 2 methods getParameters and setParameters

##The getter
void getParameters(QSettings *settings,QString itemName) which gets the list of the items properties before saving.
settings is a pointeur to the settings list object
name is the name of your item given by the save method

Each parameter is stored in the follow form 
settings->setValue(itemName/parameterName,QVariant);


#The Setter
void setParameters(QSettings *settings,QString itemName) which initialise item with settings properties
settings is a pointeur to the settings list object
name is the name of your item given by the save method

Each parameter is got by the method
QVariant variantVar=settings->value(itemName/parameterName);
MyType var=variantVar.toMyType();
