#pragma once
#include "TTable.h"
#include "TTreeNode.h"
#include <stack>

class  TTreeTable: public TTable {
  protected: 
    PTTreeNode pRoot; // ��������� �� ������ ������
    PTTreeNode *ppRef;// ����� ��������� �� �������-���������� � FindRecord
    PTTreeNode pCurrent;// ��������� �� ������� �������
    int CurrPos;        // ����� ������� �������
    stack <PTTreeNode> St;// ���� ��� ���������
    void DeleteTreeTab (PTTreeNode pNode); // ��������
  public:
    TTreeTable(): TTable(){CurrPos=0; pRoot=pCurrent=NULL; ppRef=NULL;}   
    ~TTreeTable(){DeleteTreeTab (pRoot);} // ����������
    // �������������� ������
    virtual int IsFull() const ; //���������?
    //�������� ������
    virtual PTDatValue FindRecord (TKey k); // ����� ������
    virtual void InsRecord (TKey k, PTDatValue pVal ); // ��������
    virtual void DelRecord (TKey k);       // ������� ������
    // ���������
    virtual TKey GetKey (void) const;
    virtual PTDatValue GetValuePTR (void) const;
    virtual int Reset (void);  // ���������� �� ������ ������
    virtual int IsTabEnded (void) const; // ������� ���������?
    virtual int GoNext (void) ;// ������� � ��������� ������
    //(=1 ����� ���������� ��� ��������� ������ �������)
};