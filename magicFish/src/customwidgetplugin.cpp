#include "customwidgetplugin.h"
#include "magicpool.h"

CustomWidgetPlugin::CustomWidgetPlugin(QObject *parent) :
    QObject(parent),
    initialized(false)
{

}

bool CustomWidgetPlugin::isContainer() const
{
    return false;
}

bool CustomWidgetPlugin::isInitialized() const
{
    return initialized;
}

QIcon CustomWidgetPlugin::icon() const
{
    return QIcon();
}

QString CustomWidgetPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"MagicFish\" name=\"magicPool\">\n"
//! [11]
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
//! [11]
           "  <property name=\"toolTip\" >\n"
           "   <string>A fish.</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>A fish that draw with QQuickPaintedItem.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QString CustomWidgetPlugin::group() const
{
    return "Custom Widgets";
}

QString CustomWidgetPlugin::includeFile() const
{
    return "magicpool.h";
}

QString CustomWidgetPlugin::name() const
{
    return "MagicFish";
}

QString CustomWidgetPlugin::toolTip() const
{
    return "";
}

QString CustomWidgetPlugin::whatsThis() const
{
    return "";
}

QWidget *CustomWidgetPlugin::createWidget(QWidget *parent)
{
    return new MagicPool(parent);
}

void CustomWidgetPlugin::initialize(QDesignerFormEditorInterface *)
{
    if(initialized){
        return;
    }
    initialized = true;
}
