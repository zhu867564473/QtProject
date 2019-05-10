#ifndef CUSTOMWIDGETPLUGIN_H
#define CUSTOMWIDGETPLUGIN_H

#include <QtUiPlugin/QDesignerCustomWidgetCollectionInterface>

class CustomWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
    Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit CustomWidgetPlugin(QObject *parent = nullptr);

    /**
     * @brief Returns true if the custom widget is intended to be used as a container; otherwise \
     * returns false.Most custom widgets are not used to hold other widgets, so their implementations \
     * of this function will return false,but custom containers will return true to ensure that they \
     * behave correctly in Qt Designer.
     */
    bool isContainer() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns true if the widget has been initialized; otherwise returns false.
     */
    bool isInitialized() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns the icon used to represent the custom widget in Qt Designer's widget box.
     */
    QIcon icon() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns the XML that is used to describe the custom widget's properties to Qt Designer.
     */
    QString domXml() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns the name of the group to which the custom widget belongs.
     */
    QString group() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns the path to the include file that uic uses when creating code for the custom widget.
     */
    QString includeFile() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns the class name of the custom widget supplied by the interface.\
     * The name returned must be identical to the class name used for the custom widget.
     */
    QString name() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns a short description of the widget that can be used by Qt Designer in a tool tip.
     */
    QString toolTip() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns a description of the widget that can be used by Qt Designer in "What's This?" help for the widget.
     */
    QString whatsThis() const Q_DECL_OVERRIDE;

    /**
     * @brief Returns a new instance of the custom widget, with the given parent.
     */
    QWidget *createWidget(QWidget *parent) Q_DECL_OVERRIDE;

    /**
     * @brief Initializes the widget for use with the specified formEditor interface.
     */
    void initialize(QDesignerFormEditorInterface *core) Q_DECL_OVERRIDE;

private:
    bool initialized;
};

#endif // CUSTOMWIDGETPLUGIN_H
