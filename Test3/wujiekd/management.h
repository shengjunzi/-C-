#pragma once

#include"kedaadd.h"
#include"kedachange.h"
#include"kedadelete.h"
#include"kedasave.h"
#include"kedaimport.h"
#include"kedafinds.h"
#include"point.h"
#include"Student.h"
using namespace std;
// management 对话框

class management : public CDialogEx
{
	DECLARE_DYNAMIC(management)

public:
	management(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~management();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = menu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list;
	CEdit m_edit;
	_ConnectionPtr m_pConnection = NULL;
	//初始化Recordset指针
	_RecordsetPtr pRecordset;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnKillfocusEdit2();
	virtual void OnOK();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

	afx_msg void OnCustomdrawList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickList2(NMHDR *pNMHDR, LRESULT *pResult);


//——————————————————————————以下函数和变量为自己添加！——————————————————————————————————

private:
	kedaadd  adds;                         //其他功能操作的类，每个按钮对应一个子窗口         
	kedachange changes;
	kedadelete deletes;
	kedasave saves;
	kedaimport imports;
	kedafinds finds;

	
public:
	UINT m_line;                 //计算列表框的行数
	UINT m_index;                //用于计算循环的变量
	UINT m_indexmax;             //列数，就是8
	BOOL judge;
	BOOL check;
	CString filename;
	UINT m_stusum;
	UINT m_Row;
	UINT m_Col;

	BOOL nodata();               //添加函数
	BOOL empty();
	BOOL checkgrade();
	BOOL checknumber();
	

	void deletenull();           //删除函数
	void delete_q();

	void find_q();               //查找函数
	void reset(UINT a);

	void importtt();             //导入函数
	UINT  importt(CString s);

	void findcheck();            //修改函数
	void settext(int line);
	BOOL checknum();
	void changename();
	
	void resort(UINT x);               //排序函数
	

	
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cbx;
};
