#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Card {
    int nominal;
    int mast;
    Card() {};
    Card (int a, int b): nominal(a), mast(b) {};
    friend ostream& operator << (ostream& outputStream,Card c)
    {
        return outputStream << to_string(c.nominal) + " " +
               to_string(c.mast);
    }
};
int main()
{
    string str_nom {"234567891VDKT"};//1-��� 10
    string str_mast {"#^-+"};
    int p,kol,n;
    do {
        cout <<"������� ������: 1- 36 ����, 2- 52 �����, 0-�����" << endl;
        cin >> p;
        if (!((p == 1) || (p == 2))) {}
        else if (p >0) {
            if (p == 1) {
                kol=36;
                n=4;
            } else {
                kol=52;
                n=0;
            }
            cout << endl << "�������� ������ �� " << kol << " ����" << endl;
            if (p == 2) cout << "2,3,4,5,";
            cout << "6,7,8,9,10,V-�����,D-����,�-������,T-���" << endl;
            cout << "#-������,^-�����,--����,+-����" << endl << endl;
            vector <Card> koloda;
            for (int j=0; j<4; j++) {
                for (int i=n; i<13; i++) {
                    koloda.push_back(Card(i, j));
                }
            }
            for (int i=0; i<kol; i++)
                cout << i+1 << " �����:= " << str_nom[koloda[i].nominal]<<(char) str_mast[koloda[i].mast] << endl;
            cout << endl << "������� ������ ���� ��:"<< endl;
            srand(time(NULL));
            random_shuffle(koloda.begin(),koloda.end());
            for (int i=0; i<kol; i++)
                cout<<i+1 <<"�����:= " << str_nom[koloda[i].nominal] << str_mast[koloda[i].mast]<<endl;
            cout << endl;
            cout << "����� ������ �����,������� �����:" << endl;
            for (int i=0; i<kol-1; i++) {
                if (str_mast[koloda[i].mast] ==
                    str_mast[koloda[i+1].mast])
                    cout <<i+1 <<"�����:= " << str_nom[koloda[i].nominal] << str_mast[koloda[i].mast]<<" "<<i+2 <<"�����:= " << str_nom[koloda[i+1].nominal]<<str_mast[koloda[i+1].mast]<< endl;
            }
            cout <<endl<< "����� ������ ��������,������� �����: " << endl;
            for (int i=0; i<kol-1; i++) {
                if (str_nom[koloda[i].nominal] ==
                    str_nom[koloda[i+1].nominal])
                    cout<<i+1 <<"�����:= " << str_nom[koloda[i].nominal]<< str_mast[koloda[i].mast]<<" "<<i+2 <<"�����:= " << str_nom[koloda[i+1].nominal]<<str_mast[koloda[i+1].mast]<< endl;
            }
            int i=0;
            cout << endl<<"������� ����:= ";
            while (!((str_mast[koloda[i].mast] == str_mast[2]) &&
                     (str_nom[koloda[i].nominal] == str_nom[10]))) {
                i=i+1;
            }
            cout << i+1 << "-� � ������"<< endl;
            cout << "���� � ������: "<<endl;
            for (int i=0; i<=kol; i++) {
                if (str_nom[koloda[i].nominal] == str_nom[12])
                    cout<<i+1 <<" �����"<< endl;
            }
        }
    } while (p!=0);
    return 0;
}