#include "RibbonWindow.h"
#include "ui_RibbonWindow.h"


RibbonWindow::RibbonWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::RibbonWindow)
{
    ui = new Ui::RibbonWindow();

    ui->setupUi(this);

    initMain();//初始化主页面

    initSlot();
}

RibbonWindow::~RibbonWindow()
{
    delete ui;
}

//初始化函数
void RibbonWindow::initMain()
{
    // Hide ribbon dock title bar
    ui->ribbonDockWidget->setTitleBarWidget(new QWidget());

    // Add tabs to ribbon
    ui->ribbonTabWidget->addTab(QIcon(":/main/icon/view.png"), "视图");

}

void RibbonWindow::initSlot()
{
    connect(ui->act_New, SIGNAL(triggered()), this, SLOT(on_NewProject()));
    connect(ui->act_Open, SIGNAL(triggered()), this, SLOT(on_OpenProject()));
    connect(ui->act_Exit, SIGNAL(triggered()), this, SLOT(close()));
/**/
}

void RibbonWindow::initViewPage()
{
    // 视图页控件
    QToolButton* view_Button_Stand = new QToolButton(this);
    view_Button_Stand->setIcon(QIcon(":/view/icon/select.png"));
    view_Button_Stand->setText(tr("选择"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("操作模式"), view_Button_Stand);
    connect(view_Button_Stand, SIGNAL(clicked()), this, SLOT(on_LeftButtonStandard()));

    QToolButton* view_Button_Pan = new QToolButton(this);
    view_Button_Pan->setIcon(QIcon(":/view/icon/pan.png"));
    view_Button_Pan->setText(tr("平移"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("操作模式"), view_Button_Pan);
    connect(view_Button_Pan, SIGNAL(clicked()), this, SLOT(on_LeftButtonPan()));

    QToolButton* view_Button_Rotate = new QToolButton(this);
    view_Button_Rotate->setIcon(QIcon(":/view/icon/Rotate.png"));
    view_Button_Rotate->setText(tr("旋转"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("操作模式"), view_Button_Rotate);
    connect(view_Button_Rotate, SIGNAL(clicked()), this, SLOT(on_LeftButtonRotate()));

    QToolButton* view_Button_Zoom = new QToolButton(this);
    view_Button_Zoom->setIcon(QIcon(":/view/icon/zoom.png"));
    view_Button_Zoom->setText(tr("缩放"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("操作模式"), view_Button_Zoom);
    connect(view_Button_Zoom, SIGNAL(clicked()), this, SLOT(on_LeftButtonZoom()));

    QToolButton* view_Button_ZoomWindow = new QToolButton(this);
    view_Button_ZoomWindow->setIcon(QIcon(":/view/icon/ZoomWindow.png"));
    view_Button_ZoomWindow->setText(tr("局部放大"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("操作模式"), view_Button_ZoomWindow);
    connect(view_Button_ZoomWindow, SIGNAL(clicked()), this, SLOT(on_LeftButtonZoomWindow()));

    QToolButton* view_Button_Front_view = new QToolButton(this);
    view_Button_Front_view->setIcon(QIcon(":/view/icon/front.png"));
    view_Button_Front_view->setText(tr("正视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Front_view);
    connect(view_Button_Front_view, SIGNAL(clicked()), this, SLOT(on_viewFront()));

    QToolButton* view_Button_Back_view = new QToolButton(this);
    view_Button_Back_view->setIcon(QIcon(":/view/icon/back.png"));
    view_Button_Back_view->setText(tr("后视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Back_view);
    connect(view_Button_Back_view, SIGNAL(clicked()), this, SLOT(on_viewBack()));

    QToolButton* view_Button_Left_view = new QToolButton(this);
    view_Button_Left_view->setIcon(QIcon(":/view/icon/left.png"));
    view_Button_Left_view->setText(tr("左视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Left_view);
    connect(view_Button_Left_view, SIGNAL(clicked()), this, SLOT(on_viewLeft()));

    QToolButton* view_Button_Right_view = new QToolButton(this);
    view_Button_Right_view->setIcon(QIcon(":/view/icon/right.png"));
    view_Button_Right_view->setText(tr("右视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Right_view);
    connect(view_Button_Right_view, SIGNAL(clicked()), this, SLOT(on_viewRight()));

    QToolButton* view_Button_Top_view = new QToolButton(this);
    view_Button_Top_view->setIcon(QIcon(":/view/icon/top.png"));
    view_Button_Top_view->setText(tr("俯视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Top_view);
    connect(view_Button_Top_view, SIGNAL(clicked()), this, SLOT(on_viewTop()));

    QToolButton* view_Button_Bottom_view = new QToolButton(this);
    view_Button_Bottom_view->setIcon(QIcon(":/view/icon/bottom.png"));
    view_Button_Bottom_view->setText(tr("底视图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Bottom_view);
    connect(view_Button_Bottom_view, SIGNAL(clicked()), this, SLOT(on_viewBottom()));

    QToolButton* view_Button_Axonometric_view = new QToolButton(this);
    view_Button_Axonometric_view->setIcon(QIcon(":/view/icon/Axonometric.png"));
    view_Button_Axonometric_view->setText(tr("轴测图"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("视图选择"), view_Button_Axonometric_view);
    connect(view_Button_Axonometric_view, SIGNAL(clicked()), this, SLOT(on_viewAxonometric()));

    QToolButton* view_Button_Side_view = new QToolButton(this);
    view_Button_Side_view->setIcon(QIcon(":/view/icon/side.png"));
    view_Button_Side_view->setText(tr("边框"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_Side_view);
    connect(view_Button_Side_view, SIGNAL(clicked()), this, SLOT(on_viewSide()));

    QToolButton* view_Button_Entity_view = new QToolButton(this);
    view_Button_Entity_view->setIcon(QIcon(":/view/icon/Entity.png"));
    view_Button_Entity_view->setText(tr("实体"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_Entity_view);
    connect(view_Button_Entity_view, SIGNAL(clicked()), this, SLOT(on_viewEntity()));

    QToolButton* view_Button_EntityWithSide_view = new QToolButton(this);
    view_Button_EntityWithSide_view->setIcon(QIcon(":/view/icon/EntityWithSide.png"));
    view_Button_EntityWithSide_view->setText(tr("带边实体"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_EntityWithSide_view);
    connect(view_Button_EntityWithSide_view, SIGNAL(clicked()), this, SLOT(on_viewEntityWithSide()));

    QToolButton* view_Button_Grid_view = new QToolButton(this);
    view_Button_Grid_view->setIcon(QIcon(":/view/icon/grid.png"));
    view_Button_Grid_view->setText(tr("栅格"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_Grid_view);
    connect(view_Button_EntityWithSide_view, SIGNAL(clicked()), this, SLOT(on_viewGrid()));

    QToolButton* view_Button_LightOn_view = new QToolButton(this);
    view_Button_LightOn_view->setIcon(QIcon(":/view/icon/lightOn.png"));
    view_Button_LightOn_view->setText(tr("开灯"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_LightOn_view);
    connect(view_Button_LightOn_view, SIGNAL(clicked()), this, SLOT(on_viewLightOn()));

    QToolButton* view_Button_LightOff_view = new QToolButton(this);
    view_Button_LightOff_view->setIcon(QIcon(":/view/icon/lightOff.png"));
    view_Button_LightOff_view->setText(tr("关灯"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("显示效果"), view_Button_LightOff_view);
    connect(view_Button_LightOff_view, SIGNAL(clicked()), this, SLOT(on_viewLightOff()));

    QToolButton* view_Button_OpenSTL = new QToolButton(this);
    view_Button_OpenSTL->setIcon(QIcon(":/icon/icon/open.png"));
    view_Button_OpenSTL->setText(tr("打开STL"));
    ui->ribbonTabWidget->addButton(tr("视图"), tr("打开"), view_Button_OpenSTL);
    connect(view_Button_OpenSTL, SIGNAL(clicked()), this, SLOT(on_actOpenSTLFile()));

    // Add 'Open file' button
    QToolButton* openFileButton = new QToolButton(this);
    openFileButton->setText(tr("File"));
    openFileButton->setToolTip(tr("Open file or directory"));
    openFileButton->setIcon(QIcon(":/icon/icon/open.png"));

    // Add dropdown menu to button
    openFileButton->setPopupMode(QToolButton::MenuButtonPopup);
    QMenu* menu = new QMenu("Title");
    //menu->addAction(QIcon(":/icon/icon/open.png"),
    //                "Recent directory");
    menu->addAction(QIcon(":/icon/icon/open.png"), "Recent file 1");
    menu->addAction(QIcon(":/icon/icon/open.png"), "Recent file 2");
    menu->addAction(QIcon(":/icon/icon/open.png"), "Recent file 3");
    openFileButton->setMenu(menu);

    ui->ribbonTabWidget->addButton(tr("视图"), "test", openFileButton);
}
