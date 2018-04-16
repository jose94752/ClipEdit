# *Clipart* Collections

## Definition

A *clipart* collection is

* One picture
* One description file which describes *cliparts*.

Its name is the name of the picture and the name of the description file, which
should be identical.


## Files

The picture is a [texture atlas](https://en.wikipedia.org/wiki/Texture_atlas), as a

* *png*
* *jpeg*

The description file is a *json* file.
One example:
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


# In the application ClipEdit

## Management and functionnalities

A *clipart* is a fixed size picture [1](#ref_1).

During the startup, the application will load all *clipart* collections.
Maybe the application can detect :

* Incomplete *clipart* collections (either the picture or the description file is missing)
* Overlaid *cliparts* inside one collection


## Integration

* A toolbox which :
    * Lists all *clipart* collections
    * Displays all *cliparts* inside the selected collection
    * Lets drag and drop one *clipart*
* A button**Reload** to update the list of *clipart* collections at runtime.


## Storage

Manage a folder which contains all *clipart* collections.
Subfolders are discarded.


# Reference

#ref_1:
[SpecPictures.md](SpecPictures.md)
