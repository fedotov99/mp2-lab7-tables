#pragma once
#include <iostream>
using namespace std;

// class TDatValue;
// typedef TDatValue * PTDatValue;
typedef string * PTDatValue; // because we need operator<<
typedef string TDatValue; // because we need operator<<

/*
class TDatValue {  //������, ����������� ����������� ����� ��������-�������� ������
  public:
    virtual TDatValue * GetCopy() =0; // �������� �����
   ~TDatValue() {}
};
*/