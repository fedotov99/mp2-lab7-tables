#pragma once
#include "DatValue.h"
#include <iostream>
#include <string>
using namespace std;

typedef string TKey;     // ��� ����� ������
// ����� ��������-�������� ��� ������� �������
class TTabRecord : public TDatValue {  protected:    // ����    
    TKey Key;   // ���� ������
    PTDatValue pValue;   // ��������� �� ��������
  public:  // ������
    TTabRecord(TKey k = "", PTDatValue pVal = NULL); // ����������� 
    void SetKey(TKey k) {
        Key = k;
    }; // ���������� �������� �����
    TKey GetKey(void) {
        return Key;
    };  // �������� �������� �����
    void SetValuePtr(PTDatValue p) { 
        pValue = p;
    }; // ���������� ��������� �� ������
    PTDatValue GetValuePTR(void) {
        return pValue;
    }; // �������� ��������� �� ������
    virtual TDatValue * GetCopy(); // ���������� �����
    TTabRecord & operator= (TTabRecord &tr); // ������������
    virtual int operator== (const TTabRecord &tr); // ��������� =
    virtual int operator< (const TTabRecord &tr);  // ��������� �<�
    virtual int operator> (const TTabRecord &tr);  // ��������� �>�
protected:
    virtual void Print(ostream& os);
  //������������� ������ ��� ��������� ����� ������, ��. �����
  friend class TArrayTable;
  friend class TScanTable;
  friend class TSortTable;
  friend class TTreeNode;
  friend class TTreeTable;
  friend class TArrayHash;
  friend class TListHash;
};

typedef TTabRecord * PTTabRecord;