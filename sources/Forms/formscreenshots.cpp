/*
================================================
* File:         formscreenshots.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage sceenshots capture
================================================
*/

#include "formscreenshots.h"
#include "ui_formscreenshots.h"
#include "../Items/screenshotsgraphicsitem.h"

#include<QTimer>
#include<QWindow>
#include<QDesktopWidget>
#include<QApplication>
#include<QScreen>
#include<QDebug>


// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent)
    :   BaseFormItem(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);

    // SpinBox
    ui->spinBoxDelay->setSuffix(" s");
    ui->spinBoxDelay->setMaximum(100);

    // Preview label
    ui->labelPreview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->labelPreview->setAlignment(Qt::AlignCenter);

    // Capture button
    connect(ui->pushButtonCapture, SIGNAL(clicked(bool)), this, SLOT(startCountdown()));

    // Capture button disabled by default
    ui->pushButtonAdd->setEnabled(false);

    fillDynamicStrings();
}

FormScreenshots::~FormScreenshots()
{
   delete ui;
}

// Update
// ------

void FormScreenshots::updatePreviewLabel()
{
    ui->labelPreview->setPixmap(m_screenshot.scaled(ui->labelPreview->size(),
                                                    Qt::KeepAspectRatio,
                                                    Qt::SmoothTransformation));
}

// Events
// ------

void FormScreenshots::resizeEvent(QResizeEvent* /*event*/)
{
    QSize screenshotSize = m_screenshot.size();
    screenshotSize.scale(ui->labelPreview->size(), Qt::KeepAspectRatio);

    if (m_screenshot.size() != screenshotSize && ui->labelPreview->pixmap())
    {
        updatePreviewLabel();
    }
}

// Slots
// -----

void FormScreenshots::startCountdown()
{
    // Clear the preview
    ui->labelPreview->clear();

    // Disable interactions
    ui->pushButtonAdd->setEnabled(false);
    ui->pushButtonCapture->setEnabled(false);

    // Hide window if requested
    if (ui->checkBoxHideWindow->isChecked())
        emit adjustWindowVisibility(false);

    // Start the timer
    QTimer::singleShot(ui->spinBoxDelay->value()*1000, this, &FormScreenshots::takeScreenshot);
}

void FormScreenshots::takeScreenshot()
{
    bool wholeScreen = ui->checkBoxWholeScreen->isChecked();

    emit requestScreenshot(wholeScreen);
}

void FormScreenshots::screenshotReceived(const QPixmap& screenshot)
{
    m_screenshot = screenshot;

    ui->labelPreview->setPixmap(m_screenshot.scaled(ui->labelPreview->size(),
                                                    Qt::KeepAspectRatio,
                                                    Qt::SmoothTransformation));


    // Enable interactions
    ui->pushButtonAdd->setEnabled(true);
    ui->pushButtonCapture->setEnabled(true);

    // Show if necessary
    if (ui->checkBoxHideWindow->isChecked())
        emit adjustWindowVisibility(true);
}


// Load data
// ---------

void FormScreenshots::loadFromItem(BaseGraphicItem* item) const
 {
    if (qgraphicsitem_cast<ScreenshotsGraphicsItem*>(item))
    {
        //ScreenshotsGraphicsItem* castedItem = qgraphicsitem_cast<ScreenshotsGraphicsItem*>(item);

        // Load data into the form
    }
}

// Translation
// -----------

void FormScreenshots::retranslate()
{
    ui->retranslateUi(this);
    fillDynamicStrings();
}

void FormScreenshots::fillDynamicStrings()
{
    ui->comboBoxMode->clear();
    ui->comboBoxMode->addItem(tr("Fullscreen"), CAPTURE_FULLSCREEN);
    ui->comboBoxMode->addItem(tr("Window"), CAPTURE_WINDOW);
    ui->comboBoxMode->addItem(tr("Manual"), CAPTURE_MANUAL);
}

// Getters
// -----------------

const QPixmap& FormScreenshots::getScreenshot() const
{
    return m_screenshot;
}

const QPushButton* FormScreenshots::getAddButton() const
{
    return ui->pushButtonAdd;
}



