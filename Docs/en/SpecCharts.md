% Charts 
% M2I Team
% \today

# Brief

Charts (or diagrams) are graphic objects part of the user interface. They are in charge of the visual representation of one or several data sets.

There are different types of charts (pies, histograms, scattered points,...) whose use depends on the type of data the user wants to represent.

# Features

Charts have several features and properties that are editable by the user:
	
### Main features :

- Chart type (Pies, scattered points, bars, lines)
- Data set
- Chart title
- Axis labels (units included)
- Scale

### Secondary features :

- Background color
- Data / dot colors
- Zoom in / Zoom out
- Panning / Scaling / Rotation (like other graphic widgets in ClipEdit)

# In Qt

Qt already implements a class to create, manage and manipulate charts :  **QChart**.

**QChart is a QGraphicsWidget that you can show in a QGraphicsScene.**

Each chart type is represented by an QAbstractSeries derived class or AbstractSeries derived type in QML. Charts are created by using an instance of a series class and adding it to a QChart or ChartView instance.

Basic creation example:

```cpp
QLineSeries* series = new QLineSeries();
series->add(0, 6);
series->add(2, 4);
...
chartView->chart()->addSeries(series);
chartView->chart()->createDefaultAxes();
```
There are getters and setters for axis and colors (theme). In addition to that, several methods exist to manipulate the zoom level.

More info about QChart [here](https://doc.qt.io/qt-5.10/qtcharts-overview.html)

# In ClipEdit

### Creation

The user can insert a new chart by clicking the button in the UI (toolbar of via the context menu).

A dialog will then pop to prompt the user to select the chart type (*combobox*), then to enter data. To achieve that, the user can choose to import a file or manually enter it (separator needed). 

The dialog includes a text field (*line edit*) for the chart title and the axis (+ units).

Two radio buttons to select the entry mode for data (import or manual)

We could also have buttons to set both background and data colors.

### Post-creation

Via a doubleclick or a right click -> Edit, open a dialog similar to the creation one with pre-filled fields.

Once created, you can also move, change the size, rotate or delete other components like other graphic widgets in ClipEdit.
