
#include "DatList.h"

TDatList::TDatList()
{
    pFirst = pLast = pStop = NULL; 
    ListLen = 0;
    Reset();
}

PTDatLink TDatList::GetLink (PTDatValue pVal, PTDatLink pLink)
{
    PTDatLink temp = new TDatLink (pVal, pLink); // ��������� �����
    if (temp == NULL)
        SetRetCode(ListNoMem);
    else
        SetRetCode(ListOK);
    return temp;
}

void TDatList::DelLink (PTDatLink pLink)
{
    if (pLink != NULL)
    {
        if (pLink->pValue != NULL)
            delete pLink;
    }
    SetRetCode(ListOK);
}

PTDatValue TDatList::GetDatValue (TLinkPos mode) const 
{
    PTDatLink temp;
    switch (mode)
    {
        case FIRST: temp = pFirst; break;
        case LAST: temp = pLast; break;
        default: temp = pCurrLink; break;
    }
    return (temp == NULL) ? NULL : temp -> pValue;
}

int TDatList::SetCurrentPos (int pos) // ���������� ������� �����
{
    Reset();
    for (int i = 0; i < pos; i++)
        GoNext();
    SetRetCode(ListOK);
    return RetCode;
}

// ������ ���������

int TDatList::GetCurrentPos (void) const // �������� ����� �������� �����
{
    return CurrPos;
}

int TDatList::Reset (void) // ���������� �� ������ ������
{
    pPrevLink = pStop; 
    if (IsEmpty())
    {
        pCurrLink = pStop;
        CurrPos = -1; 
        SetRetCode(ListEmpty);
    }
    else
    {
        pCurrLink = pFirst;
        CurrPos = 0;
        SetRetCode(ListOK);
    }
    return RetCode;
}

int TDatList::GoNext(void) // ����� ������ �������� �����   // � ������� 1 ��� ������ ���������� �����?
{
    if (pCurrLink == pStop)
        SetRetCode(ListNoPos);
    else
    {
        SetRetCode(ListOK);
        pPrevLink = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink();
        CurrPos++;
    }
    return RetCode;
}

int TDatList::IsListEnded (void) const // =1 ����� ���������� GoNext ��� ���������� ����� ������
{
    return pCurrLink == pStop;
}

// ������ ������� �������

void TDatList::InsFirst (PTDatValue pVal) // ����� ������
{
    PTDatLink temp = GetLink(pVal, pFirst);
    if (temp == NULL)
        SetRetCode(ListNoMem);
    else   
        {
            pFirst = temp;
            ListLen++;
            // �������� ������� ������ ����� ��������
            if (ListLen == 1)
            {
                pLast = temp;
                Reset();
            }
            // ������������� ������� ������� - ������� ��������� ��� ������ ������
            else if (CurrPos == 0)
                pCurrLink = temp; 
            else 
                CurrPos++;
            SetRetCode(ListOK);
        }
}

void TDatList::InsLast (PTDatValue pVal) // �������� ���������
{
    PTDatLink temp = GetLink(pVal, pStop);
    if (temp == NULL)
        SetRetCode(ListNoMem);
    else
    {
        if (pLast != NULL)
            pLast->SetNextLink(temp);
        pLast = temp;
        ListLen++;
        // �������� ������� ������ ����� �������� 
        if (ListLen == 1)
        {
            pFirst = temp;
            Reset();
        }
        // ������������� ������� ������� - ������� ��� pCurrLink �� ������ ������
        if (IsListEnded())
            pCurrLink = temp;
        SetRetCode(ListOK);
    }
}

void TDatList::InsCurrent (PTDatValue pVal ) // �������� ����� �������
{
    if (IsEmpty() || (pCurrLink == pFirst))
        InsFirst(pVal);
    else if (IsListEnded())
        InsLast(pVal);
    else if (pPrevLink == pStop)
        SetRetCode(ListNoPos);
    else
    {
        PTDatLink temp = GetLink(pVal, pCurrLink);
        if (temp == NULL)
            SetRetCode(ListNoMem);
        else
        {
            pCurrLink = temp;
            pPrevLink->SetNextLink(temp);
            ListLen++;
            SetRetCode(ListOK);
        }
    }
}

// ������ �������� �������

void TDatList::DelFirst (void)
{
    if (IsEmpty())
        SetRetCode(ListEmpty);
    else
    {
        PTDatLink temp = pFirst;
        pFirst = pFirst->GetNextDatLink();
        DelLink(temp);
        ListLen--;
        if (IsEmpty())
        {
            pLast = pStop;
            Reset();
        }
        // ������������� ������� ������� - ������� ��������� ��� ������ ������
        else if (CurrPos == 0)
            pCurrLink == pFirst;
        else if (CurrPos == 1)
            pPrevLink == pStop;
        if (CurrPos > 0)
            CurrPos--;
        SetRetCode(ListOK);
    }
}

void TDatList::DelCurrent (void)
{
    if (pCurrLink == pStop)
        SetRetCode(ListNoPos);
    else if (pCurrLink == pFirst)
        DelFirst();
    else
    {
        PTDatLink temp = pCurrLink;
        pCurrLink = pCurrLink->GetNextDatLink(); // !
        pPrevLink->SetNextLink(pCurrLink);
        DelLink(temp);
        ListLen--;
        // ��������� �������� �������� ���������� �����
        if (pCurrLink == pLast)   // ??? 
        {
            pLast = pPrevLink;
            pCurrLink = pStop; // ? ������ pStop, � �� pPrevLink?
        }
        SetRetCode(ListOK);
    }
}

void TDatList::DelList (void) // ������� ���� ������ 
{
    while (! IsEmpty())
        DelFirst();
    pFirst = pLast = pPrevLink = pCurrLink = pStop;
    CurrPos = -1;
}