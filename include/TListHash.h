#pragma once
#include "DatList.h"
#include "THashTable.h"

#define TabMaxSize 25
class  TListHash : public THashTable {
  protected:
    PTDatList *pList; // ������ ��� ������� ���������� �� ������ ������� 
    int TabSize;      // ������ ������� ����������
    int CurrList;     // ������, � ������� ���������� �����
  public:
    TListHash(int Size= TabMaxSize); // �����������
    ~TListHash();
    // �������������� ������
    virtual int IsFull ( ) const ; // ���������?
    // ������
    virtual TKey GetKey (void) const;
    virtual PTDatValue GetValuePTR (void) const;
    // �������� ������
    virtual PTDatValue FindRecord (TKey k); // ����� ������
    virtual void InsRecord (TKey k, PTDatValue pVal ); // ��������
    virtual void DelRecord (TKey k);        // ������� ������
    // ���������
    virtual int Reset (void);   // ���������� �� ������ ������
    virtual int IsTabEnded (void) const; // ������� ���������?
    virtual int GoNext (void) ; // ������� � ��������� ������
    //(=1 ����� ���������� ��� ��������� ������ �������)
};