#pragma once
#include "TTreeTable.h"
#include "TBalanceNode.h"
#define HeightOK 0
#define HeightInc 1

class  TBalanceTree: public TTreeTable  {
    protected: 
int InsBalanceTree(PTTreeNode &pNode, TKey k, PTDatValue pVal);
int LeftTreeBalancing(PTTreeNode &pNode); // ������. ������ ���������
int RightTreeBalancing(PTTreeNode &pNode);// ������. ������� ���������
  public:
    TBalanceTree():TTreeTable(){} // �����������
    //�������� ������
    virtual void InsRecord (TKey k, PTDatValue pVal ); // ��������
    // virtual void DelRecord (TKey k);                   // �������
};