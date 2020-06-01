/*--------------------------------------------------------------------------

	Win1.h - 用户定义的窗口1类的头文件

	本程序是FishGUI软件的一部分

	版权所有 (C) 2003,2004 王咏武
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	作者对 FishGUI 软件及其所有源代码授权如下：

	允许任何个人、组织、机构、企业无偿获得、修改、使用、重新发布 FishGUI 软
	件及其源代码，或按照有偿或者无偿的方式发行基于 FishGUI 源代码的全部或部
	分内容开发的软件产品，——但行使以上权利时，须遵守以下约定：

	1、重新发布 FishGUI 软件及其源代码时，不得隐去软件及其源代码中原有的版
	   权信息和开发者标识。

	2、发行基于 FishGUI 源代码的全部或部分内容开发的软件产品时，必须在产品
	   的显著位置标明以下字样：

	   【本产品的一部分功能是基于王咏武在 FishGUI 软件中的工作完成的】

	3、在正式出版物中引用 FishGUI 的文档、源代码或注释内容的，应注明软件的
	   原作者为王咏武。

--------------------------------------------------------------------------*/
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的窗口1类的头文件
 */

#ifndef WIN1_H_HEADER_INCLUDED_C0A87F67
#define WIN1_H_HEADER_INCLUDED_C0A87F67

#include "../../Source/Framework/FG_Framework.h"
#include "MyModel.h"

/*! \brief 用户定义的窗口1类
 */
class Win1 : public FG_Window
{
public:
    /*! \brief 窗口1上的控件ID
     */
    enum
    {
        ID_DISPLAY1 = 1,
        ID_DISPLAY2,
        ID_CHECK1,
        ID_CHECK2,
        ID_BUTTON
    };

    /*! \brief 窗口1的构造函数
     *  
     *  创建所有的控件，注册快捷键
     *  \param wID 窗口1的唯一标识，缺省为0
     */
    Win1(WORD wID = 0);

protected:
    /*! \brief 窗口1上的定时器ID
     */
    enum
    { 
        ID_TIMER = 1
    };

    /*! \brief 通知消息的处理函数 */
    void OnCheck1Checked(void) { m_bData1 = true; }

    /*! \brief 通知消息的处理函数 */
    void OnCheck2Checked(void) { m_bData2 = true; }

    /*! \brief 通知消息的处理函数 */
    void OnCheck1Unchecked(void) { m_bData1 = false; }

    /*! \brief 通知消息的处理函数 */
    void OnCheck2Unchecked(void) { m_bData2 = false; }

    /*! \brief 通知消息的处理函数 */
    void OnButtonPressed(void) { GetMyModel()->AdjustData(); }

    /*! \brief 定时器消息的处理函数 */
    void OnTimer(void);

    /*! \brief 视图通知消息的处理函数 */
    void OnViewUpdate(void);

private:
    bool m_bData1;      /*!< \brief 是否需要发送数据1 */
    bool m_bData2;      /*!< \brief 是否需要发送数据2 */

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN1_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

