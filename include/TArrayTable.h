#pragma once
#include "TTable.h"
#define TabMaxSize 25
enum TDataPos {FIRST_POS, CURRENT_POS, LAST_POS};

class  TArrayTable : public TTable {
  protected:
    PTTabRecord *pRecs; // ������ ��� ������� �������
    int TabSize;        // ����. ����.���������� ������� � �������
    int CurrPos;        // ����� ������� ������ (��������� � 0)
  public:
    TArrayTable(int Size=TabMaxSize); // �����������
    ~TArrayTable();                // ����������
    // �������������� ������
    virtual int IsFull() const {
        return DataCount >= TabSize;
    }; // ���������?
    int GetTabSize() const {
        return TabSize;
    };      // �-�� �������
    // ������
    virtual TKey GetKey(void)const { 
        return GetKey(CURRENT_POS); };
    virtual PTDatValue GetValuePTR(void)const {
        return GetValuePTR(CURRENT_POS);
    };
    virtual TKey GetKey(TDataPos mode)const;
    virtual PTDatValue GetValuePTR(TDataPos mode)const;
    // �������� ������
    virtual PTDatValue FindRecord (TKey k) =0; // ����� ������
    virtual void InsRecord (TKey k, PTDatValue pVal ) =0; // ��������
    virtual void DelRecord (TKey k) =0;        // ������� ������
    //���������
    virtual int Reset (void);   // ���������� �� ������ ������
    virtual int IsTabEnded(void)const {
        return CurrPos >= DataCount;
    }; // ������� ���������?
    virtual int GoNext (void) ; // ������� � ��������� ������
    // (=1 ����� ���������� ��� ��������� ������ �������)
    virtual int SetCurrentPos (int pos); // ���������� ������� ������
    int GetCurrentPos(void)const {
        return CurrPos;
    };     //�������� ����� ������� ������
  friend class TSortTable;
};